#pragma once
#include "Magic.h"
#include <string>
#include <iostream>

using namespace std;


class Wizard {
private:
    int knowledge;
    int magicCount;
    Magic **magicInventory;
    string name;
    int skill;
public:
    Wizard(string name, int knowledge, int skill, int maxMagic) : name(name), knowledge(knowledge), skill(skill) {
        magicInventory = new Magic *[maxMagic];
        magicCount = 0;
    }
    void AddMagic(Magic *magic) {
        if (magicCount < sizeof(magicInventory)) { // Save maxMagic instead
            magicInventory[magicCount] = magic;
            magicCount++;
        }
    }
    void Display() {
        cout << "Name: " << name << endl;
        cout << "Skill: " << skill << endl;
        cout << "Knowledge: " << knowledge << endl;

        for (int i = 0; i < magicCount; i++) {
            magicInventory[i]->Display();
        }
    }
};
