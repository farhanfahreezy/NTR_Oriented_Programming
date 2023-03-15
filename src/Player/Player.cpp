#include <string>
#include <iostream>

#include <Deck/AbilityDeck.hpp>
#include <Deck/RegularDeck.hpp>
#include "Player.hpp"

using namespace std;

Player::Player(int id): /*regularDeck(2), abilityDeck(2)*/ InventoryHolder(0, 0, 0){
    this->id = id;
    this->nama = "";
    this->poin = 0;
}

Player::Player(): /*regularDeck(2), abilityDeck(2)*/ InventoryHolder(0, 0, 0){
    this->id = -1;
    this->nama = "";
    this->poin = 0;
}

Player& Player::operator=(const Player& other){
    id = other.id;
    nama = other.nama;
    point = other.poin;

    return *this;
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

string Player::getName() const{
    return this->nama;
}

int Player::getId() const{
    return this->id;
}

void Player::toFile(File::Write& writer) const{
    InventoryHolder::toFile(writer);
    writer << nama << '\n';
    writer << id << ' ' << poin << '\n';
}

void Player::fromFile(File::Read& reader){
    InventoryHolder::fromFile(reader);
    string s;
    reader >> nama;
    
    reader >> s;
    stringstream ss(s);
    getline(ss, s, ' ');
    id = stoi(s);
    getline(ss, s, ' ');
    poin = stoi(s);
}
