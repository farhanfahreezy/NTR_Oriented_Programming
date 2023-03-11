#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <iostream>
using namespace std;

#include <Deck/RegularDeck.hpp>
#include <Deck/AbilityDeck.hpp>

class InventoryHolder {
    private:
        int point;
        RegularDeck regularDeck;
        AbilityDeck abilityDeck;
    public:
        //ctor
        InventoryHolder(int, int, int);

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