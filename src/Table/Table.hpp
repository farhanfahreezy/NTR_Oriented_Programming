#ifndef TABLE_HPP
#define TABLE_HPP

#include <InventoryHolder/InventoryHolder.hpp>

class Table : public InventoryHolder{
    private:
        std::vector<RegularCard> tableDeck;
    public:
        //ctor
        Table();

        //cctor
        Table& operator=(Table&);

        //get function
        RegularCard getTableDeckCard(int);
        int getTableDeckSize();

        //set function
        void addToTableDeck(const RegularCard&);
        void resetPot();
};

#endif