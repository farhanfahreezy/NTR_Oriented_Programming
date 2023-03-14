#include "GameCommands.hpp"
#include <iostream>
#include <Game/GameState.hpp>
#include <Game/GameAbility.hpp>
using namespace std;

bool GameCommands::initialized = false;

const Command
    GameCommands::COMMAND_NEXT = Command::withName("next")
        .handles([&](vector<string>& argv)->bool{
            if(argv.size() == 0)return false;

            cout << "Melewati giliran pemain " << GameState::getCurrentState().getCurrentPlayer().getName() << endl;
            return true;
        }),
    
    GameCommands::COMMAND_DOUBLE = Command::withName("double")
        .handles([&](vector<string>& argv)->bool{
            if(argv.size() == 0)return false;
            
            GameState& state = GameState::getCurrentState();
            string name = state.getCurrentPlayer().getName();
            Table& table = state.getTable();

            if(table.getPoint() < 1 << 30){
                table.increasePointByScale(2);
                cout << "Pemain " << name << " menggandakan poin hadiah untuk ronde ini!" << endl;
                cout << "Poin hadiah sekarang adalah senilai " << table.getPoint() << endl;
            }else{
                cout << "Poin hadiah (" << table.getPoint() << ") sudah maksimal!" << endl;
                cout << "Melewati giliran pemain " << name << endl;
            }

            return true;
        }),
    
    GameCommands::COMMAND_HALF = Command::withName("half")
        .handles([&](vector<string>& argv)->bool{
            if(argv.size() == 0)return false;

            GameState& state = GameState::getCurrentState();
            string name = state.getCurrentPlayer().getName();
            Table& table = state.getTable();

            if(table.getPoint() > 1){
                table.increasePointByScale(.5f);
                cout << "Pemain " << name << " memperduakan poin hadiah untuk ronde ini!" << endl;
                cout << "Poin hadiah sekarang adalah senilai " << table.getPoint() << endl;
            }else{
                cout << "Poin hadiah (" << table.getPoint() << ") sudah minimal!" << endl;
                cout << "Melewati giliran pemain " << name << endl;
            }

            return true;
        });
    
    /*GameCommands::COMMAND_REROLL = Command::withName("reroll")
        .handles([&](vector<string>& argv)->bool{
            if(argv.size() == 0)return false;

            

            return true;
        });*/


void GameCommands::init(){
    if(initialized)return;
    
    CommandParser::reg(COMMAND_NEXT);
    CommandParser::reg(COMMAND_DOUBLE);
    CommandParser::reg(COMMAND_HALF);

    initialized = true;
}
