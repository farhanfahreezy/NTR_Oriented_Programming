#include "Card.hpp"

Card::Card(string type){
    this->type = type;
}

string Card::getType(){
    return this->type;
}

void Card::printInfo(){
    cout << "Tipe kartu: " << this->getType() << endl;
}
