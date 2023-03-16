#ifndef GAME_COMMANDS_HPP
#define GAME_COMMANDS_HPP

#include <IO/Command.hpp>
#include <IO/CommandParser.hpp>

class GameCommands{
    private:
        static bool initialized;

#ifdef DEBUG_MODE
        static const Command
            COMMAND_WRITEFILE,
            COMMAND_READFILE;
#endif

        static const Command
            COMMAND_DOUBLE,
            COMMAND_NEXT,
            COMMAND_HALF,
            COMMAND_REROLL,
            COMMAND_QUADRUPLE,
            COMMAND_QUARTER,
            COMMAND_REVERSE,
            COMMAND_SWAP,
            COMMAND_SWITCH,
            COMMAND_ABILITYLESS;
    
    public:
        /**
         * Initialize game commands.
        */
        static void init();
};

#endif
