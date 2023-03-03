#ifndef INVENTORYHOLDER_H
#define INVENTORYHOLDER_H

#include <iostream>
using namespace std;

#include "RegularDeck.hpp"
#include "AbilityDeck.hpp"

<template T>
class InventoryHolder {
    private:
        T point;
        RegularDeck regularDeck;
        AbilityDeck abilityDeck;
    public:
        //ctor
        InventoryHolder(int, int, int);

        //dtor
        ~InventoryHolder();

        //get function
        T getPoint();
        RegularDeck getDrawingDeck();
        AbilityDeck getabilityDrawingDeck();

        //set function
        void setPoint(int);
        void increasePointByScale(int);
        void increasePointByAmount(int);

}

#endif