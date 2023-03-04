#include "AbilityDeck.hpp"

using namespace std;

AbilityDeck :: AbilityDeck() : Deck<AbilityCard>(0){
    this->amount = 0;
}

AbilityDeck :: AbilityDeck(int amount) : Deck<AbilityCard>(amount){
    float id = 1;
    for (int i = 0; i < amount; i++) {
        AbilityCard abCard(id);
        this->cards.push_back(abCard);
        id++;
    }
}

/*int main(){
    AbilityDeck abDeck(7);
    for(int i = 0; i < abDeck.getAmount(); i++){
        cout << abDeck.getCard(i) << endl;
    }
    cout <<"Shuffling" << endl;
    abDeck.shuffleDeck();
    for(int i = 0; i < abDeck.getAmount(); i++){
        cout << abDeck.getCard(i) << endl;
    }
}*/