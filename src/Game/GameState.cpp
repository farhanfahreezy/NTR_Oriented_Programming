#include "GameState.hpp"
#include <stack>
#include <IO/CommandParser.hpp>
#include <Game/GameCommands.hpp>

GameState GameState::defaultState = GameState(0);
GameState& GameState::currentState = GameState::defaultState;

GameState::GameState(int n_players) : table() {
    for(int i = 0; i < n_players; turn.push(i++))players.push_back(Player(i));
    gameNum = 1;
    round = 1;
    finished = false;
    reversed = false;
    currentPlayerIdx = turn.front();
}

GameState& GameState::getCurrentState(){
    return currentState;
}

void GameState::setCurrentState(GameState& state){
    currentState = state;
}

const Player& GameState::getCurrentPlayer() const{
    return players.at(currentPlayerIdx);
}

Player& GameState::getPlayerWithId(int id){
    return players.at(id);
}

std::queue<int> GameState::getCurrentTurnQueue() const{
    return turn;
}

Table& GameState::getTable(){
    return table;
}

const int GameState::getGameNum() const{
    return gameNum;
}

const int GameState::getRound() const{
    return round;
}

void GameState::advance(){
    /** TEMP: FOR TESTING PURPOSES ONLY, MOVE THIS LATER TO MAIN PROGRAM */
    GameCommands::init();

    /** Get current player */
    currentPlayerIdx = turn.front();
    turn.pop();

    /** Wait for and call next command */
    do cout << "|| Player " << currentPlayerIdx << " >> "; while(!CommandParser::getNext());

    if(turn.empty()){
        /** End of round; initiate the next round */
        /** TODO: Wrap up current round here: award points, etc. */

        ++round;
        turn = turnStartFrom((gameNum - 1) * 7 + (round - 1));
    }

    if (round == 7) {
        ++gameNum;
        round = 1;

        /** TODO: Wrap up current game here: determine the winner or advance to the next game */
    }
}

void GameState::reverseTurn(){
    reversed = !reversed;

    if(turn.size() > 1){
        stack<int> temp;
        for(; !turn.empty(); turn.pop())temp.push(turn.front());
        for(; !temp.empty(); temp.pop())turn.push(temp.top());
    }
}

std::queue<int> GameState::turnStartFrom(int start) const{
    std::queue<int> turnQueue;
    int i = start;
    do{
        turnQueue.push(i);
        i = (!reversed ? i + 1 : i - 1);
        i = (i < 0 ? i + players.size() : i) % players.size();
    }while(i != start);
    return turnQueue;
}

// map<int,Player>& GameState::getPlayerList(){
//     return this->players;
// }

std::ostream& operator<<(std::ostream& os, GameState& state){
    os << "game: " << state.gameNum << ", round: " << state.round << ", reversed: " << state.reversed;

    os << ", turn: [";
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

int GameState::getNumberOfPlayer(){
    return players.size();
}

void GameState::setPlayersName(){
    for(int i = 0; i<getNumberOfPlayer();i++){
        cout << "Masukkan nama Player ke-" << i+1 << ":" << endl;
        cout << "  > ";
        string name;
        cin >> name;
        Player &player = this->getPlayerWithId(i);
        player.setName(name);
    }
    cout << endl;

}

void GameState::shareRegularCardToPlayers(){
    RegularDeck regDeck(52);
    regDeck.shuffleDeck();
    for(int i = 0; i<getNumberOfPlayer();i++){
        Player &player = this->getPlayerWithId(i);
        player + regDeck.getCard(0);player + regDeck.getCard(0);
    }
    while(regDeck.getAmount()!=0){
        RegularCard temp = regDeck.getCard(0);
        table.addRegularCard(temp);
    }
}

void GameState::printAllPlayers(){
    for(int i = 0; i<getNumberOfPlayer();i++){
        cout << "Player " << i+1 <<": "<< getPlayerWithId(i).getName() << endl;
        getPlayerWithId(i).printPlayerInfo();
        cout << endl;
    }
    cout << endl;
}