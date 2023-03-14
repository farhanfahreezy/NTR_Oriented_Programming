#include <Game/GameState.hpp>
#include <iostream>

int main(){
    GameState state(7);
    std::cout << state << std::endl;

    state.advance();
    std::cout << state << std::endl;

    state.reverseTurn();
    std::cout << state << std::endl;

    state.advance();
    std::cout << state << std::endl;

    return 0;
}
