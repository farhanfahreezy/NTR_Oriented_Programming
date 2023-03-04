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
    cout << "Value: " << value() << endl;
}

float RegularCard::value(){
    float konstan = getNum() * 0.1;
    int colorValue;
    if(getColor() == "hijau"){
        colorValue = 0;
    }
    else if(getColor() == "biru"){
        colorValue = 1;
    }
    else if(getColor() == "kuning"){
        colorValue = 2;
    }
    else if(getColor() == "merah"){
        colorValue = 3;
    }
    return konstan + (colorValue*0.03);
}
// driver
/* int main(){
    RegularCard rc(9,"merah");
    rc.printInfo();
    rc.setColor("biru");
    rc.setNum(3);
    rc.printInfo();
    return 0;
} */