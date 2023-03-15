#include "GameState.hpp"
#include <stack>
#include <IO/CommandParser.hpp>
#include <Game/GameCommands.hpp>

GameState GameState::defaultState = GameState(0);
GameState& GameState::currentState = GameState::defaultState;

GameState::GameState(int n_players){
    for(int i = 0; i < n_players; turn.push(i++))players.insert(pair<int,Player>(i, Player(i)));
    gameNum = 1;
    round = 1;
    finished = false;
    reversed = false;
}

GameState& GameState::getCurrentState(){
    return currentState;
}

void GameState::setCurrentState(GameState& state){
    currentState = state;
}

const Player& GameState::getCurrentPlayer() const{
    cout << turn.front() << " yang lagi main sekarang njir" << endl;
    return players.at(turn.front());
}

const Player& GameState::getPlayerWithId(int id) const{
    return players.at(id);
}

Table& GameState::getTable(){
    return table;
}

const int GameState::getRound() const{
    return round;
}

void GameState::advance(){
    /** TEMP: FOR TESTING PURPOSES ONLY, DELETE THIS LATER */
    GameCommands::init();

    /** Get current player */
    int id = turn.front();
    Player& current = players.at(id);

    /** TODO: Do stuff with current player */
    //if (round == 1) {
    //    /** TODO: DOUBLE,NEXT, HALF
    //     *      BAGI KARTU ABILITY
    //    */
    //} else {
    //    /** TODO: DOUBLE, NEXT, HALF, ABILITY*/
    //}

    /** Wait for and call next command */
    cout << "> ";
    bool succ = CommandParser::getNext();
    cout << (succ ? "Lemao gan" : "Ish nub") << endl;

    /** End of turn; rotate to next player */
    turn.pop();

    if(turn.empty()){
        /** End of round; initiate the next round */
        /** TODO: Wrap up current round: award points, etc. */
        ++round;
        int
            first = (gameNum - 1) * 7 + (round - 1),
            i = first;
        do{
            turn.push(i);
            i = (!reversed ? i + 1 : i - 1) % players.size();
        }while(i != first);
    }

    if (round == 7) {
        ++gameNum;
        round = 1;

        /** TODO: Wrap up current game: determine the winner or advance to the next game */
    }

    currentState = *this;
}

void GameState::reverseTurn(){
    reversed = !reversed;

    stack<int> temp;
    for(; !turn.empty(); turn.pop())temp.push(turn.front());
    for(; !temp.empty(); temp.pop())turn.push(temp.top());
}

std::ostream& operator<<(std::ostream& os, GameState& state){
    os << "game: " << state.gameNum << ", round: " << state.round << endl;

    os << "turn: [";
    auto& turn = state.turn;
    for(int i = 0; i < turn.size(); ++i){
        int id = turn.front();
        os << id;
        if(i < turn.size() - 1)os << " ";
        turn.push(id);
        turn.pop();
    }
    os << "]";

    return os;
}
