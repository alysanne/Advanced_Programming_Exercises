#include "Vehicle.h"
#include "Car.h"
#include "Boat.h"

int main() {
    cout << "------ Exercises 1 & 2 ------" << endl;
    Vehicle *v1 = new Vehicle(1, 30);
    Boat *b1 = new Boat(2, 50);
    Car *c1 = new Car(3, 40);

    v1->Display();
    b1->Display();
    c1->Display();
}
