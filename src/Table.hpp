#ifndef TABLE_HPP
#define TABEL_HPP

#include "InventoryHolder.hpp"

class Table : private InventoryHolder{
    private:
        RegularDeck tableDeck;
    public:
        //ctor
        Table();

        //dtor
        ~Table();

        //get function

        RegularDeck getTableDeck();

        //set function
        void resetPot();
}

#endif