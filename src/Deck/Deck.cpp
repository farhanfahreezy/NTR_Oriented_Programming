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
    return cards[idx];
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

template<class T>
bool Deck<T>::compareCard(T c1, T c2){
    return (c1.value > c2.value);
}

template<class T>
void Deck<T>::sortDeckByValue(){
    sort(cards.begin(),cards(end), compareCard);
}

template<class T>
void Deck<T>::removeCard(int i) {
    cards.erase(i);
    amount--;
}

template<class T>
void Deck<T>::removeDuplicateNumbers(){
    std::vector<int> tempvec;
    for (int i = 1; i<amount ; i++) {
        if (getCard(i).getNum()==getCard(i-1).getNum()) {
            tempvec.push_back(getCard(i).value());
        }
    }

    for (i = 0; i<tempvec.size(); i++) {
        for (int j = 0; j < amount; j++) {
            if (getCard(j).value() == tempvec[i]) {
                removeCard(j);
            }
        }
    }

}

template<class T>
int Deck<T>::getFlushType() {
    std::vector<int> count;
    count.assign(4,0);
    for (int i = 0; i<getAmount();i++) {
        count[getCard(i).getColor()]++;
    }

    for (int i = 0; i<count.size();i++) {
        if (count[3-i]>=5) {
            return i;
        }
    }
}

template<class T>
void Deck<T>::removeOtherColor(int i) {
    std::vector<int> tempvec;
    for (int i = 0; i < getAmount(); i++) {
        if (getCard(i).getColor() != i) {
            tempvec.push_back(getCard(i).value());
        }
    }

    for (i = 0; i<tempvec.size(); i++) {
        for (int j = 0; j < amount; j++) {
            if (getCard(j).value() == tempvec[i]) {
                removeCard(j);
            }
        }
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
