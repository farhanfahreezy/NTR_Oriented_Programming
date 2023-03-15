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
};
#endif