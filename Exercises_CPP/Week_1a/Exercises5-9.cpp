#include <iostream>
#include <string>
#include <time.h>
#include "MyVars.h"
using namespace std;

namespace firstJob {
    int salary = 20000;
}

namespace secondJob {
    int salary = 15000;
}

int main (int argc, char *argv[]) {
    cout << firstJob::salary << endl;
    cout << secondJob::salary << endl;
    cout << surname << endl;
    cout << surname.length() << endl;
    cout << surname[0] << endl;
    cout << surname[8] << endl << endl;
    cout << "-------------------------" << endl;

    // Time
    time_t timeSeconds;
    struct tm timeinfo;
    char result[32];
    
    time(&timeSeconds);
    localtime_r(&timeSeconds, &timeinfo);
    asctime_r(&timeinfo, result);

    cout << "The current time is " << result << endl;
    cout << "Seconds since Epoch: " << timeSeconds << endl;
    cout << "Hours: " << timeinfo.tm_hour << endl;
    cout << "Minutes: " << timeinfo.tm_min << endl;
    cout << "Seconds: " << timeinfo.tm_sec << endl;

    return 0;
}