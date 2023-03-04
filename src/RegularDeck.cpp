#include "RegularDeck.hpp"

using namespace std;

template<class RegularCard>
RegularDeck<RegularCard> :: RegularDeck() : Deck<RegularCard>(0){
    this->amount = 0;
}

template<class RegularCard>
RegularDeck<RegularCard> :: RegularDeck(int amount) : Deck<RegularCard>(amount){
    this->amount = amount;
    for(int i =0; i < amount; i++){
        RegularCard regCard;
        if(i%4 == 0){
            regCard = RegularCard(i, "Hijau");
        }
        if(i%4 == 1){
            regCard = RegularCard(i, "Biru");
        }
        if(i%4 == 2){
            regCard = RegularCard(i, "Kuning");
        }
        if(i%4 == 3){
            regCard = RegularCard(i, "Merah");
        }
        this->cards.push_back(regCard);
    }
}

int main(){
    RegularDeck<RegularCard> regDeck(52);
    for(int i = 0; i < regDeck.getAmount(); i++){
        cout << regDeck.getCard(i) << endl;
    }
    cout <<"Shuffling" << endl;
    regDeck.shuffleDeck();
    for(int i = 0; i < regDeck.getAmount(); i++){
        cout << regDeck.getCard(i) << endl;
    }
}