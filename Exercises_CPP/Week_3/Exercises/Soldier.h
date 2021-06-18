#pragma once
#include "Person.h"
#include "Weapon.h"

class Soldier:public Person {
private:
    Weapon *weapon;
public:
    Soldier(Weapon *weapon);
    void FireWeapon(Person *person);
    void FireWeapon(Person *person, int burst);
};