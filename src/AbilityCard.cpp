#include "AbilityCard.hpp"
#include <iostream>
using namespace std;

AbilityCard::AbilityCard(string desc): Card("Ability"){
    this->description = desc;
}

string AbilityCard::getDesc(){
    return this->description;
}

void AbilityCard::setDesc(string desc){
    this->description = desc;
}

void AbilityCard::printInfo(){
    cout << "Kegunaan kartu ini adalah: " << getDesc() << endl;
}

// driver
/* int main(){
    AbilityCard ac("Reverse");
    ac.printInfo();
    ac.setDesc("Switch");
    ac.printInfo();
    return 0;
} */