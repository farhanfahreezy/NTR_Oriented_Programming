#ifndef COMBO_HPP
#define COMBO_HPP
#include "Value/Value.hpp"

class Combo : public Value{
    protected:
        float value;
    public:
        Combo();
        bool isPair();
        bool isTwoPair();
        bool isThreeOfAKind();
        bool isStraight();
        bool isFlush();
        bool isFullHouse();
        bool isFourOfAKind();
        bool isStraightFlush();
        float value();
};
#endif