#include "Table.hpp"

//ctor
Table::Table() : InventoryHolder(64,0,7), tableDeck(5){
    for(int i = 1; i<8; i++){
        AbilityCard ac(i);
        addAbilityCard(ac);
    }
    
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

void Table::toFile(File::Write& writer) const{
    writer << "# Informasi table\n";
    InventoryHolder::toFile(writer);
    writer << "## TABLE\n";
    writer << tableDeck.size() << '\n';
    for(int i = 0; i < tableDeck.size(); ++i)
        tableDeck.at(i).toFile(writer);
}

void Table::fromFile(File::Read& reader){
    InventoryHolder::fromFile(reader);
    string s;
    reader >> s;
    int tblSize = stoi(s);

    tableDeck.clear();
    for(int i = 0; i < tblSize; ++i){
        RegularCard c;
        c.fromFile(reader);
        tableDeck.push_back(c);
    }
}


