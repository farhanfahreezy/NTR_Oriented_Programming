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

float AbilityCard::value() const{
    return this->id;
}

void AbilityCard::setId(float id){
    this->id = id;
}

void AbilityCard::printInfo(){
    cout << "Id kartu ini adalah: ";
    if(value() == ABILITY_REROLL_ID){
        cout << "Re-Roll" << endl;
    }
    else if(value() == ABILITY_QUADRUPLE_ID){
        cout << "Quadruple" << endl;
    }
    else if(value() == ABILITY_QUARTER_ID){
        cout << "Quarter" << endl;
    }
    else if(value() == ABILITY_REVERSE_ID){
        cout << "Reverse Direction" << endl;
    }
    else if(value() == ABILITY_SWAP_ID){
        cout << "Swap Card" << endl;
    }
    else if(value() == ABILITY_SWITCH_ID){
        cout << "Switch" << endl;
    }
    else if(value() == ABILITY_ABILITYLESS_ID){
        cout << "Abilityless" << endl;
    }
    else{
        cout << "Id invalid" << endl;
    }
}

void AbilityCard::toFile(File::Write& writer) const{
    writer << value() << '\n';
}
void AbilityCard::fromFile(File::Read& reader){
    string s;
    reader >> s;
    id = stof(s);
}

// driver
/* int main(){
    AbilityCard ac("Reverse");
    ac.printInfo();
    ac.setId("Switch");
    ac.printInfo();
    return 0;
} */