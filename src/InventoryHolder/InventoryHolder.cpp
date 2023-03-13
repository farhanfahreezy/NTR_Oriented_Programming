#include <iostream>
#include "InventoryHolder.hpp"

using namespace std;

// ctor
InventoryHolder::InventoryHolder(int poin, int n_regulardeck, int n_abilitydeck)
    : point(poin), regularInv(n_regulardeck), abilityInv(n_abilitydeck)
{}

// get functions
int InventoryHolder::getPoint() const {
    return point;
}

const vector<RegularCard>& InventoryHolder::getRegularInv() const{
    return regularInv;
}

const vector<AbilityCard>& InventoryHolder::getAbilityInv() const {
    return abilityInv;
}

int InventoryHolder::getRegularInvSize() const {
    return regularInv.size();
}

int InventoryHolder::getAbilityInvSize() const {
    return abilityInv.size();
}

// set functions
void InventoryHolder::setPoint(int num) {
    point = num;
}

void InventoryHolder::increasePointByScale(int num) {
    point *= num;
}

void InventoryHolder::increasePointByAmount(int num) {
    point += num;
}

// inventory functions
void InventoryHolder::addRegularCard(const RegularCard& card, int max) {
    if (regularInv.size() < max) {
        regularInv.push_back(card);
    } else {
        throw out_of_range("Regular card inventory is full");
    }
}

void InventoryHolder::addAbilityCard(const AbilityCard& card, int max) {
    if (abilityInv.size() < max) {
        abilityInv.push_back(card);
    } else {
        throw out_of_range("Ability card inventory is full");
    }
}

RegularCard InventoryHolder::removeRegularCard(int index) {
    if (index < 0 || index >= regularInv.size()) {
        throw out_of_range("Invalid index for regular card inventory");
    }
    RegularCard removedCard = regularInv[index];
    regularInv.erase(regularInv.begin() + index);
    return removedCard;
}

AbilityCard InventoryHolder::removeAbilityCard(int index) {
    if (index < 0 || index >= abilityInv.size()) {
        throw out_of_range("Invalid index for ability card inventory");
    }
    AbilityCard removedCard = abilityInv[index];
    abilityInv.erase(abilityInv.begin() + index);
    return removedCard;
}
