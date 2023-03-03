#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP
#include "Card.hpp"

class AbilityCard: public Card{
    private:
        string description;
    public:
        AbilityCard(string desc);
        string getDesc();
        void setDesc(string desc);
        void printInfo();
};
#endif