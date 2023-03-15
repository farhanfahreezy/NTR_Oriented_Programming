#include <iostream>
#include <IO/Command.hpp>
#include <IO/CommandParser.hpp>
using namespace std;

int main(){
    string aegis = "aegis";
    Command
        CMD0 = Command::withName("hello")
            .handles([](vector<string>& argv)->bool{
                cout << "Hello!" << endl;
                return true;
            }),
        CMD1 = Command::withName("fullhello")
            .addArg("name", "")
            .addArg("age", "")
            .handles([](vector<string>& argv)->bool{
                if(argv.size() != 2)return false;
                cout << "Hello, " << argv.at(0) << ", you are " << argv.at(1) << " years old." << endl;
                return true;
            }),
        CMD2 = Command::withName("mod")
            .addArg("newval", "")
            .handles([&](vector<string>& argv)->bool{
                if(argv.size() != 1)return false;
                aegis = argv.at(0);
                return true;
            });
    
    CommandParser::reg(CMD0);
    CommandParser::reg(CMD1);
    CommandParser::reg(CMD2);
    cout << "Command: ";
    if(CommandParser::getNext()){
        cout << "Success!" << endl;
    }else{
        cout << "Failure!" << endl;
    }
    cout << "Aegis: " << aegis << endl;
    return 0;
}
