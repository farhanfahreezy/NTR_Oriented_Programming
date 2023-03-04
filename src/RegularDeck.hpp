#ifndef REGULARDECK_HPP
#define REGULARDECK_HPP

#include <Deck.hpp>
#include <RegularCard.hpp>

class RegularDeck : public Deck<RegularCard>{
    public:
        RegularDeck();
        RegularDeck(int amount);
};

#endif