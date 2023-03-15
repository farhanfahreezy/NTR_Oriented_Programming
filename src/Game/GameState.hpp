#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <queue>
#include <map>
#include <iostream>
#include <Player/Player.hpp>
#include <Table/Table.hpp>

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
        const Player& getCurrentPlayer() const;

        /**
         * @brief Get the Player With Id
         * 
         * @return const Player& 
         */
        const Player& getPlayerWithId(int id) const;

        /**
         * Getter for the game table.
        */
        Table& getTable();

        /**
         * Getter for the game round.
        */
        const int getRound() const;

        /**
         * Advances the game to the next state.
         * 
         * TODO: Do turn actions and calls here
        */
        void advance();

        /**
         * Reverses the order of player turn.
        */
        void reverseTurn();

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

    private:
        // Queue containing player IDs. The player with their ID at the queue head goes first.
        std::queue<int> turn;

        // List of all players in the game.
        std::map<int,Player> players;

        // Whether the game is finished or not.
        bool finished;

        // The game table.
        Table table;

        // Ronde Permainan
        int ronde;

        // Current active state of the game
        static GameState& currentState;

        // Default non-functional game state
        static GameState defaultState;
};

#endif