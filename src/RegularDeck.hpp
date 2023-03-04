#ifndef REGULARDECK_HPP
#define REGULARDECK_HPP

#include "Deck.hpp"

class RegularDeck : public Deck{
    public:
        RegularDeck(int amount);
        RegularDeck& operator=(const RegularDeck&);
};

#endif