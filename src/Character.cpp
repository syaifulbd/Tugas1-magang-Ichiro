#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "Character.hpp"
using namespace std;


Character::Character(string name) {
    Character::name = name;
    Character::health = 100;
}
void Character::display(){
    if(Character::health>0) {
        cout << "\tName\t: " << Character::name << endl;
        cout << "\tHealth\t: " << Character::health << endl;
        cout << "\tWeapon\t: " << Character::weapon->getName() << endl;
        cout << "\tPower\t: "<< Character::weapon->getPower() << endl;
    }
}
void Character::attack(Character* character){
    if (Character::health <= 0){
        cout << Character::name << " sudah meninggal" << endl;
        cout << Character::name << " tidak dapat menyerang" << endl;
    } else {
        cout << endl << Character::name << " menyerang " << character->getName() << endl;
        character->defence(Character::weapon->getPower());
    }
}
//getter
string Character::getName(){
    return Character::name;
}
string Character::getWeapon() {
    return Character::weapon->getName();
}
double Character::getHealth() {
    return Character::health;
}
//setter
void Character::equipWeapon(Weapon* weapon){
    Character::weapon = weapon;
}
void Character::defence(double damage){
    Character::health -= damage;
    cout << Character::name << " mendapatkan damage : " << damage << endl;

    if (Character::health <= 0){
        cout << Character::name << " mati" << endl;
    }

}