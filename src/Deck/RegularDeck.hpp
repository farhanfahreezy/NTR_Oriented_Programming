#ifndef REGULARDECK_HPP
#define REGULARDECK_HPP

#include <Deck/Deck.hpp>
#include <Card/RegularCard.hpp>

template<class T>
class RegularDeck : public Deck<RegularCard>{
    public:
        RegularDeck();
        RegularDeck(int amount);
        RegularDeck(const RegularDeck& other);
        void sortDeckByValue();
        bool compareCard(T, T);
        void removeCard(int);
        void removeDuplicateNumbers();
        int getFlushType();
        void removeOtherColor(int);
        
};

#endif