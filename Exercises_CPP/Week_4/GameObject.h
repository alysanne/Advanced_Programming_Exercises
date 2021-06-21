#pragma once
#include <iostream>
#include "Location.h"

using namespace std;

class GameObject {
public:
    int id;
    static int instances;
    Location *location;
    GameObject(int id, Location *location): id(id) {
        cout << "GameObject constructor invoked" << endl;
        instances++;
        this->location = location;
    }
    GameObject(GameObject &gameObject) {
        this->location = new Location(
                gameObject.location->x,
                gameObject.location->y,
                gameObject.location->z
                );
    }
};
