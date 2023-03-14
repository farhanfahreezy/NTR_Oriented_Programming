#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>
#include "Deck/RegularDeck.hpp"
#include "Deck/AbilityDeck.hpp"
#include "Card/RegularCard.hpp"
#include "Card/AbilityCard.hpp"

class InventoryHolder {
protected:
    int point;
    std::vector<RegularCard> regularInv;
    std::vector<AbilityCard> abilityInv;
public:
    // ctor
    InventoryHolder(int poin, int n_regulardeck, int n_abilitydeck);

    // dtor

    // get functions
    int getPoint() const;
    const std::vector<RegularCard>& getRegularInv() const ;
    const std::vector<AbilityCard>& getAbilityInv() const ;
    int getRegularInvSize() const;
    int getAbilityInvSize() const;

    // set functions
    void setPoint(int num);
    void increasePointByScale(float scl);
    void increasePointByAmount(int num);

    // inventory functions
    void addRegularCard(const RegularCard& card, int max);
    void addAbilityCard(const AbilityCard& card, int max);
    RegularCard removeRegularCard(int index);
    AbilityCard removeAbilityCard(int index);

    // std::vector<RegularCard> sortDeckByValue();
    // bool compareCard(RegularCard, RegularCard);
    // std::vector<RegularCard> removeDuplicateNumbers();
    // int getFlushType();
    // std::vector<RegularCard> removeOtherColor(int);
};

#endif
