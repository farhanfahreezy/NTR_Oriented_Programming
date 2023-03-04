#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
using namespace std;

class Card{
    protected:
        string type; //reg atau ability
    public:
        Card(string type);
        string getType();
        void printInfo();
};

#endif