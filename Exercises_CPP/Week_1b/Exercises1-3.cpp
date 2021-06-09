#include <iostream>
#include <string>
using namespace std;
#define test

int main (int argc, char *argv[]) {
    // Array with random values between 0-100
    const int scoresNo = 100;
    int scores[scoresNo];

    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        scores[i] = rand() % 101;
    }

    // Array with count of numbers between ranges
    int ranges[4] = {0,0,0,0};

    for (int i = 0; i < 100; i++) {
        if (scores[i] <= 40){
            ranges[0]++;
        } else if (scores[i] > 40 && scores[i] <= 60){
            ranges[1]++;
        } else if (scores[i] > 60 && scores[i] <= 80){
            ranges[2]++;
        } else {
            ranges[3]++;
        }
    }

    cout << "Novice 0..40: " << ranges[0] << endl;
    cout << "Intermediate 41..60: " << ranges[1] << endl;
    cout << "Advanced 61..80: " << ranges[2] << endl;
    cout << "Hardcore 81..100: " << ranges[3] << endl;

    // Preprocessor directive for test code
    #ifdef test
    int total = ranges[0] + ranges[1] + ranges[2] + ranges[3];
    if (total == 100) {
        cout << "Pass" << endl;
    } else {
        cout << "Fail" << endl;
    }
    #endif

    // State machine with enums
    enum Movement { stand=1, walk=2, run=3, crawl=4 };
    Movement state = (Movement) ((rand() % 4) + 1);

    cout << "Random state is: " << state << endl;

    switch (state) {
        case stand:
            cout << "You can walk or crawl" << endl;
            break;
        case walk:
            cout << "You can stand or run" << endl;
            break;
        case run:
            cout << "You can walk" << endl;
            break;
        case crawl:
            cout << "You can stand" << endl;
            break;
    }

    return 0;
}