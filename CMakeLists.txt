cmake_minimum_required(VERSION 3.21)
project(Naval_Combat)

set(CMAKE_CXX_STANDARD 20)

add_executable(Naval_Combat main.cpp Battlefield.h Battle.h Battle.cpp Battlefield.cpp "Game tools.h" Ship.h Ship.cpp Player.h Player.cpp Checks.h Checks.cpp)
