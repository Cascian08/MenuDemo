#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "../headers/games.h"
#include "../headers/menu.h"

using namespace std;
using namespace GamesLibrary;



//Draws the main menu screen.
void MenuLibrary::Menu::drawMenu(){
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

Press '4' to open the 'help' command.    
    )"<< "\n";
}

void MenuLibrary::Menu::help(){
    cout << R"(
    List of commands:

    1 - Play: Rock, paper, scissor.
    2 - Play: Tic Tac Toe.
    3 - Quit, closes the program.
    4 - Help, returns all the commands.)" << "\n\n";
}

//Main menu function.
void MenuLibrary::Menu::menu(){
    
    GamesLibrary::Games Games;

    int choose;
    bool q = 0;
    
    drawMenu(); 
    
    while(q!=1){
        cout << ">>> ";
        cin >> choose;
        switch(choose){
            case 1:
                Games.RockPaperScissor();
                break;
            case 2:
                Games.TicTacToe();
                break;
            case 3:
                cout << "\nClosing the program...\n";
                this_thread::sleep_for(chrono::milliseconds(500));
                q = 1;
                break;
            case 4:
                help();
                break;            
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error! Please insert a valid option!\n"; 
                cout << "Press '4' to open the 'help' command.\n";
        }
    }
}
