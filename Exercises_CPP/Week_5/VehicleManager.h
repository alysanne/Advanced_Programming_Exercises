#include "Vehicle.h"

class VehicleManager {
private:
    int count;
    int maxVehicles;
    Vehicle **vehicle;
public:
    VehicleManager(int size): maxVehicles(size), count(0) {
        vehicle = new Vehicle*[maxVehicles];
    }
    bool Add(Vehicle *v) {
        if (count < maxVehicles) {
            vehicle[count] = v;
            count++;
            return true;
        } else {
            return false;
        }
    }
    void Display() {
        for(int i = 0; i < count; i++) {
            vehicle[i]->Display();
        }
    }
    int GetCount() {
        return count;
    }
    Vehicle** GetList() {
        return vehicle;
    }

    void DisplayDamaged() {
        for (int i = 0; i < count; i++) {
            if (vehicle[i]->damage >= 35) {
                vehicle[i]->Display();
            }
        }
    }
};