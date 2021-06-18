cmake_minimum_required(VERSION 3.19)
project(Exercises)

set(CMAKE_CXX_STANDARD 14)

add_executable(Exercises_w1a_1-4 Week_1a/Exercises1-4.cpp)
add_executable(Exercises_w1a_5-9 Week_1a/Exercises5-9.cpp)
add_executable(Exercises_w1b_1-3 Week_1b/Exercises1-3.cpp)
add_executable(Exercises_w1b_4 Week_1b/Exercise4.cpp)
add_executable(Exercises_w2_1-5 Week_2/Exercises1-5.cpp)
add_executable(Exercises_w2_6-8 Week_2/Exercises6-8.cpp)
add_executable(Exercises_w3 Week_3/main.cpp Week_3/Person.cpp Week_3/Person.h Week_3/Soldier.cpp Week_3/Soldier.h Week_3/Weapon.cpp Week_3/Weapon.h)
add_executable(Exercises_w4 Week_4/main.cpp)