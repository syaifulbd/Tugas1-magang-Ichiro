#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "Character.hpp"
#include "Player.hpp"

Player::Player(string name) {
    Player::name=name;
}

void Player::AddCharacter(Character* character) {
    listc.push_back(character);
}

void Player::AddWeapon(Weapon* weapon) {
    listw.push_back(weapon);
}

vector <Character*> Player::Getlistc() {
    return listc;
}

vector <Weapon*> Player::Getlistw() {
    return listw;
}
