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
}

void AbilitySwitch::get() const {
     //// kerjain (bikin fungsi tambahan)
}

void AbilityAbilityless::get() const {
     //// kerjain (removeAbilityCard)
}