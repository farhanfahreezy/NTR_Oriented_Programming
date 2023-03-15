#include "RegularCard.hpp"


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
    if(getColor() == 0){
        return "hijau";
    }
    else if(getColor() == 1){
        return "biru";
    }
    else if(getColor() == 2){
        return "kuning";
    }
    else if(getColor() == 3){
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
    cout << "Kartu ini adalah " << getNum() << " " << colorString() <<endl;
    cout << "Value: " << value() << endl;
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