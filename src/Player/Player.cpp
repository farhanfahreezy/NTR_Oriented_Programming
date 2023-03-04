#include <string>
#include <iostream>

#include "../AbilityDeck.hpp"
#include "../RegularDeck.hpp"
#include "Player.hpp"

using namespace std;

Player::Player(int id){
    this->id = id;
    this->nama = "";
    this->poin = 0;
    this->regularDeck = new RegularDeck(2);
    this->abilityDeck = new AbilityDeck(2);
}

bool Player::operator<(const Player& other) const{
    return poin < other.poin;
}

bool Player::operator>(const Player& other) const{
    return poin > other.poin;
}

bool Player::operator==(const Player& other) const{
    return poin == other.poin;
}

void Player::setName(string newName){
    nama = newName;
}

void Player::addPoin(int newPoin){
    poin += newPoin;
}