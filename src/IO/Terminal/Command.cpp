#include "Command.hpp"

Command::Command(string name, CommandHandle handle, map<string,string>& args):
    name(name), handle(handle), args(args){}

string Command::getName(){
    return name;
}

map<string,string> Command::getArgs(){
    return args;
}

bool Command::invoke(vector<string>& argv){
    return handle(argv);
}

Command::CommandBuilder Command::withName(string name){
    return Command::CommandBuilder(name);
}

Command::CommandBuilder::CommandBuilder(string name):
    name(name), args(){}

Command Command::CommandBuilder::handles(CommandHandle handle){
    return Command(name, handle, args);
}

Command::CommandBuilder& Command::CommandBuilder::addArg(string argname, string argdesc){
    auto existing = args.find(argname);
    if(existing == args.end()){
        args.insert(pair<string,string>(argname, argdesc));
    }
    return *this;
}
