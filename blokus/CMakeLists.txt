cmake_minimum_required(VERSION 2.6)
project(blokus)
add_definitions(-std=c++14)
add_executable(blokus game.cpp grid.cpp player.cpp shape.cpp main.cpp)
