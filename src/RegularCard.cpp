#include "RegularCard.hpp"

RegularCard::RegularCard(int num, string color): Card("Reg"){
    this->num = num;
    this->color = color;
}

int RegularCard::getNum(){
    return this->num;
}

string RegularCard::getColor(){
    return this->color;
}

void RegularCard::setNum(int num){
    this->num = num;
}

void RegularCard::setColor(string color){
    this->color = color;
}

void RegularCard::printInfo(){
    cout << "Kartu ini adalah " << getNum() << " " << getColor() <<endl;
}

// driver
/* int main(){
    RegularCard rc(9,"Merah");
    rc.printInfo();
    rc.setColor("Biru");
    rc.setNum(3);
    rc.printInfo();
    return 0;
} */