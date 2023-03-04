#ifndef INVENTORYHOLDER_H
#define INVENTORYHOLDER_H

#include <iostream>
using namespace std;

#include "RegularDeck.hpp"
#include "AbilityDeck.hpp"

class InventoryHolder {
    private:
        int point;
        RegularDeck regularDeck;
        AbilityDeck abilityDeck;
    public:
        //ctor
        InventoryHolder(int, int, int);

        //dtor
        ~InventoryHolder();

        //get function
        int getPoint();
        RegularDeck getRegularDeck();
        AbilityDeck getAbilityDeck();

        //set function
        void setPoint(int);
        void increasePointByScale(int);
        void increasePointByAmount(int);

};

#endif