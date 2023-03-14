#include <iostream>
#include "InventoryHolder.hpp"

using namespace std;

// ctor
InventoryHolder::InventoryHolder(long long int poin, int n_regulardeck, int n_abilitydeck)
    : point(poin), regularInv(n_regulardeck), abilityInv(n_abilitydeck)
{}

// get functions
long long int InventoryHolder::getPoint() const {
    return point;
}

const vector<RegularCard>& InventoryHolder::getRegularInv() const{
    return regularInv;
}

const vector<AbilityCard>& InventoryHolder::getAbilityInv() const {
    return abilityInv;
}

int InventoryHolder::getRegularInvSize() const {
    return regularInv.size();
}

int InventoryHolder::getAbilityInvSize() const {
    return abilityInv.size();
}

// set functions
void InventoryHolder::setPoint(long long int num) {
    point = num;
}

void InventoryHolder::increasePointByScale(float scl) {
    point *= scl;
}

void InventoryHolder::increasePointByAmount(int num) {
    point += num;
}

long long int InventoryHolder::getMaxPoint(){
    return maxPoint;
}

// inventory functions
InventoryHolder InventoryHolder::operator+(const RegularCard& card) {
    this->addRegularCard(card);
    return *this;
}

InventoryHolder InventoryHolder::operator+(const AbilityCard& card) {
    this->addAbilityCard(card);
    return *this;
}

InventoryHolder InventoryHolder::operator-(const RegularCard& card) {
    this->removeRegularCard();
    return *this;
}

InventoryHolder InventoryHolder::operator-(const AbilityCard& card) {
    this->removeAbilityCard();
    return *this;
}

void InventoryHolder::addRegularCard(const RegularCard& card){
    regularInv.push_back(card);
}

void InventoryHolder::addAbilityCard(const AbilityCard& card){
    abilityInv.push_back(card);
}

void InventoryHolder::removeRegularCard() {regularInv.erase(regularInv.begin());}
void InventoryHolder::removeAbilityCard() {abilityInv.erase(abilityInv.begin());}

// void Remove
// std::vector<RegularCard> InventoryHolder::removeDuplicateNumbers(){
//     std::vector<RegularCard> tempInv;
//     for (int i = 0; i<getRegularInvSize() ; i++) {
//         if (i!= 0) {
//             if (regularInv[i].getNum()!=regularInv[i-1].getNum()) {
//                 tempInv.push_back(regularInv[i]);
//             } 
//         } else {
//             tempInv.push_back(regularInv[i]);
//         }
//     }
//     return tempInv;
// }


// int InventoryHolder::getFlushType() {
//     std::vector<int> count;
//     count.assign(4,0);
//     for (int i = 0; i<getRegularInvSize();i++) {
//         count[regularInv[i].getColor()]++;
//     }

//     for (int i = 0; i<count.size();i++) {
//         if (count[3-i]>=5) {
//             return i;
//         }
//     }
// }

// std::vector<RegularCard> InventoryHolder::removeOtherColor(int x) {
//     std::vector<RegularCard> tempInv;
//     for (int i = 0; i < getRegularInvSize(); i++) {
//         if (regularInv[i].getColor() == x) {
//             tempInv.push_back(regularInv[i]);
//         }
//     }
//     return tempInv;
// }


// bool InventoryHolder::compareCard(RegularCard c1, RegularCard c2){
//     return (c1.value() > c2.value());
// }


// std::vector<RegularCard> InventoryHolder::sortDeckByValue(){
//     std::vector<RegularCard> tempInv;
//     for (int i = 0;i<getRegularInvSize(); i++) {
//         tempInv.push_back(regularInv[i]);
//     }
//     sort(tempInv.begin(),tempInv.end(),compareCard);
//     return tempInv;
// }