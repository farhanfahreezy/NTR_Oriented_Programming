#ifndef REGULARCARD_HPP
#define REGULARCARD_HPP 
#include <Card/Card.hpp>
#include <iostream>
#include <IO/File.hpp>
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
        RegularCard();
        RegularCard(int num, int color);
        int getNum() const;
        int getColor() const;
        string colorString();
        void setNum(int num);
        void setColor(int color);
        void printInfo() override;
        float value() const override;

        void toFile(File::Write& writer) const;
        void fromFile(File::Read& reader);

        static const float
            REGULAR_GREEN_COL,
            REGULAR_BLUE_COL,
            REGULAR_YELLOW_COL,
            REGULAR_RED_COL;
};
#endif