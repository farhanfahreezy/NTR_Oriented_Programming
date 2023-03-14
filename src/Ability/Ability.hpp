#ifndef ABILITY_HPP
#define ABILITY_HPP
#include <Game/GameState.hpp>
#include <functional>
using namespace std;

class Ability{
    public:
        GameState get(GameState);
        Ability(int, function<GameState,GameState>)
    private:
   
};
#endif