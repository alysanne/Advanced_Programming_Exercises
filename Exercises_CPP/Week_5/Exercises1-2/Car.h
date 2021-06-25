#include "Vehicle.h"

class Car: public Vehicle {
public:
    Car(int id, int damage): Vehicle(id, damage) {}
    void Display() {
        Vehicle::Display();
        cout << "Class Car - id: " << id << endl;
    }
};
