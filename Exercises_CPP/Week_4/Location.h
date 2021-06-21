#include <iostream>

using namespace std;

class Location {
public:
    int x, y, z;
    void Display() {
        cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
    }
    Location();
    Location(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void Set(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
