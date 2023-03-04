#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

class Deck{
    protected:
        std :: vector<std::string> cards;
        int amount;

    public:
        Deck(int amount); //ctor
        Deck& operator=(const Deck&);
        virtual void shuffleDeck(); // shuffle deck
        std :: string getCard(int idx); 
        int getAmount();
};


#endif