#include "Vehicle.h"

class Boat: public Vehicle {
public:
    Boat(int id, int damage): Vehicle(id, damage) {}
    void Display() {
        Vehicle::Display();
        cout << "Class Boat - id: " << id << endl;
    }
};
