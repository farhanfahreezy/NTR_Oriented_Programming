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
        RegularCard regCard(i, i%4);
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