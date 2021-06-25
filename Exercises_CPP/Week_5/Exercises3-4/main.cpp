#include "Vehicle.h"
#include "Car.h"
#include "Boat.h"

int main() {
    cout << "------ Exercises 3 & 4 ------" << endl;
    Vehicle *vehicles[5];
    vehicles[0] = new Car(1, 35);
    vehicles[1] = new Boat(2, 55);
    vehicles[2] = new Vehicle(3, 30);
    vehicles[3] = new Car(4, 25);
    vehicles[4] = new Boat(5, 65);

    for(int i = 0; i < 5; i++) {
        vehicles[i]->Display();
    }
}
