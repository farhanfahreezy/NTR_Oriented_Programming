#ifndef REGULARDECK_HPP
#define REGULARDECK_HPP

#include <Deck.hpp>
#include <../Card/RegularCard.hpp>

class RegularDeck : public Deck<RegularCard>{
    public:
        RegularDeck();
        RegularDeck(int amount);
};

#endif