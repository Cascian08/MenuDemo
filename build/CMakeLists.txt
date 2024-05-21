cmake_minimum_required(VERSION 3.10)
project(MenuDemo)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..)

add_subdirectory(../src ${CMAKE_CURRENT_BINARY_DIR}/src)