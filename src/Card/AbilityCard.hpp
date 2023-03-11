#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP
#include <Card/Card.hpp>

class AbilityCard: public Card{
    private:
        float id;
    public:
        AbilityCard(float id);
        void setId(float id);
        void printInfo() override;
        float value() override;
};
#endif