#include <string>
#include <iostream>

#include <AbilityDeck.hpp>
#include <RegularDeck.hpp>
#include "Player.hpp"

using namespace std;

Player::Player(int id): regularDeck(2), abilityDeck(2){
    this->id = id;
    this->nama = "";
    this->poin = 0;
    //this->regularDeck = RegularDeck(2);
    //this->abilityDeck = AbilityDeck(2);
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