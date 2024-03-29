#include "GameState.hpp"
#include <stack>
#include <IO/CommandParser.hpp>
#include <Game/GameCommands.hpp>
#include <Combo/Combo.hpp>
#include <Util/Vectors.hpp>

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
    Table &tables = currentState.getTable();
    int i = 0;
    while(state.getTable().getRegularInvSize()!=i){
        tables + state.getTable().getRegularInv().at(i);
        i++;
    }
}

Player& GameState::getCurrentPlayer(){
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

const int GameState::getFirstPlayerIdx() const{
    return ((gameNum - 1) * 7 + (round - 1)) % players.size();
}

void GameState::advance(){
    
    /** Get current player */
    currentPlayerIdx = turn.front();
    turn.pop();

    /** Wait for and call next command */
    getTable().printTableInfo();
    getPlayerWithId(currentPlayerIdx).printPlayerInfo();
    do cout << ":: " << getCurrentPlayer().getName() << "'s turn > "; while(!CommandParser::getNext());
    cout << endl;
    Table &tables = getTable();
    
    if(turn.empty()){
        /** End of round; initiate the next round */
        cout << "Akhir dari ronde ke-" << round << "!" << endl;

        ++round;
        turn = turnStartFrom(getFirstPlayerIdx());
        
        tables.pullCardToDisplay();
        if(round==2){
            cout << "Membagikan AbilityCard ke Player" << endl;
            shareAbilityCardToPlayers();
        }

        
    }

    if (round == 7) {
        /** Wrap up current game here */
        cout << "Akhir dari permainan ke-" << gameNum << "!" << endl;

        /** Award points */
        vector<Combo> combos;
        for(int i = 0; i < players.size(); ++i)
            combos.push_back(Combo(players.at(i).getRegularInv(), table.getRegularInv()));
        
        int maxPlayer;
        Vectors::max<Combo>(combos, maxPlayer);

        Player& pointWinner = getPlayerWithId(maxPlayer);
        cout
            << "Pemenang permainan ini adalah " << pointWinner.getName() << "!\n"
            << "Poin sebesar " << table.getPoint() << " diberikan kepada " << pointWinner.getName() << endl;
        pointWinner.setPoint(pointWinner.getPoint() + table.getPoint());

        if(pointWinner.getPoint() >= table.getMaxPoint()){
            /** End game if a player reaches point 1<<32 */
            cout << pointWinner.getName() << " menang! Permainan selesai" << endl;
            finished = true;
        }else{
            /** Reset players and the table */
            for(auto& p : players)
                p.setAbilityMati(false);
            cout << "Mengambil kartu Player" << endl;
            retractPlayersCard();
            cout << "Membagikan RegularCard ke Player" << endl;
            shareRegularCardToPlayers();
            tables.retractCardFromDisplay();

            /** Advance to the next game */
            ++gameNum;
            round = 1;
        }
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

void GameState::toFile(File::Write& writer) const{
    auto q = turn;
    writer << "# Informasi state permainan\n";
    writer << gameNum << ' ' << round << ' ' << currentPlayerIdx
        << ' ' << reversed << ' ' << finished
        << ' ' << players.size() << ' ' << q.size() << '\n';
    
    for(int i = 0; i < players.size(); ++i)
        players.at(i).toFile(writer);
    int size = q.size();
    for(int i = 0; i < size; ++i){
        writer << q.front();
        if(i < size - 1)writer << ' ';
        q.pop();
    }
    writer << '\n';
    table.toFile(writer);
}

void GameState::fromFile(File::Read& reader){
    string s;

    reader >> s;
    stringstream ss1(s);

    getline(ss1, s, ' ');
    gameNum = stoi(s);
    getline(ss1, s, ' ');
    round = stoi(s);
    getline(ss1, s, ' ');
    currentPlayerIdx = stoi(s);
    getline(ss1, s, ' ');
    reversed = stoi(s);
    getline(ss1, s, ' ');
    finished = stoi(s);
    getline(ss1, s, ' ');
    int pSize = stoi(s);
    getline(ss1, s, ' ');
    int qSize = stoi(s);

    for(; !turn.empty(); turn.pop());

    for(int i = 0; i < pSize; ++i){
        players.at(i).fromFile(reader);
    }
    
    reader >> s;
    stringstream ss2(s);
    for(int i = 0; i < qSize; ++i){
        getline(ss2, s, ' ');
        turn.push(stoi(s));
    }
    table.fromFile(reader);
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

void GameState::shareRegularCardToPlayers(RegularDeck regDeck){
    for(int i = 0; i<getNumberOfPlayer();i++){
        Player &player = this->getPlayerWithId(i);
        player + regDeck.getCard(0);player + regDeck.getCard(0);
    }
    while(regDeck.getAmount()!=0){
        Table &tables = this->getTable();
        tables + regDeck.getCard(0);
    }
}

void GameState::shareRegularCardToPlayers(){
    Table &tables = this->getTable();
    vector<RegularCard> &RegCard = tables.getRegularInvMod();
    Vectors::shuffle_vec<RegularCard>(RegCard);
    for(int i = 0; i<getNumberOfPlayer();i++){
        Player &player = this->getPlayerWithId(i);
        player + tables.getRegularInv().at(0);
        tables.removeRegularCard(0);
        player + tables.getRegularInv().at(0);
        tables.removeRegularCard(0);
    }
}

void GameState::shareAbilityCardToPlayers(){
    Table &tables = this->getTable();
    vector<AbilityCard> AbCard = tables.getAbilityInv();
    Vectors::shuffle_vec(AbCard);
    for(int i = 0; i<getNumberOfPlayer();i++){
        Player &player = this->getPlayerWithId(i);
        player + AbCard.at(i);
    }
}

void GameState::retractPlayersCard(){
    Table &tables = this->getTable();
    for(int i = 0; i<getNumberOfPlayer();i++){
        Player &player = this->getPlayerWithId(i);
        while(player.getRegularInvSize()!=0){
            tables + player.getRegularInv().at(0);
            player.removeRegularCard(0);
        }
        if(player.getAbilityInvSize()!=0){
            player.removeAbilityCard();
        }
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

bool GameState::isComplete(){
    return finished;
}