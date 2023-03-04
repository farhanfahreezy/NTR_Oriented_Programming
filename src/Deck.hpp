#ifndef DECK_HPP
#define DECK_HPP

#include "RegularCard.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

template<class T>
class Deck{
    protected:
        std :: vector<T> cards;
        int amount;

    public:
        Deck();
        Deck(int amount); //ctor
        Deck& operator=(const Deck&);
        virtual void shuffleDeck(); // shuffle deck
        std :: string getCard(int idx); 
        int getAmount();
};


#endif