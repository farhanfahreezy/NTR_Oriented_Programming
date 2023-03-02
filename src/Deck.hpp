#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

class Deck{
    private:
        std :: vector<std::string> cards;
        int amount;

    public:
        Deck(); //ctor

        void shuffleDeck(); // shuffle deck
        std :: string getCard(int idx); 
        int getAmount();
};


#endif