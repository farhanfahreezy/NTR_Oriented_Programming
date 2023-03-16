#ifndef CARD_HPP
#define CARD_HPP

#include <Value/Value.hpp>
#include <IO/File.hpp>
#include <iostream>
using namespace std;

class Card: public Value{
    public:
        virtual void printInfo() = 0;
        virtual void toFile(File::Write& writer) const = 0;
        virtual void fromFile(File::Read& reader) = 0;
};

#endif