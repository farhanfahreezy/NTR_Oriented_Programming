#include "RegularCard.hpp"

const float
    RegularCard::REGULAR_GREEN_COL = 0.F,
    RegularCard::REGULAR_BLUE_COL = 1.F,
    RegularCard::REGULAR_YELLOW_COL = 2.F,
    RegularCard::REGULAR_RED_COL = 3.F;

RegularCard::RegularCard() {
    this->num = 0;
    this->color = 0;
}
RegularCard::RegularCard(int num, int color){
    if((num > 13 || num < 0) || (color < 0 || color > 3)){
        throw invalid_argument("Nomor atau warna anda salah.\n");
    }
    else{
        this->num = num;
        this->color = color;
    }
    
}

int RegularCard::getNum() const{
    return this->num;
}

int RegularCard::getColor() const{
    return this->color;
}

string RegularCard::colorString(){
    if(getColor() == REGULAR_GREEN_COL){
        return "hijau";
    }
    else if(getColor() == REGULAR_BLUE_COL){
        return "biru";
    }
    else if(getColor() == REGULAR_YELLOW_COL){
        return "kuning";
    }
    else if(getColor() == REGULAR_RED_COL){
        return "merah";
    } else {
        return "unknown";
    }
}

void RegularCard::setNum(int num){
    this->num = num;
}

void RegularCard::setColor(int color){
    this->color = color;
}

void RegularCard::printInfo(){
    cout << getNum() << " " << colorString() <<endl;
}

float RegularCard::value() const{
    float konstan = getNum() * 0.1;
    return konstan + (getColor() * 0.03);
}

void RegularCard::toFile(File::Write& writer) const{
    writer << value() << '\n';
}
void RegularCard::fromFile(File::Read& reader){
    string s;
    reader >> s;
    float f = stof(s);
    setNum(f * 10);
    setColor((f - getNum() * 0.1) / 0.03);
}
// driver
/* int main(){
    RegularCard rc(9,1);
    rc.printInfo();
    rc.setColor(3);
    rc.setNum(3);
    rc.printInfo();
    return 0;
} */