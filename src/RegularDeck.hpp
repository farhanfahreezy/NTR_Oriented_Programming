#ifndef REGULARDECK_HPP
#define REGULARDECK_HPP

#include "Deck.hpp"
#include "RegularCard.hpp"

template<class T>
class RegularDeck : public Deck<T>{
    public:
        RegularDeck();
        RegularDeck(int amount);
};

#endif