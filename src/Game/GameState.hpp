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
};

#endif