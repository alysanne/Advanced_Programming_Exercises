#pragma once

#include <iostream>
#include <assert.h>
#include "NoAmmoException.h"
#include "MagazineFullException.h"
#include "JammedException.h"

using namespace std;

class Weapon {
private:
  int rounds;
  bool jammed;
  NoAmmoException ENoAmmo;
  MagazineFullException EMagFull;

public:
  Weapon(int rounds, bool jammed) : rounds(rounds), jammed(jammed) {
    assert(rounds >= 0 && rounds <= 10);
  }

  void Fire() throw (NoAmmoException, JammedException) {
    if (rounds < 1)
      throw ENoAmmo;
    if (jammed) {
      throw JammedException(rounds);
    }
    cout << "Weapon Fired\n" << endl;
    rounds--;
  }

  void Reload() throw (MagazineFullException) {
    if (rounds >= 10) {
      throw EMagFull;
    }
    rounds += 10;
    if (rounds > 10)
      rounds = 10;
    cout << "Weapon Reloaded \n" << endl;
  }
};