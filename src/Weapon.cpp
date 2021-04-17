#include <iostream>
#include <string>
#include "Weapon.hpp"

//constructor
Weapon::Weapon(string name, double power){
    Weapon::name = name;
    Weapon::power = power;
}

// getter
double Weapon::getPower(){
    return Weapon::power;
}

std::string Weapon::getName(){
    return Weapon::name;
}