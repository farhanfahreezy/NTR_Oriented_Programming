#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP
#include <Card/Card.hpp>
#include <IO/File.hpp>

class AbilityCard: public Card{
    private:
        float id;
    public:
        AbilityCard();
        AbilityCard(float id);
        void setId(float id);
        void printInfo() override;
        float value() const override;

        void toFile(File::Write& writer) const;
        void fromFile(File::Read& reader);

        static const float
            ABILITY_REROLL_ID = 1,
            ABILITY_QUADRUPLE_ID = 2,
            ABILITY_QUARTER_ID = 3,
            ABILITY_REVERSE_ID = 4,
            ABILITY_SWAP_ID = 5,
            ABILITY_SWITCH_ID = 6,
            ABILITY_ABILITYLESS_ID = 7;
};
#endif