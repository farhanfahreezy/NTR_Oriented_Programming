#ifndef GAMEABILITY_HPP
#define GAMEABILITY_HPP
#include <Ability/Ability.hpp>
#include <Game/GameState.hpp>
#include <InventoryHolder/InventoryHolder.hpp>
using namespace std;

class AbilityReroll: public Ability{
    public:
        void get() const override;
};
class AbilityQuadruple: public Ability{
    public:
        void get() const override;
};
class AbilityQuarter: public Ability{
    public:
        void get() const override;
};
class AbilityReverse: public Ability{
    public:
        void get() const override;
};
class AbilitySwap: public Ability{
    public:
        void get() const override;
};
class AbilitySwitch: public Ability{
    public:
        void get() const override;
};
class AbilityAbilityless: public Ability{
    public:
        void get() const override;
};
#endif