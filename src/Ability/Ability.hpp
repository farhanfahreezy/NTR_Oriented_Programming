#ifndef ABILITY_HPP
#define ABILITY_HPP
#include <Game/GameState.hpp>
#include <functional>
using namespace std;

typedef function<void()> Action;

class Ability{
    public:
        void get();
        Ability(int, Action);
    private:
        Action act;
        float id;
};
#endif