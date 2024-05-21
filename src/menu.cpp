#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "../headers/games.h"
#include "../headers/menu.h"

using namespace std;
using namespace GamesLibrary;

void Menu::Menu::drawMenu(){
    cout << R"(                                              
 _    _      _                            _         ___  ___                ______                     _ 
| |  | |    | |                          | |        |  \/  |                |  _  \                   | |
| |  | | ___| | ___ ___  _ __ ___   ___  | |_ ___   | .  . | ___ _ __  _   _| | | |___ _ __ ___   ___ | |
| |/\| |/ _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  | |\/| |/ _ \ '_ \| | | | | | / _ \ '_ ` _ \ / _ \| |
\  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |  | |  __/ | | | |_| | |/ /  __/ | | | | | (_) |_|
 \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/  \_|  |_/\___|_| |_|\__,_|___/ \___|_| |_| |_|\___/(_)
                                                                                                                                                                                                       
          ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______            
         |______|______|______|______|______|______|______|______|______|______|______|______| 

                                         Select an option:
                                 1 - Play Rock, paper, scissor.
                                     2 - Play Tic Tac Toe.
                                            3 - Quit.                                                                      
    
    )"<< "\n";
}

void Menu::Menu::menu(){
    
    GamesLibrary::Games Games;

    int scelta;
    bool q = 0;
    drawMenu(); 
    while(q!=1){
        cout << ">>> ";
        cin >> scelta;
        switch(scelta){
            case 1:
                Games.RockPaperScissor();
                break;
            case 2:
                Games.TicTacToe();
                break;
            case 3:
                cout << "\nChiusura programma...\n";
                this_thread::sleep_for(chrono::milliseconds(1000));
                q = 1;
                break;            
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Errore! Inserire un opzione valida!\n"; 
        }
    }
}
