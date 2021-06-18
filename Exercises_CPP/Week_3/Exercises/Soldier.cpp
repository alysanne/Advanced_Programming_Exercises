#include "Soldier.h"

Soldier::Soldier(Weapon *weapon) {
    Soldier::weapon = weapon;
}

void Soldier::FireWeapon(Person *person) {
    if (weapon != 0 && state != crawl) {
        weapon->Fire(person);
    }
}

void Soldier::FireWeapon(Person *person, int burst) {
    if (weapon != 0 && state != crawl) {
        weapon->Fire(person, burst);
    }
}
