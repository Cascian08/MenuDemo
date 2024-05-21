#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>
#include "../headers/games.h"

using namespace std; 

void GamesLibrary::Games::RockPaperScissor(){
    string scelta;
    string mosse[3] = {"rock", "paper", "scissor"};
    
    do{
        cout << "Scegliere una mossa tra: 'rock', 'paper', 'scissor'.\n" << ">>> " ;
        cin >> scelta;
    }while(find(begin(mosse), end(mosse), scelta) == end(mosse));

    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> range(0,3);
    
    
    string sceltaAvversario = mosse[range(engine)];
    cout << "\nL'avversario ha scelto: " << sceltaAvversario;

    cout << "\nRisultato: ";
    if(scelta == sceltaAvversario){
        cout << "Pari\n";
    }else if(scelta == "paper" && sceltaAvversario =="rock"){
        cout << "Hai vinto!\n";
    }else if(scelta == "rock" && sceltaAvversario == "scissor"){
        cout << "Hai vinto!\n";
    }else if(scelta ==  "scissor" && sceltaAvversario == "paper"){
        cout << "Hai vinto!\n";
    }else{
        cout << "Hai Perso...\n";
    }

    char s;
    cout << "\nVuoi continuare?(S/n)\n" << ">>> ";
    cin >> s;
    if(tolower(s) == 's'){
        RockPaperScissor();
    }else{
        cout << "\nChiusura Gioco...\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}