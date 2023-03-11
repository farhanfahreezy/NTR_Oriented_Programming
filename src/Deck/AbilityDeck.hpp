#ifndef ABILITYDECK_HPP
#define ABILITYDECK_HPP

#include <Deck/Deck.hpp>

class AbilityDeck : public Deck<AbilityCard>{
    public:
        AbilityDeck();
        AbilityDeck(int amount);
};

#endif