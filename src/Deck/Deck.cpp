#include "Deck.hpp"
#include <algorithm>

using namespace std;


template<class T>
Deck<T>::Deck() {
    this->amount = 0;
}

template<class T>
Deck<T>::Deck(int amount) {
    this->amount = amount;
}

template<class T>
T Deck<T>::getCard(int idx) {
    T tempCard = cards[idx];
    cards.erase(cards.begin()+idx);
    this->amount--;
    return tempCard;
}

template<class T>
int Deck<T>::getAmount() {
    return amount;
}

template<class T>
void Deck<T>::shuffleDeck(){
    srand(time(NULL));
    for(int i=amount-1; i>=0; i--){
        int j = rand() % (i+1);
        std::swap(cards[i], cards[j]);
    }
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

template class Deck<RegularCard>;
template class Deck<AbilityCard>;
