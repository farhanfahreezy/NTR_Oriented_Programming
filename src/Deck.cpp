#include "Deck.hpp"

using namespace std;


template<class T>
Deck<T>::Deck() {
    amount = 0;
}

template<class T>
Deck<T>::Deck(int amount) {
    this->amount = amount;
}

template<class T>
void Deck<T>::shuffleDeck() {
    std::random_shuffle(cards.begin(), cards.end());
}

template<class T>
std::string Deck<T>::getCard(int idx) {
    std::ostringstream oss;
    oss << cards[idx];
    return oss.str();
}

template<class T>
int Deck<T>::getAmount() {
    return amount;
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