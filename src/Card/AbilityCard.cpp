#include "AbilityCard.hpp"
#include <iostream>
using namespace std;

AbilityCard ::AbilityCard(){
    this->id = 0;
}

AbilityCard::AbilityCard(float id){
    if(id>7 || id<1){
        throw invalid_argument("Ability salah\n");
    }
    else{
        this->id = id;
        // id = 1 (REROLL)
        // id = 2 (QUADRUPLE)
        // id = 3 (QUARTER)
        // id = 4 (REVERSE)
        // id = 5 (SWAP)
        // id = 6 (SWITCH)
        // id = 7 (ABILITYLESS)
    }
    
}

float AbilityCard::value(){
    return this->id;
}

void AbilityCard::setId(float id){
    this->id = id;
}

void AbilityCard::printInfo(){
    cout << "Id kartu ini adalah: ";
    if(value() == 1){
        cout << "Re-Roll" << endl;
    }
    else if(value() == 2){
        cout << "Quadruple" << endl;
    }
    else if(value() == 3){
        cout << "Quarter" << endl;
    }
    else if(value() == 4){
        cout << "Reverse Direction" << endl;
    }
    else if(value() == 5){
        cout << "Swap Card" << endl;
    }
    else if(value() == 6){
        cout << "Switch" << endl;
    }
    else if(value() == 7){
        cout << "Abilityless" << endl;
    }
    else{
        cout << "Id invalid" << endl;
    }
}

// driver
/* int main(){
    AbilityCard ac("Reverse");
    ac.printInfo();
    ac.setId("Switch");
    ac.printInfo();
    return 0;
} */