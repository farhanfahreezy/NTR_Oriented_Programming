#ifndef CARD_HPP
#define CARD_HPP

#include "Value.hpp"
#include <iostream>
using namespace std;

class Card: public Value{
    public:
        virtual void printInfo() = 0;
};

#endif