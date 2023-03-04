#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>

#include "../AbilityDeck.hpp"
#include "../RegularDeck.hpp"

using namespace std;

class Player{
    private:
        int id;
        string nama;
        int poin;
        RegularDeck regularDeck;
        AbilityDeck abilityDeck;
    public:
        /**
         * @brief Construct a new Player object
         * 
         * @param id id unik yang dimiliki player
         */
        Player(int id);


        /**
         * @brief Operator pembanding point antara 2 object Player
         * 
         * @return true 
         * @return false 
         */
        bool operator<(const Player&) const;

        /**
         * @brief Operator pembanding point antara 2 object Player
         * 
         * @return true 
         * @return false 
         */
        bool operator>(const Player&) const;

        /**
         * @brief Operator pembanding point antara 2 object Player
         * 
         * @return true 
         * @return false 
         */
        bool operator==(const Player&) const;

        /**
         * @brief Set the Name object
         * 
         * @param newName nama untuk object Player
         */
        void setName(string newName);

        /**
         * @brief Menambah point pada atribut point Player
         * 
         * @param newPoin poin yang akan ditambahkan
         */
        void addPoin(int newPoin);


};
#endif