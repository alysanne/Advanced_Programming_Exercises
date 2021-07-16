#include "Weapon.h"

int main() {
  Weapon weapon(0, false);

  cout << "------ Exercises 1 & 2 ------" << endl;
  try {
    weapon.Fire();
  } catch(int e) {
    cout << "error: " << e << endl;
  } catch(NoAmmoException& e) {
    cout << "error: " << e.what() << endl;
  }

  cout << "------ Exercise 3 ------" << endl;
  try {
    weapon.Reload();
    weapon.Reload();
  } catch(MagazineFullException& e) {
    cout << "error: " << e.what() << endl;
  }

  cout << "------ Exercise 4 ------" << endl;
  Weapon jammedWeapon(0, true);
  try {
    jammedWeapon.Reload();
    jammedWeapon.Fire();
  } catch(NoAmmoException& e) {
    cout << "error: " << e.what() << endl;
  } catch(MagazineFullException& e) {
    cout << "error: " << e.what() << endl;
  } catch(...) {
    cout << "error: unspecified exception" << endl;
  }

  cout << "------ Exercises 5 & 6 ------" << endl;
  try {
    jammedWeapon.Fire();
  } catch(JammedException& e) {
    cout << "error: " << e.what() << endl;
    cout << "Rounds: " << e.GetRounds() << endl;
  }

  cout << "------ Exercise 7 ------" << endl;
  Weapon wrongWeapon(12, true);
}