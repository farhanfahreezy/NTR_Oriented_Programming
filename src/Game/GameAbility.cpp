#include "GameAbility.hpp"

using namespace std;

void AbilityReroll::get() const {
    //// kerjain (removeRegularCard, addRegularCard)
    GameState& state = GameState::getCurrentState();
    Player currentPlayer = state.getCurrentPlayer();
    Table& table = state.getTable();
    cout << currentPlayer.getName() << " melakukan Re-Roll!" << endl;

    Player &player = state.getPlayerWithId(currentPlayer.getId());
    
    table + player.getRegularInv().at(0);
    player.removeRegularCard(0);
    table + player.getRegularInv().at(0);
    player.removeRegularCard(0);

    player + table.getRegularInv().at(0);
    table.removeRegularCard(0);
    player + table.getRegularInv().at(0);
    table.removeRegularCard(0);


}

void AbilityQuadruple::get() const {
    //// kerjain (increaseByScale(4))
    GameState& state = GameState::getCurrentState();
    string name = state.getCurrentPlayer().getName();
    Table& table = state.getTable();
    int tmp = table.getPoint();
    Player currentPlayer = state.getCurrentPlayer();
    cout << currentPlayer.getName() << " melakukan Quadruple!" << endl;

    if(tmp>=table.getMaxPoint()){
        cout << "Poin hadiah (" << table.getPoint() << ") sudah maksimal!" << endl;
        cout << "Melewati giliran pemain " << name << endl;
    }
    else if(tmp < table.getMaxPoint()/4){
        table.increasePointByScale(4);
        cout << "Pemain " << name << " melakukan QUADRUPLE! Poin hadiah naik dari " << tmp << " menjadi " << table.getPoint() << "!" << endl;
    }
    else {
        table.setPoint(table.getMaxPoint());
        cout << "Pemain " << name << " melakukan QUADRUPLE! Poin hadiah naik dari " << tmp << " menjadi " << table.getPoint() << "!" << endl;
    }   
}

void AbilityQuarter::get() const {
     //// kerjain (increaseByScale(0.25))
    GameState& state = GameState::getCurrentState();
    string name = state.getCurrentPlayer().getName();
    cout << "Pemain " << name << " melakukan Quarter!" << endl;
    Table& table = state.getTable();
    int tmp = table.getPoint();

    if(tmp > 2){
        if(table.getPoint() < table.getMaxPoint()){
            table.increasePointByScale(0.25);
            cout << "Poin hadiah turun dari " << tmp << " menjadi " << table.getPoint() << "!" << endl;
        }else{
            cout << "Poin hadiah (" << table.getPoint() << ") sudah maksimal!" << endl;
            cout << "Melewati giliran pemain " << name << endl;
        }
    }else{
        table.setPoint(1);
        cout << "Pemain " << name << " melakukan QUARTER! Poin hadiah turun dari " << tmp << " menjadi 1!" << endl;
    }
}

void AbilityReverse::get() const {
    GameState& state = GameState::getCurrentState();
    string name = state.getCurrentPlayer().getName();
    Table& table = state.getTable();
    Player currentPlayer = state.getCurrentPlayer();
    cout << currentPlayer.getName() << " melakukan Reverse!" << endl;

    state.reverseTurn();
    auto
        newTurn = state.getCurrentTurnQueue(),
        nextRoundTurn = state.turnStartFrom((state.getFirstPlayerIdx() + 1) % state.getNumberOfPlayer());
    
    cout << name << " melakukan reverse!" << endl;
    cout << "Sisa urutan eksekusi ronde ini : ";
    while(!newTurn.empty()){
        cout << newTurn.front() << " ";
        newTurn.pop();
    }
    cout << endl << "Urutan eksekusi ronde selanjutnya : ";
    while(!nextRoundTurn.empty()){
        cout << nextRoundTurn.front() << " ";
        nextRoundTurn.pop();
    }
    cout << endl;
}

void AbilitySwap::get() const {
     //// kerjain (bikin fungsi tambahan)
    GameState &state = GameState::getCurrentState();
    Player currentPlayer = state.getCurrentPlayer();
    cout << currentPlayer.getName() << " melakukan Swapcard!" << endl;

    int p1 = -1;
    int p2 = -1;

    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
    for(int i = 0;i<state.getNumberOfPlayer();i++){
        if(i!=currentPlayer.getId()){
            cout << "  " << i+1 << ". " << state.getPlayerWithId(i).getName() << endl;
        }
    }
    while(p1 < 0 || p1 > state.getNumberOfPlayer()-1 || p1 == currentPlayer.getId()){
        cout << "> ";
        cin >> p1;
        p1--;
    }

    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
    for(int i = 0;i<state.getNumberOfPlayer();i++){
        if(i!=currentPlayer.getId() && i!=p1){
            cout << "  " << i+1 << ". " << state.getPlayerWithId(i).getName() << endl;
        }
    }

    while(p2 < 0 || p2 > state.getNumberOfPlayer()-1 || p2 == currentPlayer.getId() || p2 == p1){
        cout << "> ";
        cin >> p2;
        p2--;
    }
    
    Player &pl1 = state.getPlayerWithId(p1);
    Player &pl2 = state.getPlayerWithId(p2);
    int pil1 = 0;
    int pil2 = 0;


    cout << "Silakan pilih kartu kanan/kiri " << pl1.getName() << endl;
    cout << "  1. Kanan" << endl << "  2. Kiri" << endl;
    while(pil1 <= 0 || pil1 > 2 ){
        cout << "> ";
        cin >> pil1;
    }

    cout << "Silakan pilih kartu kanan/kiri " << pl2.getName() << endl;
    cout << "  1. Kanan" << endl << "  2. Kiri" << endl;
    while(pil2 <= 0 || pil2 > 2 ){
        cout << "> ";
        cin >> pil2;
    }

    RegularCard temp1 = pl1.getRegularInv().at(pil1-1);
    RegularCard temp2 = pl2.getRegularInv().at(pil2-1);

    pl1 - (pil1-1);
    pl2 - (pil2-1);

    pl1 + temp2;
    pl2 + temp1;
}

void AbilitySwitch::get() const {
     //// kerjain (bikin fungsi tambahan)
    GameState &state = GameState::getCurrentState();
    Player currentPlayer = state.getCurrentPlayer();
    cout << currentPlayer.getName() << " melakukan Switch!" << endl;

    int p1 = -1;

    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
    for(int i = 0;i<state.getNumberOfPlayer();i++){
        if(i!=currentPlayer.getId()){
            cout << "  " << i+1 << ". " << state.getPlayerWithId(i).getName() << endl;
        }
    }
    while(p1 < 0 || p1 > state.getNumberOfPlayer()-1 || p1 == currentPlayer.getId()){
        cout << "> ";
        cin >> p1;
        p1--;
    }

    Player &pl1 = state.getPlayerWithId(currentPlayer.getId());
    Player &pl2 = state.getPlayerWithId(p1);

    RegularCard tempP11 = pl1.getRegularInv().at(0);
    RegularCard tempP12 = pl1.getRegularInv().at(1);
    RegularCard tempP21 = pl2.getRegularInv().at(0);
    RegularCard tempP22 = pl2.getRegularInv().at(1);

    pl1 - 0;pl1 - 0;pl2 - 0;pl2 - 0;
    pl1 + tempP21;
    pl1 + tempP22;
    pl2 + tempP11;
    pl2 + tempP12;
}

void AbilityAbilityless::get() const {
     //// kerjain (removeAbilityCard)
    GameState &state = GameState::getCurrentState();
    Player currentPlayer = state.getCurrentPlayer();
    cout << currentPlayer.getName() << " melakukan AbilityLess!" << endl;

    int p1 = -1;

    cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
    for(int i = 0;i<state.getNumberOfPlayer();i++){
        if(i!=currentPlayer.getId()){
            cout << "  " << i+1 << ". " << state.getPlayerWithId(i).getName() << endl;
        }
    }
    while(p1 < 0 || p1 > state.getNumberOfPlayer()-1 || p1 == currentPlayer.getId()){
        cout << "> ";
        cin >> p1;
        p1--;
    }

    Player &player = state.getPlayerWithId(p1);
    player.setAbilityMati(false);
}