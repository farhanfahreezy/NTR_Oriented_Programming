#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>

#include <Deck/AbilityDeck.hpp>
#include <Deck/RegularDeck.hpp>
#include <InventoryHolder/InventoryHolder.hpp>

using namespace std;

class Player : public InventoryHolder{
    private:
        int id;
        string nama;
        int poin;
        bool abilityMati;
    public:
        /**
         * @brief Construct a new Player object
         * 
         * @param id id unik yang dimiliki player
         */
        Player(int id);
        Player();
        //cctor

        Player& operator=(const Player&);


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

        /**
         * Mengembalikan @c true jika pemain ini memiliki kartu ability dengan  id yang diberikan.
         * 
         * @param id Id kartu ability yang diperiksa.
        */
        bool hasAbilityCard(float id) const;

        string getName() const;

        int getId() const;

        bool getAbilityMati() const;
        void setAbilityMati(bool b);

        void toFile(File::Write& writer) const;
        void fromFile(File::Read& reader);
};
#endif