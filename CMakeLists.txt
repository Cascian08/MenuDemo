cmake_minimum_required(VERSION 3.10)
project(MenuDemo)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

add_executable(MenuDemo 
    src/main.cpp 
    src/menu.cpp 
    src/RockPaperScissor.cpp 
    src/TicTacToe.cpp
)