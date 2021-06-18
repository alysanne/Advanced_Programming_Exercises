#include "Weapon.h"

Weapon::Weapon() {
    rounds = 10;
}

bool Weapon::Fire(Person *person) {
    if (rounds > 0) {
        cout << "Weapon Fired" << endl;
        rounds--;
        person->Damage(1);
        return true;
    }
    cout << "Not enough ammo" << endl;
    Weapon::Reload();
    Weapon::Fire(person);
    return false;
}

bool Weapon::Fire(Person *person, int burst) {
    if (rounds >= burst) {
        cout << "Automatic Weapon Fire" << endl;
        rounds-=burst;
        person->Damage(burst);
        return true;
    }
    cout << "Not enough ammo" << endl;
    Weapon::Reload();
    Weapon::Fire(person, burst);
    return false;
}


void Weapon::Reload() {
    rounds = 10;
    cout << "Reloading" << endl;
}
