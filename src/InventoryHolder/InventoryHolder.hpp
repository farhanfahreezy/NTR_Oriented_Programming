#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>
#include "Deck/RegularDeck.hpp"
#include "Deck/AbilityDeck.hpp"
#include "Card/RegularCard.hpp"
#include "Card/AbilityCard.hpp"

class InventoryHolder {
protected:
    long long int point;
    static const long long int maxPoint = 1LL<<32;
    std::vector<RegularCard> regularInv;
    std::vector<AbilityCard> abilityInv;
public:
    // ctor
    InventoryHolder(long long int poin, int n_regulardeck, int n_abilitydeck);

    // dtor

    // get functions
    long long int getPoint() const;
    const std::vector<RegularCard>& getRegularInv() const ;
    const std::vector<AbilityCard>& getAbilityInv() const ;
    int getRegularInvSize() const;
    int getAbilityInvSize() const;

    // set functions
    void setPoint(long long int num);
    void increasePointByScale(float scl);
    void increasePointByAmount(int num);
    long long int getMaxPoint();

    // inventory functions
    InventoryHolder operator+(const RegularCard& card); 
    InventoryHolder operator+(const AbilityCard& card);
    InventoryHolder operator-(int amount);
    void addRegularCard(const RegularCard& card);
    void addAbilityCard(const AbilityCard& card);
    void removeRegularCard(int amount);
    void removeAbilityCard();
    
};

#endif
