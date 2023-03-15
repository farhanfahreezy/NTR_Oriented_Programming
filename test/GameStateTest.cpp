#include <Game/GameState.hpp>
#include <IO/File.hpp>
#include <iostream>

int main(){
    GameState state(7);
    GameState::setCurrentState(state);
    std::cout << GameState::getCurrentState() << std::endl;

    for(int i = 0; i < 7; ++i){
        GameState::getCurrentState().advance();
        std::cout << GameState::getCurrentState() << std::endl;
    }

    return 0;
}
