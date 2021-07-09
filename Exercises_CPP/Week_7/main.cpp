#include <iostream>
#include <string>
#include "GameObject.h"

using namespace std;

// Exercise 1
void HelloMessage() {
    cout << "Hello" << endl;
}

void Goodbye() {
    cout << "Goodbye" << endl;
}

// Exercise 2
void Message(const string msg) {
    cout << msg << endl;
}

// Exercise 3-4
typedef bool (*sortType)(int, int);

void Sort(int *numbers, int size, sortType sort) {
    for (int n= 0; n < size; n++) {
        int nBestIndex = n;
        for (int i = n + 1; i < size; i++){
            if (sort(numbers[i], numbers[nBestIndex]))
                nBestIndex = i;
        }
        swap(numbers[n], numbers[nBestIndex]);
    }
    for (int i=0; i < size; i++)
        cout << numbers[i] << endl;
}

bool Ascending(int nX, int nY) {
    return nY > nX;
}

bool Descending(int nX, int nY) {
    return nY < nX;
}

// Exercise 8
template<typename T>
void DisplayArray(T *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

// Exercise 9
template<typename T>
T SumArray(T *array, int size) {
    T result;
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            result = array[i];
        } else {
            result += array[i];
        }
    }
    return result;
}

int main() {
    cout << "------ Exercise 1 ------" << endl;
    void (*ptr1)() = HelloMessage;
    void (*ptr2)() = Goodbye;
    ptr1();
    ptr2();

    cout << "------ Exercise 2 ------" << endl;
    void (*ptr3)(string) = Message;
    ptr3("A message!");

    cout << "------ Exercise 3 & 4 ------" << endl;
    int items[] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };
    Sort(items, 9, Ascending);
    cout << endl;
    Sort(items, 9, Descending);

    cout << "------ Exercise 5 & 6 ------" << endl;
    GameObject<int> gameObject(1, 1, 1, 1);
    void (GameObject<int>::*ptr4)();
    ptr4 = &GameObject<int>::Draw;
    (gameObject.*ptr4)();

    cout << "------ Exercise 7 ------" << endl;
    int *(GameObject<int>::*ptr5)(int, int, int);
    ptr5 = &GameObject<int>::Move;
    int *result = (gameObject.*ptr5)(1, 2, 3);
    for (int i = 0; i < 3; i++) {
        cout << result[i] << endl;
    }

    cout << "------ Exercise 8 ------" << endl;
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    DisplayArray(nums, 9);

    cout << "------ Exercise 9 ------" << endl;
    cout << SumArray(nums, 9) << endl;
    float numsL[] = { 1.5, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
    cout << SumArray(numsL, 9) << endl;

    cout << "------ Exercise 10 ------" << endl;
    GameObject<int> gameObjectInt(5, 5, 6, 7);

    // Draw pointer
    void (GameObject<int>::*drawIntPtr)();
    drawIntPtr = &GameObject<int>::Draw;
    (gameObjectInt.*drawIntPtr)();

    // Move pointer
    int *(GameObject<int>::*moveIntPtr)(int, int, int);
    moveIntPtr = &GameObject<int>::Move;
    int *resultInt = (gameObject.*moveIntPtr)(8, 9, 10);
    for (int i = 0; i < 3; i++) {
        cout << resultInt[i] << endl;
    }

    GameObject<float> gameObjectFloat(7, 7.7, 8.8, 9.9);

    // Draw pointer
    void (GameObject<float>::*drawFloatPtr)();
    drawFloatPtr = &GameObject<float>::Draw;
    (gameObjectInt.*drawIntPtr)();

    // Move pointer
    float *(GameObject<float>::*moveFloatPtr)(float, float, float);
    moveFloatPtr = &GameObject<float>::Move;
    float *resultFloat = (gameObjectFloat.*moveFloatPtr)(1.1, 2.2, 3.3);
    for (int i = 0; i < 3; i++) {
        cout << resultFloat[i] << endl;
    }
}
