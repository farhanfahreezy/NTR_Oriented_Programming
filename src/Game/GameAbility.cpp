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
    GameState::getCurrentState().reverseTurn();
}

void AbilitySwap::get() const {
     //// kerjain (bikin fungsi tambahan)
    GameState& state = GameState::getCurrentState();
    Player currentPlayer = state.getCurrentPlayer();
    Table& table = state.getTable();

    cout << currentPlayer.getName() << "melakukan SWAPCARD" << endl;

    int p1 = -1;
    int p2 = -1;
    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
    map<int, Player>::iterator it;
    int idx = 1;
    for(int i = 1;i<8;i++){
        if(i!=currentPlayer.getId()){
            cout << "  " << idx << ". " << state.getPlayerWithId(i).getName() << endl;
            idx++;
        }
    }
    while(p1 <= 0 || p1 > 7 || p1 == currentPlayer.getId()){
        cout << "> ";
        cin >> p1;
    }
    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
    idx = 1;
    for(int i = 1;i<8;i++){
        if(i!=currentPlayer.getId()){
            cout << "  " << idx << ". " << state.getPlayerWithId(i).getName() << endl;
            idx++;
        }
    }
    while(p2 <= 0 || p2 > 7 || p2 == currentPlayer.getId() || p2 == p1){
        cout << "> ";
        cin >> p2;
    }

    Player pl1 = state.getPlayerWithId(p1);
    Player pl2 = state.getPlayerWithId(p2);
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

    pl1 - 1;
    pl2 - 1;

    pl1 + temp2;
    pl2 + temp1;
}

void AbilitySwitch::get() const {
     //// kerjain (bikin fungsi tambahan)
}

void AbilityAbilityless::get() const {
     //// kerjain (removeAbilityCard)
}