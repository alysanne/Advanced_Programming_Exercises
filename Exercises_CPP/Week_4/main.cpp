#include "GameObject.h"
#include "HealthKit.h"

int main () {
    cout << "------ Exercise 3 ------" << endl;
//    GameObject obj1;
//    cout << obj1.id << endl;

    cout << "------ Exercise 4 & 5------" << endl;
    GameObject obj2(45, new Location(1, 1, 1));
    GameObject obj3(3, new Location(2, 2, 2));
    GameObject obj4(4, new Location(3, 3, 3));
    GameObject obj5(5, new Location(4, 4, 4));
    cout << "Instances:" << GameObject::instances << endl;

    cout << "Object with id " << obj2.id << " has location:" << endl;
    obj2.location->Display();

    cout << "Object with id " << obj3.id << " has location:" << endl;
    obj3.location->Display();

    cout << "Object with id " << obj4.id << " has location:" << endl;
    obj4.location->Display();

    cout << "Object with id " << obj5.id << " has location:" << endl;
    obj5.location->Display();

    cout << "------ Exercise 6 ------" << endl;
    GameObject obj6 = obj4;
    cout << "Location for obj6" << endl;
    obj6.location->Display();
    cout << "Location for obj4" << endl;
    obj4.location->Display();

    cout << "Changing location for obj4" << endl;
    obj4.location->Set(8, 8, 8);

    cout << "Location for obj6" << endl;
    obj6.location->Display();
    cout << "Location for obj4" << endl;
    obj4.location->Display();

    cout << "------ Exercise 7 ------" << endl;
    HealthKit healthkit(10, new Location(9, 9, 9));
}