#include "AbilityDeck.hpp"

using namespace std;

AbilityDeck :: AbilityDeck() : Deck(0){
    this->amount = 0;
}

AbilityDeck :: AbilityDeck(int amount) : Deck(amount){
    /*for (int i = 0; i < amount; i++) {
        std::string ability;
        switch (i % 7) {
            case 0:
                ability = "Re-Roll";
                break;
            case 1:
                ability = "Quadruple";
                break;
            case 2:
                ability = "Quarter";
                break;
            case 3:
                ability = "Reverse Direction";
                break;
            case 4:
                ability = "Swap Card";
                break;
            case 5:
                ability = "Switch";
                break;
            case 6:
                ability = "Abilityless";
                break;
        }
        this->cards.push_back(ability);
    }*/
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