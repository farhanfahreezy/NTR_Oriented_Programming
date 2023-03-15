#include "GameAbility.hpp"

using namespace std;

void AbilityReroll::get() const {
    //// kerjain (removeRegularCard, addRegularCard)
}

void AbilityQuadruple::get() const {
    //// kerjain (increaseByScale(4))
    GameState& state = GameState::getCurrentState();
    string name = state.getCurrentPlayer().getName();
    Table& table = state.getTable();
    int tmp = table.getPoint();

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
    Table& table = state.getTable();
    int tmp = table.getPoint();

    if(tmp > 2){
        if(table.getPoint() < table.getMaxPoint()){
            table.increasePointByScale(0.25);
            cout << "Pemain " << name << " melakukan QUARTER! Poin hadiah turun dari " << tmp << " menjadi " << table.getPoint() << "!" << endl;
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

    state.reverseTurn();
    auto
        newTurn = state.getCurrentTurnQueue(),
        nextRoundTurn = state.turnStartFrom((state.getGameNum() - 1) * 7 + state.getRound());
    
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
    GameState& state = GameState::getCurrentState();
    Player currentPlayer = state.getCurrentPlayer();
    Table& table = state.getTable();

    int p1 = -1;
    int p2 = -1;
    cout << "Masukkan Player 1 yang ingin diswap kartunya!" << endl;
    while(p1 <= 0 || p1 > 7 || p1 == currentPlayer.getId()){
        cout << "Id Player 1 : ";
        cin >> p1;
    }
    cout << "Masukkan Player 2 yang ingin diswap kartunya!" << endl;
    while(p2 <= 0 || p2 > 7 || p2 == currentPlayer.getId() || p2 == p1){
        cout << "Id Player 2 : ";
        cin >> p2;
    }

    Player pl1 = state.getPlayerWithId(p1);
    Player pl2 = state.getPlayerWithId(p2);
    RegularCard temp1 = pl1.getRegularInv().at(0);
    RegularCard temp2 = pl2.getRegularInv().at(0);

    //pl1 - temp1;

}

void AbilitySwitch::get() const {
     //// kerjain (bikin fungsi tambahan)
}

void AbilityAbilityless::get() const {
     //// kerjain (removeAbilityCard)
}