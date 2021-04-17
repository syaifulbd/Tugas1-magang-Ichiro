#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>
#include <vector>
#include "Weapon.hpp"
#include "Character.hpp"
using namespace std;

class Player {

    public:
    string name;

    Player(string);
    void AddCharacter(Character* character);
    void AddWeapon(Weapon* weapon);

    vector <Character *> Getlistc();
    vector <Weapon *> Getlistw();
    
    private:
    vector <Character *> listc;
    vector <Weapon *> listw;
};

#endif