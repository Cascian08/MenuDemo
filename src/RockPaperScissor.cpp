#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>
#include "../headers/games.h"

using namespace std; 

void GamesLibrary::Games::RockPaperScissor(){
    string choice;
    string moves[3] = {"rock", "paper", "scissor"};
    

    //Gets a move by the user.
    do{
        cout << "\nChoose a move between: 'rock', 'paper', 'scissor'.\n" << ">>> " ;
        cin >> choice;
    }while(find(begin(moves), end(moves), choice) == end(moves));

    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> range(0,3);
    
    //Computer randomly selects a move. 
    string opponentChoice = moves[range(engine)];
    cout << "\nThe opponent has chosen: " << opponentChoice;

    //Displays the final Result:
    cout << "\nFinal result: ";
    if(choice == opponentChoice){
        cout << "Draw!\n";
    }else if(choice == "paper" && opponentChoice =="rock"){
        cout << "You win!!!\n";
    }else if(choice == "rock" && opponentChoice == "scissor"){
        cout << "You win!!!\n";
    }else if(choice ==  "scissor" && opponentChoice == "paper"){
        cout << "You win!!!\n";
    }else{
        cout << "You lose...\n";
    }


    //Asks to the user if he wants to restart.
    char c;
    cout << "\nRestart?(Y/n)\n" << ">>> ";

    while(!(cin >> c) ||  (tolower(c)!= 'y' && tolower(c) != 'n')){
        cout << "\nPlese select a valid option!\n";
        cout << ">>> ";
    }

    c = tolower(c);

    if(c == 'y'){
        RockPaperScissor();
    }else if(c == 'n'){
        cout << "\nClosing the game...\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}