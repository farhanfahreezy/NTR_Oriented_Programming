#ifndef GAME_COMMANDS_HPP
#define GAME_COMMANDS_HPP

#include <IO/Terminal/Command.hpp>
#include <IO/Terminal/CommandParser.hpp>

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
