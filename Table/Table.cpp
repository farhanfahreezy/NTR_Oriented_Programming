#include "Table.hpp"

//ctor
Table::Table() : InventoryHolder(64,52,7), tableDeck(5){
    //this->tableDeck = RegularDeck(5);
}


//get function
RegularDeck Table::getTableDeck(){
    return this->tableDeck;
}

//set function
void Table::resetPot(){
    InventoryHolder::setPoint(64);
}
