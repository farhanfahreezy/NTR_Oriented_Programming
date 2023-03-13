#ifndef COMBO_HPP
#define COMBO_HPP
#include "Value/Value.hpp"
#include "Deck/RegularDeck.hpp"

class Combo : public Value{
    protected:
        float val;
    public:
        Combo();
        bool isPair(RegularDeck);
        bool isTwoPair(RegularDeck);
        bool isThreeOfAKind(RegularDeck);
        bool isStraight(RegularDeck);
        bool isFlush(RegularDeck);
        bool isFullHouse(RegularDeck);
        bool isFourOfAKind(RegularDeck);
        bool isStraightFlush(RegularDeck);
        float value(RegularDeck);
};
#endif