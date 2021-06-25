
#include "Vehicle.h"
#include "Car.h"
#include "Boat.h"
#include "VehicleManager.h"

Vehicle **DamagedVehicles(Vehicle **vehicles, int *size) {
    VehicleManager *damaged = new VehicleManager(*size);

    for (int i = 0; i < *size; i++) {
        if (vehicles[i]->damage >= 35) {
            damaged->Add(vehicles[i]);
        }
    }

    return damaged->GetList();
}

int main() {
    cout << "------ Exercises 5 & 6 ------" << endl;
    Vehicle *v1 = new Car(1, 35);
    Vehicle *v2 = new Boat(2, 55);
    Vehicle *v3 = new Vehicle(3, 30);
    Vehicle *v4 = new Car(4, 25);
    Vehicle *v5 = new Boat(5, 65);
    VehicleManager *manager = new VehicleManager(10);
    manager->Add(v1);
    manager->Add(v2);
    manager->Add(v3);
    manager->Add(v4);
    manager->Add(v5);
    manager->Display();

    cout << "------ Exercise 7 ------" << endl;
    int size = manager->GetCount();
    Vehicle **damagedVehicles = DamagedVehicles(manager->GetList(), &size);
    for (int i = 0; i < 3; i++) {
        damagedVehicles[i]->Display();
    }

    cout << "------ Exercise 8 ------" << endl;
    manager->DisplayDamaged();
}
