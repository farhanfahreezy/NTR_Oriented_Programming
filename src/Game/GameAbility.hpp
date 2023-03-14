#ifndef GAMEABILITY_HPP
#define GAMEABILITY_HPP
#include <Ability/Ability.hpp>
using namespace std;

class GameAbility{
    public:
        static const Ability
            ABILITY_REROLL,
            ABILITY_QUADRUPLE,
            ABILITY_QUARTER,
            ABILITY_REVERSE,
            ABILITY_SWAP,
            ABILITY_SWITCH,
            ABILITY_ABILITYLESS;
};
#endif