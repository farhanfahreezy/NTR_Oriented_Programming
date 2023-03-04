#include <iostream>
using namespace std;

#include "InventoryHolder.hpp"

//ctor
InventoryHolder::InventoryHolder(int poin, int n_regulardeck, int n_abilitydeck){
    this->point = poin;
    this->regularDeck = new RegularDeck(n_regulardeck);
    this->abilityDeck = new AbilityDeck(n_abilitydeck);
}

//dtor
InventoryHolder::~InventoryHolder(){
    delete regularDeck;
    delete abilityDeck;
}

//get function
int InventoryHolder::getPoint(){
    return this->point;
}
RegularDeck InventoryHolder::getRegularDeck(){
    return this->regularDeck;
}

AbilityDeck InventoryHolder::getAbilityDeck(){
    return this->abilityDeck;
}

//set function
void InventoryHolder::setPoint(int num){
    this->point = num;
}
void InventoryHolder::increasePointByScale(int num){
    this->point *= num;
}
void InventoryHolder::increasePointByAmount(int num){
    this->point += num;
}
