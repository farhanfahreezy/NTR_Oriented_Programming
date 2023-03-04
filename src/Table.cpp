#include "Table.hpp"
#include "InventoryHolder.hpp"

//ctor
Table::Table() : InventoryHolder(64,52,7){
    this->tableDeck = new RegularDeck(5);
}

//dtor
Table::~Table(){
    delete tableDeck;
}

//get function
RegularDeck Table::getTableDeck(){
    return this->tableDeck;
}

//set function
void Table::resetPot(){
    InventoryHolder::setPoint(64);
}
