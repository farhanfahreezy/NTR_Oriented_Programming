#include <iostream>
#include <Deck/RegularDeck.hpp>
using namespace std;

int main(){
    RegularDeck regDeck(52);
    for(int i = 0; i < regDeck.getAmount(); i++){
        auto card = regDeck.getCard(i);
        card.printInfo();
    }
    /*cout <<"Shuffling" << endl;
    regDeck.shuffleDeck();
    for(int i = 0; i < regDeck.getAmount(); i++){
        auto card = regDeck.getCard(i);
        card.printInfo();
    }*/
}