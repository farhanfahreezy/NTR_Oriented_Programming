#include <Game/GameState.hpp>
#include <iostream>

int main(){
    GameState state(7);
    GameState::setCurrentState(state);
    std::cout << state << std::endl;

    for(int i = 0; i < 7; ++i){
        state.advance();
        std::cout << state << std::endl;
    }

    return 0;
}
