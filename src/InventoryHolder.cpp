#include <iostream>
using namespace std;

#include "InventoryHolder.cpp"

class InventoryHolder {
    //ctor
    InventoryHolder(T poin, int n_regulardeck, int n_abilitydeck){
        this->point = poin;
        this->regularDeck = new RegularDeck(n_regulardeck);
        this->abilityDeck = new AbilityDeck(n_abilitydeck);
    }

    //dtor
    ~InventoryHolder(){
        delete regularDeck;
        delete abilityDeck;
    }

    //get function
    T getPoint(){
        return this->point;
    }
    RegularDeck getRegularDeck(){
        return this->regularDeck;
    }
    
    AbilityDeck getAbilityDeck(){
        return this->abilityDeck;
    }

    //set function
    void setPoint(int num){
        this->point = num;
    }
    void increasePointByScale(int num){
        this->point *= num;
    }
    void increasePointByAmount(int){
        this->point += num;
    }
}