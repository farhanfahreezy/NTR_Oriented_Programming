#ifndef TABLE_HPP
#define TABLE_HPP

#include <InventoryHolder/InventoryHolder.hpp>

class Table : public InventoryHolder{
    private:
        RegularDeck<int> tableDeck;
    public:
        //ctor
        Table();

        //get function

        RegularDeck<int> getTableDeck();

        //set function
        void resetPot();
        void resetTableDeck();
};

#endif