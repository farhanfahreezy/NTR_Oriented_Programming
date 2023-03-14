#include "CommandParser.hpp"
#include <sstream>
#include <vector>

istream* CommandParser::is = &cin;
ostream* CommandParser::os = &cout;
map<string,Command> CommandParser::commands;

void CommandParser::changeIn(istream& s){
    is = &s;
}

void CommandParser::changeOut(ostream& s){
    os = &s;
}

bool CommandParser::getNext(){
    string inp;
    getline(*is, inp);

    stringstream ss(inp);
    string name;
    vector<string> argv;

    string current;
    int i = 0;
    while(getline(ss, current, ' ')){
        if(i == 0)
            name = current;
        else
            argv.push_back(current);
        ++i;
    }

    auto toInvoke = commands.find(name);
    if(toInvoke != commands.end()){
        bool success = toInvoke->second.invoke(argv);
        return success;
    }
    return false;
}

void CommandParser::reg(Command& command){
    string name = command.getName();
    if(commands.find(name) != commands.end())commands.erase(name);
    commands.insert(pair<string,Command>(name, command));
}
