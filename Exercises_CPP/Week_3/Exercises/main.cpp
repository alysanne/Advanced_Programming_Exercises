#include <iostream>
#include "Person.h"
#include "Soldier.h"

int main() {
    cout << "------ Exercise 1 ------" << endl;
    Person *person = new Person();
    person->Crawl();
    person->Run();
    person->Stand();
    person->Walk();

    cout << "------ Exercises 2 & 3 ------" << endl;
    Soldier *soldier = new Soldier(new Weapon());
    soldier->Stand();
    soldier->FireWeapon(person);

    cout << "------ Exercise 4 ------" << endl;
    soldier->Crawl();
    soldier->FireWeapon(person);

    cout << "------ Exercise 5 ------" << endl;
    soldier->Stand();
    soldier->FireWeapon(person, 6);

    cout << "------ Exercise 6 ------" << endl;
    soldier->FireWeapon(person, 10);
}