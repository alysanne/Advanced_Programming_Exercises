#pragma once
#include "Magic.h"
#include <iostream>

using namespace std;

class Potion: public Magic {
public:
    Potion(int dose): Magic(), dose(dose) {}
    void Display() {
        cout << "Potion dose: " << dose << endl;
    }
private:
    int dose;
};
