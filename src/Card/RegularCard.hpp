#ifndef REGULARCARD_HPP
#define REGULARCARD_HPP 
#include "Card.hpp"
#include <iostream>
using namespace std;

class RegularCard: public Card{
    private:
        int num;
        int color;
        // hijau = 0;
        // biru = 1;
        // kuning = 2;
        // merah = 3;
    public:
        RegularCard(int num, int color);
        int getNum();
        int getColor();
        string colorString();
        void setNum(int num);
        void setColor(int color);
        void printInfo() override;
        float value() override;
};
#endif