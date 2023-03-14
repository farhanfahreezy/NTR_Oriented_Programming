#include "RegularDeck.hpp"

using namespace std;

template<class T>
RegularDeck<T> :: RegularDeck() : Deck(0){
    this->amount = 0;
}

template<class T>
RegularDeck<T> :: RegularDeck(int amount) : Deck(amount){
    this->amount = amount;
    for(int i =0; i < amount; i++){
        RegularCard regCard((i%13) + 1, i%4);
        this->cards.push_back(regCard);
    }
}

template<class T>
RegularDeck<T> :: RegularDeck(const RegularDeck& other){
    this->amount = other.amount;
    for(int i = 0; i < other.amount ; i++){
        RegularCard* card = new RegularCard(other.cards[i].getNum(), other.cards[i].getColor());
        this->cards.push_back(*card);
    }
}
template<class T>
void RegularDeck<T>::removeCard(int i) {
    cards.erase(cards.begin()+i);
    amount--;
}

template<class T>
void RegularDeck<T>::removeDuplicateNumbers(){
    std::vector<int> tempvec;
    for (int i = 1; i<amount ; i++) {
        if (getCard(i).getNum()==getCard(i-1).getNum()) {
            tempvec.push_back(getCard(i).value());
        }
    }

    for (int i = 0; i<tempvec.size(); i++) {
        for (int j = 0; j < amount; j++) {
            if (getCard(j).value() == tempvec[i]) {
                removeCard(j);
            }
        }
    }

}

template<class T>
int RegularDeck<T>::getFlushType() {
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
void RegularDeck<T>::removeOtherColor(int i) {
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

template<class T>
bool RegularDeck<T>::compareCard(T c1, T c2){
    return (c1.value() > c2.value());
}

template<class T>
void RegularDeck<T>::sortDeckByValue(){
    sort(cards.begin(),cards.end(), compareCard);
}
