#ifndef GAME_COMMANDS_HPP
#define GAME_COMMANDS_HPP

#include <IO/Command.hpp>
#include <IO/CommandParser.hpp>

class GameCommands{
    private:
        static bool initialized;
        static const Command
            COMMAND_DOUBLE,
            COMMAND_NEXT,
            COMMAND_HALF,
            COMMAND_ABILITY;
    public:
        /**
         * Initialize game commands.
        */
        static void init();
};

#endif
