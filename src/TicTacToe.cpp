#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "../headers/games.h"

using namespace std;

auto GamesLibrary::Games::checkForZero(auto table, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(table[i][j] == 0){
                return true;
            }
        }
    }
    return false;
}


auto GamesLibrary::Games::checkForWin(auto table, int rows, int cols){
    for(int i = 0; i < rows; i++){
        if(table[i][0] != 0 && table[i][0] == table[i][1] && table[i][1] == table[i][2]){
            return table[i][0];
        }
    }

    for(int i = 0; i < cols; i++){
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

auto GamesLibrary::Games::minimax(auto& table, int rows, int cols, int depth, bool isMaxingPlayer, int alpha, int beta){
    int result = checkForWin(table,3,3);

    if(result != 0){
        return result;
    }
    
    if(!checkForZero(table,3,3)){
        return 0;
    }

    int bestScore = -9999;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(table[i][j] == 0){
                table[i][j] = 2;
                int score = minimax(table, rows, cols, depth+1, false, alpha, beta);
                table[i][j] = 0;

                bestScore = max(score, bestScore);
                alpha = max(alpha, score);

                if(beta <= alpha){
                    break;
                }
            }
        }
    }
    return bestScore;
}

auto GamesLibrary::Games::move(auto& table, int rows, int cols, int player){
    int x,y;
    
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> rangeXY(1,2);

    if(player == 1){
        do {
            cout << "\nIt's your turn!\n" << ">>> ";
            while(!(cin >> x) || x < 1 || x > 3){
                cout << "Error! Please insert a valid coordinate!\n" << ">>> ";
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

    }else{

        cout << "\nIt's opponent turn!\n";
        int bestScore = -9999;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(table[i][j] == 0){
                    table[i][j] = 2;
                    int score = minimax(table, rows, cols, 0, false, -9999, 9999);
                    table[i][j] = 0;

                    if(score > bestScore){
                        bestScore = score;
                        x = i;
                        y = j;
                    }
                }
            }
        }

        table[x][y] = 2;

        cout << "\nOpponent placed 'O' in: " << x+1 << " , " << y+1 << "\n\n";
    }
}

auto GamesLibrary::Games::drawTable(auto table, int rows, int cols){
    string tableToDraw[rows][cols];
        
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(table[i][j] == 1){
                tableToDraw[i][j] = "X";
            }else if(table[i][j] == 2){
                tableToDraw[i][j] = "O";
            }else{
                tableToDraw[i][j] = " ";
            }
        }
    }
        
        
    for(int i = 0; i < rows; i++){
        cout << " " << tableToDraw[i][0] << "|"<< tableToDraw[i][1] << "|" << tableToDraw[i][2] << "\n";
        if(i < 2){
            cout << "-------\n";
        }
    }
}

void GamesLibrary::Games::TicTacToe(){
    int  table[3][3] = {{0,0,0},
                        {0,0,0},
                        {0,0,0}};

    int player;
    
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> range(1,2);

    player = range(engine);    


    while(checkForZero(table,3,3) && checkForWin(table,3,3) == 0){
        move(table,3,3,player);
        drawTable(table,3,3);
        player = 3 - player;
    }

    int result = checkForWin(table,3,3);

    if(checkForZero(table,3,3) == false && result == 0){
        cout << "\nDraw!\n";
    }else if(result == 1){
        cout << "\nYou Win!!\n";
    }else{
        cout << "\nYou lose..\n";
    }

    /*
    if(result == 2){
        cout << "\nYou lose...\n";
    }
    */

    char c;
    cout << "\nRestart?(Y/n)\n" << ">>> ";

    while(!(cin >> c) ||  (tolower(c)!= 'y' && tolower(c) != 'n')){
        cout << "\nPlese select a valid option!\n";
        cout << ">>> ";
    }

    c = tolower(c);

    if(c == 'y'){
        TicTacToe();
    }else if(c == 'n'){
        cout << "\nClosing the game...\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}