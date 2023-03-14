#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include <Card/RegularCard.hpp>
#include <Card/AbilityCard.hpp>

template<class T>
class Deck{
    protected:
        std :: vector<T> cards;
        int amount;

    public:
        Deck();
        Deck(int amount); //ctor
        Deck& operator=(const Deck&);
        T getCard(int idx); 
        int getAmount();
        void shuffleDeck();        
};

#endif