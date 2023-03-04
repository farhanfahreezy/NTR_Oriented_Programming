#include "Deck.hpp"

using namespace std;

Deck :: Deck(int amount){
    {
        this->amount = amount;
    }
}

Deck& Deck::operator=(const Deck& other) {
    this->amount = amount;
    this->cards = other.cards;
    return *this;
}

void Deck :: shuffleDeck() {
    int n = this->amount;
    for (int i = n - 1; i > 0; i--) {
        srand(time(0));
        int j = rand() % (i + 1);
        string temp = this->cards[i];
        this->cards[i] = this->cards[j];
        this->cards[j] = temp;
    }
}

string Deck :: getCard(int idx){
    if(idx >= 0 && idx < this->amount){
        return this->cards[idx];
    } else{
        return "Invalid index";
    }
}

int Deck :: getAmount(){
    return this->amount;


}

/*int main(){
    Deck deck;
    for(int i = 0; i < deck.getAmount(); i++){
        cout << deck.getCard(i) << endl;
    }
    cout << "shuffling" << endl;
    deck.shuffleDeck();
    for(int i = 0; i < deck.getAmount(); i++){
        cout << deck.getCard(i) << endl;
    }
    
}*/