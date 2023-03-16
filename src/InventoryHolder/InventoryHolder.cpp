#include <iostream>
#include <sstream>
#include "InventoryHolder.hpp"

using namespace std;

// ctor
InventoryHolder::InventoryHolder(long long int poin, int n_regulardeck, int n_abilitydeck)
    : point(poin), regularInv(n_regulardeck), abilityInv(n_abilitydeck)
{}

//cctor
InventoryHolder& InventoryHolder::operator=(const InventoryHolder& other) {
    for (int i = 0; i<other.getRegularInvSize();i++) {
        addRegularCard(other.getRegularInv()[i]);
    }

    for (int i = 0; i<other.getAbilityInvSize();i++) {
        addAbilityCard(other.getAbilityInv()[i]);
    }

    return *this;
}

// get functions
long long int InventoryHolder::getPoint() const {
    return point;
}

const vector<RegularCard>& InventoryHolder::getRegularInv() const{
    return regularInv;
}

vector<RegularCard>& InventoryHolder::getRegularInvMod(){
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

InventoryHolder InventoryHolder::operator-(int amount) {
    if (amount > regularInv.size()) {
        // handle the case where the player has less than 'amount' regular cards in their inventory
        regularInv.clear();
    } else {
        // remove 'amount' regular cards from the player's inventory
        this->removeRegularCard(amount);
        if(this->getAbilityInvSize() == 1){
            this->removeAbilityCard();
        }
    }
    return *this;
}



void InventoryHolder::addRegularCard(const RegularCard& card){
    regularInv.push_back(card);
}

void InventoryHolder::addAbilityCard(const AbilityCard& card){
    abilityInv.push_back(card);
}

void InventoryHolder::removeRegularCard(int amount) {
    // if(amount > regularInv.size()) {
    //     amount = regularInv.size();
    // }
    // for(int i = 0; i < amount; i++){
    //     regularInv.erase(regularInv.begin());
    // }
    regularInv.erase(regularInv.begin()+amount);
}

void InventoryHolder::removeAbilityCard() {abilityInv.erase(abilityInv.begin());}

void InventoryHolder::toFile(File::Write& writer) const{
    writer << "## INV-HOLDER\n";
    writer << point << ' ' << regularInv.size() << ' ' << abilityInv.size() << '\n';
    for(int i = 0; i < regularInv.size(); ++i)
        regularInv.at(i).toFile(writer);
    for(int i = 0; i < abilityInv.size(); ++i)
        abilityInv.at(i).toFile(writer);
}

void InventoryHolder::fromFile(File::Read& reader){
    string s;

    reader >> s;
    stringstream ss(s);
    getline(ss, s, ' ');
    point = stoll(s);
    getline(ss, s, ' ');
    int regSize = stoi(s);
    getline(ss, s, ' ');
    int ablSize = stoi(s);

    regularInv.clear();
    abilityInv.clear();
    for(int i = 0; i < regSize; ++i){
        RegularCard c;
        c.fromFile(reader);
        regularInv.push_back(c);
    }
    for(int i = 0; i < ablSize; ++i){
        AbilityCard c;
        c.fromFile(reader);
        abilityInv.push_back(c);
    }
}

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