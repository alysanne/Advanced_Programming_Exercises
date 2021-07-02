#pragma once

#include "Wizard.h"
#include <string>

class Elementalist : public Wizard {
public:
    enum TElements {
        earth, wind, fire, water
    };
    Elementalist(string name, int knowledge, int skill, int maxMagic, TElements specialism) :
            Wizard(name, knowledge, skill, maxMagic),
            specialism(specialism) {}
    void Display() {
        Wizard::Display();
        switch (specialism) {
            case earth:
                cout << "Earth" << endl;
                break;
            case wind:
                cout << "Wind" << endl;
                break;
            case fire:
                cout << "Fire" << endl;
                break;
            case water:
                cout << "Water" << endl;
                break;
        }
    }
private:
    TElements specialism;
};
