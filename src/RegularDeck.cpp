#include "RegularDeck.hpp"

using namespace std;

RegularDeck :: RegularDeck() : Deck(0){
    this->amount = 0;
}

RegularDeck :: RegularDeck(int amount) : Deck(amount){
    this->amount = amount;
    for(int i =0; i < amount; i++){
        RegularCard regCard(i, i%4);
        this->cards.push_back(regCard);
    }
}
