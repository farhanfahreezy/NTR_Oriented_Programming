#ifndef COMBO_HPP
#define COMBO_HPP
#include "Value/Value.hpp"
#include "Table/Table.hpp"
#include "Player/Player.hpp"
#include "Card/RegularCard.hpp"

class Combo{
    private:
        float val;
        vector<RegularCard> combined;
    public:
        Combo();
        vector<RegularCard> combineAndSortRegularCard(vector<RegularCard>, vector<RegularCard>);
        vector<RegularCard> sortByColor(vector<RegularCard>);
        vector<RegularCard> sortByValue(vector<RegularCard>);
        vector<RegularCard> HighCard(vector<RegularCard>); //oke
        vector<RegularCard> Pair(vector<RegularCard>); //oke
        vector<RegularCard> TwoPair(vector<RegularCard>); //oke
        vector<RegularCard> ThreeOfAKind(vector<RegularCard>); //oke
        vector<RegularCard> FourOfAKind(vector<RegularCard>); //oke
        vector<RegularCard> Straight(vector<RegularCard>); //oke
        vector<RegularCard> Flush(vector<RegularCard>); //oke
        vector<RegularCard> FullHouse(vector<RegularCard>); //oke
        vector<RegularCard> StraightFlush(vector<RegularCard>); //oke
        float value(vector<RegularCard>, vector<RegularCard>, vector<RegularCard>);
};
#endif