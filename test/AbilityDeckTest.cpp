#include <iostream>
#include <AbilityDeck.hpp>
using namespace std;

int main(){
    AbilityDeck abDeck(7);
    for(int i = 0; i < abDeck.getAmount(); i++){
        auto card = abDeck.getCard(i);
        card.printInfo();
    }
}

