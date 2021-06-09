#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    // State machine 2
    enum Movement { stand=1, walk=2, run=3, crawl=4 };
    srand(time(NULL));
    Movement state = (Movement) ((rand() % 4) + 1);

    cout << "Initial random state is: " << state << endl;

    for (int i=0; i < 10; i++) {
        switch (state) {
            case stand:
                cout << "Your state is stand. You can walk or crawl" << endl;
                state = (rand() % 2 == 0) ? walk : crawl;
                break;
            case walk:
                cout << "Your state is walk. You can stand or run" << endl;
                state = (rand() % 2 == 0) ? stand : run;
                break;
            case run:
                cout << "Your state is run. You can walk" << endl;
                state = walk;
                break;
            case crawl:
                cout << "Your state is crawl. You can stand" << endl;
                state = stand;
                break;
        }
    }

    return 0;
}