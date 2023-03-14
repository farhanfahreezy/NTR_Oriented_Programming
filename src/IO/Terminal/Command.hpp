#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <functional>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef function<bool(vector<string>&)> CommandHandle;

class Command{
    private:
        string name;
        CommandHandle handle;
        map<string,string> args;

    public:
        /**
         * Creates a command object. Not intended for direct use; use a CommandBuilder object instead.
         * 
         * @param name Name of this command, to invoke by.
         * @param handle The function to be called.
         * @param args Name of expected arguments.
        */
        Command(string name, CommandHandle handle, map<string,string>& args);

        /**
         * Getter for command name.
        */
        string getName();

        /**
         * Getter for command argument list.
        */
        map<string,string> getArgs();

        /**
         * Invoke this command with the given arguments. Returns whether invocation is successful.
         * 
         * @param argv Argument values to be supplied.
        */
        bool invoke(vector<string>& argv);

        class CommandBuilder{
            private:
                string name;
                map<string,string> args;
            
            public:
                /**
                 * Creates a command builder object with the given name.
                 * 
                 * @param name Name of the command.
                */
                CommandBuilder(string name);

                /**
                 * Constructs the command object.
                 * 
                 * @param handle The function to be called.
                */
                Command handles(CommandHandle handle);

                /**
                 * Adds an expected argument at the end of this command.
                 * 
                 * @param argname Name of the argument.
                 * @param argdesc Description of the argument.
                */
                CommandBuilder& addArg(string argname, string argdesc);
        };
        
        /**
         * Returns an object to construct commands.
         * 
         * @param name Name of the command to be constructed.
        */
        static CommandBuilder withName(string name);
};

#endif
