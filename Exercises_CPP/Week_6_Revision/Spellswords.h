#include "Wizard.h"
#include <string>

using namespace std;

class Spellswords: public Wizard {
private:
    string weapon;
public:
    Spellswords(string name, int knowledge, int skill, int maxMagic, string weapon) :
            Wizard(name, knowledge, skill, maxMagic),
            weapon(weapon) {}
    void Display() {
        Wizard::Display();
        cout << "Weapon: " << weapon << endl;
    }
};
