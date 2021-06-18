#pragma once
#include <iostream>

using namespace std;

enum Movements {stand=1, walk=2, run=3, crawl=4};

class Person {
protected:
    Movements state;
public:
    int health;
    Person();
    void Crawl();
    void Run();
    void Walk();
    void Stand();
    void Damage(int amount);
};