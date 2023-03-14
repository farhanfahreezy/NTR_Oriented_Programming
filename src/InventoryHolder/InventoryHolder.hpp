#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>
#include "Deck/RegularDeck.hpp"
#include "Deck/AbilityDeck.hpp"
#include "Card/RegularCard.hpp"
#include "Card/AbilityCard.hpp"

class InventoryHolder {
protected:
    unsigned long point;
    unsigned long const maxPoint = 1UL << 32;
    std::vector<RegularCard> regularInv;
    std::vector<AbilityCard> abilityInv;
public:
    // ctor
    InventoryHolder(unsigned long poin, int n_regulardeck, int n_abilitydeck);

    // dtor

    // get functions
    unsigned long getPoint() const;
    const std::vector<RegularCard>& getRegularInv() const ;
    const std::vector<AbilityCard>& getAbilityInv() const ;
    int getRegularInvSize() const;
    int getAbilityInvSize() const;

    // set functions
    void setPoint(unsigned long num);
    void increasePointByScale(float scl);
    void increasePointByAmount(int num);

    // inventory functions
    InventoryHolder operator+(const RegularCard& card) const; 
    InventoryHolder operator+(const AbilityCard& card) const;
    InventoryHolder operator-(const RegularCard& card) const;
    InventoryHolder operator-(const AbilityCard& card) const;
    /*void addRegularCard(const RegularCard& card, int max);
    void addAbilityCard(const AbilityCard& card, int max);
    RegularCard removeRegularCard(int index);
    AbilityCard removeAbilityCard(int index);*/
};

#endif
