#pragma once
#include "Magic.h"
#include <string>
#include <iostream>

using namespace std;

class Spell: public Magic {
public:
    Spell(string words): Magic(), words(words) {}
    void Display() {
        cout << "Spell words: " << words << endl;
    }
private:
    string words;
};