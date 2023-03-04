#ifndef REGULARCARD_HPP
#define REGULARCARD_HPP 
#include "Card.hpp"
#include <iostream>
using namespace std;

class RegularCard: public Card{
    private:
        int num;
        string color;
    public:
        RegularCard(int num, string color);
        RegularCard& operator=(const RegularCard&);
        int getNum();
        string getColor();
        void setNum(int num);
        void setColor(string color);
        void printInfo();
        float value();
};
#endif