#ifndef COMBO_HPP
#define COMBO_HPP
#include "Value/Value.hpp"
#include "Table/Table.hpp"
#include "Player/Player.hpp"
#include "Game/GameState.hpp"
#include <bits/stdc++.h>

class Combo : public Value{
    protected:
        float val;
        Table tbl;
        Player p;
    public:
        Combo(Table, Player);
        void setPlayer(Player);
        bool compareCard(RegularCard,RegularCard);
        bool isPair();
        bool isTwoPair();
        bool isThreeOfAKind();
        bool isStraight();
        bool isFlush();
        bool isFullHouse();
        bool isFourOfAKind();
        bool isStraightFlush();
        float value();
        int getCombo();
        Player getWinner(GameState);
};
#endif