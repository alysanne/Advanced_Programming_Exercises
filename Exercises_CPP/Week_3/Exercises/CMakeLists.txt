cmake_minimum_required(VERSION 3.19)
project(Exercises)

set(CMAKE_CXX_STANDARD 14)

add_executable(Exercises main.cpp Person.cpp Person.h Soldier.cpp Soldier.h Weapon.cpp Weapon.h)