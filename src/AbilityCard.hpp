#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP
#include "Card.hpp"

class AbilityCard: public Card{
    private:
        float id;
    public:
        AbilityCard(float id);
        void setId(float id);
        void printInfo();
        float value() override;
};
#endif