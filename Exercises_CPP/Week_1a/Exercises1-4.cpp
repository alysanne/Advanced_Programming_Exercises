#include <iostream>
#include <string>
using namespace std;

int main (int argc, char *argv[]) {
    const int DAYS_IN_YEAR = 365;

    string name;
    int age;
    
    cout << "What's your name?: ";
    cin >> name;

    cout << "What's your age?: ";
    cin >> age;


    cout << "Hello " << name << ", you are " << age <<  " years old." << endl;

    int ageInDays = age * DAYS_IN_YEAR;

    cout << "You are " << ageInDays << " days old." << endl;
    
    int *pAge = &age;
    age = 10;

    cout << "Memory address for 'age': " << &age << ", with value: " << age << endl;
    cout << "Memory address saved in 'pAge': " << pAge << ", pointing to value: " << *pAge << endl;

    int& rAge = age;
    age = 19;

    cout << "Memory address for 'age': " << &age << ", with value: " << age << endl;
    cout << "Memory address saved in 'rAge': " << &rAge << ", pointing to value: " << rAge << endl;

    return 0;
}