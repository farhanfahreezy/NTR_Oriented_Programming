#include "GameAbility.hpp"

using namespace std;

const Ability
    GameAbility::ABILITY_REROLL(1, [&](){
        //// kerjain (removeRegularCard, addRegularCard)
    }),
    GameAbility::ABILITY_QUADRUPLE(2, [&](){
        //// kerjain (increaseByScale(4))
    }),
    GameAbility::ABILITY_QUARTER(3, [&](){
        //// kerjain (increaseByScale(0.25))
    }),
    GameAbility::ABILITY_REVERSE(4, [&](){
        //// kerjain (reverseTurn())
    }),
    GameAbility::ABILITY_SWAP(5, [&](){
        //// kerjain (bikin fungsi tambahan)
    }),
    GameAbility::ABILITY_SWITCH(6, [&](){
        //// kerjain (bikin fungsi tambahan)
    }),
    GameAbility::ABILITY_ABILITYLESS(7, [&](){
        //// kerjain (removeAbilityCard)
    });