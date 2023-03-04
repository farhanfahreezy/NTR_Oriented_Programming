#ifndef TABLE_HPP
#define TABEL_HPP

#include "InventoryHolder.hpp"

class Table : public InventoryHolder{
    private:
        RegularDeck tableDeck;
    public:
        //ctor
        Table();

        //get function

        RegularDeck getTableDeck();

        //set function
        void resetPot();
};

#endif