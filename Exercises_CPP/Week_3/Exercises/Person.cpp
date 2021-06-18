#include "Person.h"

Person::Person() {
    state = stand;
    health = 100;
}

void Person::Crawl() {
    state = crawl;
    cout << "Crawl" << endl;
}

void Person::Run() {
    state = run;
    cout << "Run" << endl;
}

void Person::Stand() {
    state = stand;
    cout << "Stand" << endl;
}

void Person::Walk() {
    state = walk;
    cout << "Walk" << endl;
}

void Person::Damage(int amount) {
    health-=amount;
    cout << "Damaged" << endl;
    cout << "Current health: " << health << endl;
}