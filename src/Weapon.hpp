#ifndef WEAPON
#define WEAPON

#include <iostream>
#include <string>
using namespace std;

class Weapon{
    private:
        string name;
        double power;

    public:
        Weapon(string, double); //constructor
        //getter
        double getPower();
        string getName();
};

#endif