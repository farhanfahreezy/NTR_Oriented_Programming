#ifndef COMBO_HPP
#define COMBO_HPP
#include "Value/Value.hpp"
#include "Table/Table.hpp"
#include "Player/Player.hpp"
#include "Card/RegularCard.hpp"

class Combo: public Value{
    private:
        vector<RegularCard> com;
        vector<RegularCard> player;
        vector<RegularCard> table;
    public:
        Combo(vector<RegularCard>, vector<RegularCard>);
        vector<RegularCard> combineAndSortRegularCard();
        vector<RegularCard> sortByColor() const;
        vector<RegularCard> sortByValue(vector<RegularCard>) const;
        vector<RegularCard> HighCard() const; //oke
        vector<RegularCard> Pair() const; //oke
        vector<RegularCard> TwoPair() const; //oke
        vector<RegularCard> ThreeOfAKind() const; //oke
        vector<RegularCard> FourOfAKind() const; //oke
        vector<RegularCard> Straight() const; //oke
        vector<RegularCard> Flush() const; //oke
        vector<RegularCard> FullHouse() const; //oke
        vector<RegularCard> StraightFlush() const; //oke
        int getCombo() const;
        float value() const override;
        float TieBreaker() const;
        bool operator>(const Combo&) const;
        //yang menjerumus kalo ada kasus dimana ada lebih dari 1 pemain yang punya nilai tertinggi adalah flush dan straight flush
        //flush bisa ke straight, two pair, pair
        //straight flush bisa ke threes, two pair, sm pair
        //sisanya tinggal bandingin high card
};
#endif