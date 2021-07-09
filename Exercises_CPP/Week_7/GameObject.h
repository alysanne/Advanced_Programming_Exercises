#include <iostream>

using namespace std;

template<class T>
class GameObject {
private:
    int id;
    T position[3];
public:
    GameObject(int id, T x, T y, T z) : id(id) {
        position[0] = x;
        position[1] = y;
        position[2] = z;
    }

    void Draw() {
        cout << "GameObject" << endl;
        cout << "id: " << id << endl;
    }

    T *Move(T x, T y, T z) {
        position[0] = x;
        position[1] = y;
        position[2] = z;
        return position;
    }
};
