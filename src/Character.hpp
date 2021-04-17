#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include <string>
#include "Weapon.hpp"
using namespace std;

class Character{
    private:
        string name;
        double health;
        Weapon* weapon;
        void defence(double);
    
    public:
        Character(string);
        void display();
        void attack(Character*);
        //getter
        string getName();
        string getWeapon();
        double getHealth();
        //setter
        void equipWeapon(Weapon*);
};

#endif