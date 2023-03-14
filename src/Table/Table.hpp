#ifndef TABLE_HPP
#define TABLE_HPP

#include <InventoryHolder/InventoryHolder.hpp>

class Table : public InventoryHolder{
    private:
        std::vector<RegularCard> tableDeck;
    public:
        //ctor
        Table();

        //get function

        RegularCard getTableDeck(int);
        int getTableDeckSize();

        //set function
        void resetPot();
};

#endif