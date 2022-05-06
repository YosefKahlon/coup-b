cmake_minimum_required(VERSION 3.16)
project(coup_b)

set(CMAKE_CXX_STANDARD 14)

add_executable(coup_b main.cpp sources/Captain.cpp sources/Duke.cpp sources/Contessa.cpp sources/Ambassador.cpp sources/Assassin.cpp sources/Game.cpp sources/Player.cpp)
