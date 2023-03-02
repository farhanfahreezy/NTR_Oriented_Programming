#ifndef TABLE_HPP
#define TABLE_HPP

#include "RegularDeck.hpp"
#include "AbilityDeck.hpp"

class Table {
    private:
        int pot;
        RegularDeck tableDeck;
        RegularDeck drawDeck;
        AbilityDeck abilityDrawDeck;
    public:
        //ctor
        Table();

        //dtor
        ~Table();

        //get function
        int getPotAmount();
        RegularDeck getTableDeck();
        RegularDeck getDrawingDeck();
        AbilityDeck getabilityDrawingDeck();

        //set function
        void setPotAmount(int);
        void setPotAmountByScale(int);
};

#endif