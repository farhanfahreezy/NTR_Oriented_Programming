#include "RegularDeck.hpp"

using namespace std;

RegularDeck :: RegularDeck() : Deck(0){
    this->amount = 0;
}

RegularDeck :: RegularDeck(int amount) : Deck(amount){
    this->amount = amount;
    for(int i =0; i < amount; i++){
        RegularCard regCard((i%13) + 1, i%4);
        this->cards.push_back(regCard);
    }
}

RegularDeck :: RegularDeck(const RegularDeck& other){
    this->amount = other.amount;
    for(int i = 0; i < other.amount ; i++){
        RegularCard* card = new RegularCard(other.cards[i].getNum(), other.cards[i].getColor());
        this->cards.push_back(*card);
    }
}

