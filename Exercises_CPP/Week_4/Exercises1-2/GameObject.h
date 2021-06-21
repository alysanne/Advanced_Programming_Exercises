#pragma once
#include <iostream>

using namespace std;

class GameObject {
public:
    int id;
    GameObject() {
        id = 0;
    }
    GameObject(int id): id(id) {}
};
