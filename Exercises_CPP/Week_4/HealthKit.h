#include "GameObject.h"

class HealthKit: public GameObject {
public:
    HealthKit(int id, Location *location): GameObject(id, location) {
        cout << "HealthKit constructor invoked" << endl;
    }
};