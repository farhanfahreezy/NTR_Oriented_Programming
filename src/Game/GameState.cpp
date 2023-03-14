#include "GameState.hpp"
#include <stack>

GameState::GameState(int n_players){
    for(int i = 0; i < n_players; turn.push(i++))players.insert(pair<int,Player>(i, Player(i)));
    ronde = 1;
}

GameState& GameState::getCurrentState(){
    return currentState;
}

const Player& GameState::getCurrentPlayer() const{
    return players.at(turn.front());
}

Table& GameState::getTable(){
    return table;
}

const int GameState::getRound() const{
    return ronde;
}

void GameState::advance(){
    /** Get current player */
    int id = turn.front();
    Player& current = players.at(id);

    /** TODO: Do stuff with current player */
    if (ronde == 1) {
        /** TODO: DOUBLE,NEXT, HALF
         *      BAGI KARTU ABILITY
        */
    } else {
        /** TODO: DOUBLE, NEXT, HALF, ABILITY*/
    }

    /** End of turn; rotate to next player */
    //turn.push(id);
    turn.pop();

    if (ronde == 6) {
        /** TODO: Wrap up */
    }

    currentState = *this;
}

void GameState::reverseTurn(){
    stack<int> temp;
    for(; !turn.empty(); turn.pop())temp.push(turn.front());
    for(; !temp.empty(); temp.pop())turn.push(temp.top());
}

std::ostream& operator<<(std::ostream& os, GameState& state){
    auto& turn = state.turn;
    
    for(int i = 0; i < turn.size(); ++i){
        int id = turn.front();
        os << id << " ";
        turn.push(id);
        turn.pop();
    }

    return os;
}
