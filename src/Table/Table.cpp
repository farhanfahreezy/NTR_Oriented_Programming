#include "Table.hpp"

//ctor
Table::Table() : InventoryHolder(64,0,0), tableDeck(5){
    //this->tableDeck = RegularDeck(5);
}

Table& Table::operator=(Table& other) {
    for (int i = 0; i<other.getTableDeckSize();i++) {
        addToTableDeck(other.getTableDeckCard(i));
    }
    return *this;
}


//get function
RegularCard Table::getTableDeckCard(int x){
    return tableDeck[x];
}

int Table::getTableDeckSize(){
    return tableDeck.size();
}

//set function

void Table::addToTableDeck(const RegularCard& card){
    tableDeck.push_back(card);
}

void Table::resetPot(){
    InventoryHolder::setPoint(64);
}


