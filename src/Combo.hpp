#ifndef COMBO_HPP
#define COMBO_HPP
#include "Value/Value.hpp"
#include "Table/Table.hpp"
#include "Player/Player.hpp"
#include <bits/stdc++.h>

class Combo : public Value{
    protected:
        float val;
    public:
        Combo();
        bool compareCard(RegularCard,RegularCard);
        bool isPair(Table,Player);
        bool isTwoPair(Table,Player);
        bool isThreeOfAKind(Table,Player);
        bool isStraight(Table,Player);
        bool isFlush(Table,Player);
        bool isFullHouse(Table,Player);
        bool isFourOfAKind(Table,Player);
        bool isStraightFlush(Table,Player);
        float value(Table,Player);
};
#endif