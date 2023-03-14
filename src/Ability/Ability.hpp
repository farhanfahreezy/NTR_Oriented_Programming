#ifndef ABILITY_HPP
#define ABILITY_HPP
#include <Game/GameState.hpp>
#include <functional>
using namespace std;

class Ability{
    public:
        virtual void get() const = 0;
};
#endif