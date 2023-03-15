#include "GameCommands.hpp"
#include <iostream>
#include <Game/GameState.hpp>
#include <Game/GameAbility.hpp>
#include <IO/File.hpp>
using namespace std;

bool GameCommands::initialized = false;

#ifdef DEBUG_MODE
const Command
    GameCommands::COMMAND_WRITEFILE = Command::withName("write")
        .addArg("<path>", "Path to file to write to.")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 1)return false;
            string path = argv[0];

            cout << "Menulis GameState aktif ke file " << path << endl;
            File::Write fs(path);
            GameState::getCurrentState().toFile(fs);
            return true;
        }),
    
    GameCommands::COMMAND_READFILE = Command::withName("read")
        .addArg("<path>", "Path to file to read from.")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 1)return false;
            string path = argv[0];

            cout << "Membaca GameState dari file " << path << endl;
            File::Read fs(path);
            GameState::getCurrentState().fromFile(fs);
            return true;
        });
#endif

const Command
    GameCommands::COMMAND_NEXT = Command::withName("next")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;

            cout << "Giliran dilanjut ke permainan selanjutnya." << endl;
            return true;
        }),
    
    GameCommands::COMMAND_DOUBLE = Command::withName("double")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;
            
            GameState& state = GameState::getCurrentState();
            string name = state.getCurrentPlayer().getName();
            Table& table = state.getTable();

            long long oldPoint = table.getPoint();
            table.increasePointByScale(2.F);
            cout << name << " melakukan DOUBLE! Poin hadiah naik dari " << oldPoint << " menjadi " << table.getPoint() << "!" << endl;

            return true;
        }),
    
    GameCommands::COMMAND_HALF = Command::withName("half")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;

            GameState& state = GameState::getCurrentState();
            string name = state.getCurrentPlayer().getName();
            Table& table = state.getTable();

            long long oldPoint = table.getPoint();
            if(oldPoint > 1LL){
                table.increasePointByScale(.5F);
                cout << name << " melakukan HALF! Poin hadiah turun dari " << oldPoint << " menjadi " << table.getPoint() << "!" << endl;
            }else{
                cout << name << " melakukan HALF! Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
            }

            return true;
        }),
    
    /*GameCommands::COMMAND_REROLL = Command::withName("reroll")
        .handles([&](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;

            return true;
        }),*/
    
    GameCommands::COMMAND_REVERSE = Command::withName("reverse")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;

            /** TODO: Check if current player has a REVERSE ability card */
            AbilityReverse a;
            a.get();

            // The player keeps their turn after REVERSE-ing
            return false;
        });

void GameCommands::init(){
    if(initialized)return;
    
#ifdef DEBUG_MODE
    CommandParser::reg(COMMAND_WRITEFILE);
    CommandParser::reg(COMMAND_READFILE);
#endif

    CommandParser::reg(COMMAND_NEXT);
    CommandParser::reg(COMMAND_DOUBLE);
    CommandParser::reg(COMMAND_HALF);
    CommandParser::reg(COMMAND_REVERSE);

    initialized = true;
}
