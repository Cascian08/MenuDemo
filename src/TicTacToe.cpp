#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "../headers/games.h"

using namespace std;

//Checks for zeros in the table
bool GamesLibrary::Games::checkForZero(int (*table)[3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(table[i][j] == 0){
                return true;
            }
        }
    }
    return false;
}

//Checks for an eventual win
int GamesLibrary::Games::checkForWin(int (*table)[3]){
    for(int i = 0; i < 3; i++){
        if(table[i][0] != 0 && table[i][0] == table[i][1] && table[i][1] == table[i][2]){
            return table[i][0];
        }
    }

    for(int i = 0; i < 3; i++){
        if(table[0][i] != 0 && table[0][i] == table[1][i] && table[1][i] == table[2][i]){
            return table[0][i];
        }
    }

    if(table[0][0] != 0 && table[0][0] == table[1][1] && table[1][1] == table[2][2]){
        return table[0][0];
    }
        
    if(table[2][0] != 0 && table[2][0] == table[1][1] && table[1][1] == table[0][2]){
        return table[2][0];
    }

    return 0;
}
//Looks for the best computer move by using the minimax algorithm.
int GamesLibrary::Games::minimax(int (&table)[3][3], int depth, bool isMax, int maxDepth){
    int winner = checkForWin(table);
    //Assigns values based on the final state of the game.
    if(winner == 1){
        return -10; //if the real player wins, the score = -10.
    }

    if(winner == 2){
        return 10; //if the computer wins, the score = +10.
    }

    //If there are no more moves left or the maximum depth is reached, the game is a draw(score = 0).
    if(checkForZero(table) == false || depth == maxDepth){
        return 0;
    }
    //If it's the computer's turn, the function tries to maximize the score.
    if(isMax){
        int bestScore = numeric_limits<int>::min();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(table[i][j] == 0){
                    table[i][j] = 2; 
                    int score = minimax(table, depth+1, false, maxDepth);
                    table[i][j] = 0; 
                    bestScore = max(score,bestScore);
                }
            }
        }
        return bestScore;
    }else{//If it's the real player's turn, the function tries to minimize the score.
        int bestScore = numeric_limits<int>::max();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(table[i][j] == 0){
                    table[i][j] = 1; 
                    int score = minimax(table, depth+1, true, maxDepth);
                    table[i][j] = 0;
                    bestScore = min(score,bestScore);
                } 
            }
        }
        return bestScore;
    }
}

//Manages moves for both computer & real player.
void GamesLibrary::Games::move(int (&table)[3][3], bool player, int difficulty){
    int x,y;

    if(player){//Real player's turn.
        do {
            cout << "\nIt's your turn!\n" << ">>> ";
            while(!(cin >> x) || x < 1 || x > 3){
                cout << "Error! Please insert a valid option!\n" << ">>> ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << ">>> ";
            while(!(cin >> y) || y < 1 || y > 3){
                cout << "Error! Please insert a valid coordinate!\n" << ">>> ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "\n";

        }while(table[x-1][y-1] != 0);

        table[x-1][y-1] = 1;

    }else{//Computer's turn.
        cout << "\nIt's opponent's turn!\n";
        if(difficulty == 1){

            vector<pair<int,int>> valid_moves;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(table[i][j] == 0){
                        valid_moves.push_back(make_pair(i,j));
                    }
                }
            }
            
            pair<int,int> random_move = valid_moves[rand() % valid_moves.size()];
            table[random_move.first][random_move.second] = 2;
            cout << "\nOpponent placed 'O' in: " << random_move.first+1 << "," << random_move.second+1 << "\n\n";

        }else if(difficulty == 2){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(table[i][j] == 0){
                        table[i][j] = 1;
                        int result = checkForWin(table);
                        if(result == 1 && rand()%2 == 0){
                            table[i][j] = 2;
                            cout << "\nOpponent placed 'O' in: " << i+1 << "," << j+1 << "\n\n";
                            return;
                        }
                        table[i][j] = 0;
                    }
                }
            }

            vector<pair<int,int>> valid_moves;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(table[i][j] == 0){
                        valid_moves.push_back(make_pair(i,j));
                    }
                }
            }
            pair<int,int> random_move = valid_moves[rand() % valid_moves.size()];
            table[random_move.first][random_move.second] = 2;
            cout << "\nOpponent placed 'O' in: " << random_move.first+1 << "," << random_move.second+1 << "\n\n";

        }else{
            int bestScore = numeric_limits<int>::min();
            pair<int,int> move;
            int score;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(table[i][j] == 0){
                        table[i][j] = 2;
                        if(difficulty == 3){
                            score = minimax(table, 0, false, 2);
                        }else{
                            score = minimax(table, 0, false, -1); 
                        }
                        table[i][j] = 0;

                        if(score > bestScore){
                            bestScore = score;
                            move = {i,j};
                        }
                    }
                }
            }
        table[move.first][move.second] = 2;
        cout << "\nOpponent placed 'O' in: " << move.first+1 << "," << move.first+1 << "\n\n";
        }
    }
}

//Draws the game table.
void GamesLibrary::Games::drawTable(int (*table)[3]){
    string tableToDraw[3][3];
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(table[i][j] == 1){
                tableToDraw[i][j] = "X";
            }else if(table[i][j] == 2){
                tableToDraw[i][j] = "O";
            }else{
                tableToDraw[i][j] = " ";
            }
        }
    }
        
        
    for(int i = 0; i < 3; i++){
        cout << " " << tableToDraw[i][0] << "|"<< tableToDraw[i][1] << "|" << tableToDraw[i][2] << "\n";
        if(i < 2){
            cout << "-------\n";
        }
    }
}
//Main game function.
void GamesLibrary::Games::TicTacToe(){
    int table[3][3] = {{0,0,0},
                       {0,0,0},
                       {0,0,0}};

    bool player;
    int difficulty;
    
    //Selects a random player(real player or computer.
    player = (rand()%2==1) ? true : false;

    //Gets the computer difficulty
    cout << "Please select a difficulty between: Easy(1), Medium(2), Hard(3), Unbeatable(4)\n" << ">>> ";
    while(!(cin >> difficulty) || difficulty < 1 || difficulty > 4){
        cout << "Please select a valid difficulty!\n" << ">>> ";
    }

    //The game continues until there are free spots and there's no win.
    while(checkForZero(table) && checkForWin(table) == 0){
        move(table, player, difficulty);
        drawTable(table);
        player = !player;
    }
    
    int result = checkForWin(table);

    //Displays final state of the game. 
    if(result == 0){
        cout << "\nDraw!\n";
    }else if(result == 1){ 
        cout << "\nYou Win!!\n";
    }else{
        cout << "\nYou lose...\n";
    }

    //Asks to restart the game.
    char c;
    cout << "\nRestart?(Y/n)\n" << ">>> ";

    while(!(cin >> c) ||  (tolower(c)!= 'y' && tolower(c) != 'n')){
        cout << "\nPlese select a valid option!\n";
        cout << ">>> ";
    }

    c = tolower(c);

    if(c == 'y'){
        TicTacToe();
    }
    
    if(c == 'n'){
        cout << "\nClosing the game...\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}