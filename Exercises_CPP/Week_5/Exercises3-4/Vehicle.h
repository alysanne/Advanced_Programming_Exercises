#pragma once
#include <iostream>

using namespace std;

class Vehicle {
private:
    int damage;
protected:
    int id;
public:
    Vehicle(int id, int damage): id(id), damage(damage) {}
    virtual void Display() {
        cout << "Class Vehicle - id: " << id << endl;
    }
};
