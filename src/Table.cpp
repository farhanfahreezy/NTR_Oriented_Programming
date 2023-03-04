#include "Table.hpp"

class Table : private InventoryHolder{
        //ctor
        Table() : InventoryHolder(64,52,7){
            this->tableCards = new RegularDeck(5);
        }

        //dtor
        ~Table() : ~InventoryHolder(){
            delete this->tableCards;
        }

        //get function
        RegularDeck getTableDeck(){
            return this->tableDeck;
        }

        //set function
        void resetPot(){
            this.setPoint(64);
        }