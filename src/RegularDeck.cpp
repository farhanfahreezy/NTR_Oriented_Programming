#include "RegularDeck.hpp"

using namespace std;

RegularDeck :: RegularDeck(int amount) : Deck(amount){
    this->cards.reserve(52);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            stringstream ss;
            if(i % 4 == 0){
                ss << "Hijau";
            }
            if(i % 4 == 1){
                ss << "Kuning";
            }
            if(i % 4 == 2){
                ss << "Biru";
            } 
            if(i % 4 == 3){
                ss << "Merah";
            }
            ss << " " << j + 1;
            string card = ss.str();
            this->cards.push_back(card);
        }
    }
    this->amount = this->cards.size();
}

/*int main(){
    RegularDeck regDeck(52);
    for(int i = 0; i < regDeck.getAmount(); i++){
        cout << regDeck.getCard(i) << endl;
    }
    cout <<"Shuffling" << endl;
    regDeck.shuffleDeck();
    for(int i = 0; i < regDeck.getAmount(); i++){
        cout << regDeck.getCard(i) << endl;
    }
}*/