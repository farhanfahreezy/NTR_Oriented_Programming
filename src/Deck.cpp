#include "Deck.hpp"

using namespace std;

Deck :: Deck(){
    {
        this->cards.reserve(52);

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 13; j++){
                stringstream ss;
                if(i % 4 == 0){
                    ss << "Hijau";
                }
                if(i % 4 == 1){
                    ss << "Kuning";
                }
                if(i % 4 == 2){
                    ss << "Biru";
                } 
                if(i % 4 == 3){
                    ss << "Merah";
                }
                ss << " " << j + 1;
                string card = ss.str();
                this->cards.push_back(card);
            }
        }
        this->amount = this->cards.size();
    }
}

void Deck :: shuffleDeck() {
    int n = this->amount;
    for (int i = n - 1; i > 0; i--) {
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