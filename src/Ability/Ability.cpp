#include "Ability.hpp"

Ability::Ability(int i, Action act){
    this->act = act;
    this->id = i;
}

void Ability::get(){
    act();
}