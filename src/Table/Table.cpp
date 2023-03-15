#include "Table.hpp"

//ctor
Table::Table() : InventoryHolder(64,0,0), tableDeck(5){
    //this->tableDeck = RegularDeck(5);
}


//get function
RegularCard Table::getTableDeck(int x){
    return tableDeck[x];
}

int Table::getTableDeckSize(){
    return tableDeck.size();
}

//set function
void Table::resetPot(){
    InventoryHolder::setPoint(64);
}

