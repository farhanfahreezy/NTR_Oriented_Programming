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
    InventoryHolder operator+(const RegularCard& card); 
    InventoryHolder operator+(const AbilityCard& card);
    InventoryHolder operator-(const RegularCard& card);
    InventoryHolder operator-(const AbilityCard& card);
    void addRegularCard(const RegularCard& card);
    void addAbilityCard(const AbilityCard& card);
    void removeRegularCard();
    void removeAbilityCard();
    
};

#endif
