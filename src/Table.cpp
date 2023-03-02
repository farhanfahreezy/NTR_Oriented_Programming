#include "Table.hpp"

class Table {
        //ctor
        Table(){
            this->pot = 64;
            this->tableCards = new RegularDeck(5);
            this->drawCards = new RegularDeck(52);
            this->abilityDrawCards = new AbilityDeck(7);
        }

        //dtor
        ~Table(){
            delete this->tableCards;
            delete this->drawCards;
            delete this->abilityDrawCards;
        }

        //get function
        int getPotAmount(){
            return this->pot;
        }

        RegularDeck getTableDeck(){
            return this->tableCards
        }

        RegularDeck getDrawingDeck(){
            return this->drawCards;
        }

        AbilityDeck getabilityDrawingDeck(){
            return this->abilityDrawCards;
        }

        //set function
        void setPotAmount(int x){
            this->pot = x;
        }
        void setPotAmountByScale(int x){
            this->pot *= x;
        }
}