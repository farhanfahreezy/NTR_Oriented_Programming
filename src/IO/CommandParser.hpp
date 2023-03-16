#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <iostream>
#include <string>
#include <IO/Command.hpp>
using namespace std;

class CommandParser{
    private:
        static istream* is;
        static ostream* os;
        static map<string,Command> commands;
    
    public:
        /**
         * Change input stream to read from. Do not use unless necessary.
         * 
         * @param s New input stream to read from.
        */
        static void changeIn(istream& s);

        /**
         * Change output stream to write to. Do not use unless necessary.
         * 
         * @param s New output stream to write to.
        */
        static void changeOut(ostream& s);

        /**
         * Reads and parses the next command. Returns whether the input given is valid.
        */
        static bool getNext();

        /**
         * Registers this command into the parser, allowing it to be called.
         * 
         * @param command The command object.
        */
        static void reg(const Command& command);
};

#endif
