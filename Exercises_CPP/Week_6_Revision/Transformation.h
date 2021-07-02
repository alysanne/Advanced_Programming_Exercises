#pragma once
#include "Magic.h"
#include <string>
#include <iostream>

using namespace std;

class Transformation: public Magic {
public:
    Transformation(string creature): Magic(), creature(creature) {}
    void Display() {
        cout << "Transformation creature: " << creature << endl;
    }
private:
    string creature;
};
