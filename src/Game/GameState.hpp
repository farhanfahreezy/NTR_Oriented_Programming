#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <queue>
#include <map>
#include <iostream>
#include <Player/Player.hpp>
#include <Table/Table.hpp>
#include <IO/File.hpp>
#include <InventoryHolder/InventoryHolder.hpp>
#include <Util/Vectors.hpp>

class GameState{
    public:
        /**
         * Creates an initial game state.
         * 
         * @param n_players The number of players.
        */
        GameState(int n_players);

        /**
         * Gets the current active state of the game.
        */
        static GameState& getCurrentState();

        /**
         * Sets the current active state of the game.
        */
        static void setCurrentState(GameState& state);

        /**
         * Gets the current active player.
        */
        Player& getCurrentPlayer();

        /**
         * @brief Get the player with the given id.
         * 
         * @return const Player& 
         */
        Player& getPlayerWithId(int id);

        /**
         * Gets a copy of the player turn queue for this round.
        */
        std::queue<int> getCurrentTurnQueue() const;

        /**
         * Getter for the game table.
        */
        Table& getTable();

        /**
         * Getter for the game number.
        */
        const int getGameNum() const;

        /**
         * Getter for the game round.
        */
        const int getRound() const;

        /**
         * Returns the index of the player that should play first this round.
        */
        const int getFirstPlayerIdx() const;

        /**
         * Advances the game to the next state.
        */
        void advance();

        /**
         * Reverses the order of player turn.
        */
        void reverseTurn();

        /**
         * Gets the new turn order starting with the given player.
         * 
         * @param start Index of the first player to play.
        */
        std::queue<int> turnStartFrom(int start) const;

        /**
         * Prints a string representation of this game state to an output stream.
         * 
         * @param os        The output stream to write into.
         * @param state     The state to write from.
        */
        friend std::ostream& operator<<(std::ostream& os, GameState& state);

        /**
         * Return the number of players active in the game
         * 
        */
        int getNumberOfPlayer();

        /**
         * @brief Set the Name Player object
         * 
         */
        void setPlayersName();

        /**
         * @brief Bagiin kartu regular ke player, kartu dari RegularDeck
         * 
         */
        void shareRegularCardToPlayers(RegularDeck regDeck);

        /**
         * @brief Bagiin kartu regular ke player, kartu dari table
         * 
         */
        void shareRegularCardToPlayers();

        /**
         * @brief Bagiin kartu Ability ke player, kartu dari table
         * 
         */
        void shareAbilityCardToPlayers();

        /**
         * @brief Ambil semua kartu yang dimiliki player
         * 
         */
        void retractPlayersCard();

        /**
         * @brief Print all players with their cards
         * 
         */
        void printAllPlayers();

        /**
         * Writes this object's attributes into a file.
        */
        void toFile(File::Write& writer) const;

        /**
         * Reads values for this object's attributes from a file.
        */
        void fromFile(File::Read& reader);

        /**
         * Check if any player have point greater than MAXPOINT
         * 
         */
        bool isComplete();

    private:
        // Queue containing player IDs. The player with their ID at the queue head goes first.
        std::queue<int> turn;

        // List of all players in the game.
        std::vector<Player> players;

        // Whether the game is finished or not.
        bool finished;

        // The game table.
        Table table;

        // Game number.
        int gameNum;

        // Game round in the current game.
        int round;

        // Index of the current player to go.
        int currentPlayerIdx;

        // Whether turn is reversed.
        bool reversed;

        // Current active state of the game.
        static GameState& currentState;

        // Default non-functional game state.
        static GameState defaultState;
};

#endif
