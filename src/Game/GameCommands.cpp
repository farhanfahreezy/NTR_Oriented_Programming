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
            if(argv.size() != 1){
                cout << "Tidak ada path yang diberikan!" << endl;
                return false;
            }
            string path = argv[0];

            cout << "Menulis GameState aktif ke file " << path << endl;
            File::Write fs(path);
            GameState::getCurrentState().toFile(fs);
            return false;
        }),
    
    GameCommands::COMMAND_READFILE = Command::withName("read")
        .addArg("<path>", "Path to file to read from.")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 1){
                cout << "Tidak ada path yang diberikan!" << endl;
                return false;
            }
            string path = argv[0];

            cout << "Membaca GameState dari file " << path << endl;
            File::Read fs(path);
            fs.ignore('#');
            GameState::getCurrentState().fromFile(fs);
            return false;
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
    
    GameCommands::COMMAND_REROLL = Command::withName("reroll")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;
            auto& p = GameState::getCurrentState().getCurrentPlayer();

            if(!p.hasAbilityCard(AbilityCard::ABILITY_REROLL_ID)){
                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REROLL.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }else if(p.getAbilityMati()){
                cout << "Oops, kartu ability REROLL-mu telah dimatikan sebelumnya:(.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }
            AbilityReroll a;
            a.get();
            p.removeAbilityCard();

            return true;
        }),
    
    GameCommands::COMMAND_QUADRUPLE = Command::withName("quadruple")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;
            auto& p = GameState::getCurrentState().getCurrentPlayer();

            if(!p.hasAbilityCard(AbilityCard::ABILITY_QUADRUPLE_ID)){
                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }else if(p.getAbilityMati()){
                cout << "Oops, kartu ability QUADRUPLE-mu telah dimatikan sebelumnya:(.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }
            AbilityQuadruple a;
            a.get();
            p.removeAbilityCard();

            return true;
        }),
    
    GameCommands::COMMAND_QUARTER = Command::withName("quarter")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;
            auto& p = GameState::getCurrentState().getCurrentPlayer();

            if(!p.hasAbilityCard(AbilityCard::ABILITY_QUARTER_ID)){
                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUARTER.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }else if(p.getAbilityMati()){
                cout << "Oops, kartu ability QUARTER-mu telah dimatikan sebelumnya:(.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }
            AbilityQuarter a;
            a.get();
            p.removeAbilityCard();

            return true;
        }),
    
    GameCommands::COMMAND_REVERSE = Command::withName("reverse")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;
            auto& p = GameState::getCurrentState().getCurrentPlayer();

            if(!p.hasAbilityCard(AbilityCard::ABILITY_REVERSE_ID)){
                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REVERSE.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }else if(p.getAbilityMati()){
                cout << "Oops, kartu ability REVERSE-mu telah dimatikan sebelumnya:(.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }
            AbilityReverse a;
            a.get();
            p.removeAbilityCard();

            // The player keeps their turn after REVERSE-ing
            return false;
        }),
    
    GameCommands::COMMAND_SWAP = Command::withName("swap")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;
            auto& p = GameState::getCurrentState().getCurrentPlayer();

            if(!p.hasAbilityCard(AbilityCard::ABILITY_SWAP_ID)){
                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability SWAP.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }else if(p.getAbilityMati()){
                cout << "Oops, kartu ability SWAP-mu telah dimatikan sebelumnya:(.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }
            AbilitySwap a;
            a.get();
            p.removeAbilityCard();

            return true;
        }),
    
    GameCommands::COMMAND_SWITCH = Command::withName("switch")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;
            auto& p = GameState::getCurrentState().getCurrentPlayer();

            if(!p.hasAbilityCard(AbilityCard::ABILITY_SWITCH_ID)){
                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability SWITCH.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }else if(p.getAbilityMati()){
                cout << "Oops, kartu ability SWITCH-mu telah dimatikan sebelumnya:(.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }
            AbilitySwitch a;
            a.get();
            p.removeAbilityCard();

            return true;
        }),
    
    GameCommands::COMMAND_ABILITYLESS = Command::withName("abilityless")
        .handles([](vector<string>& argv)->bool{
            if(argv.size() != 0)return false;
            auto& p = GameState::getCurrentState().getCurrentPlayer();

            if(!p.hasAbilityCard(AbilityCard::ABILITY_REROLL_ID)){
                cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability ABILITYLESS.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }else if(p.getAbilityMati()){
                cout << "Oops, kartu ability ABILITYLESS-mu telah dimatikan sebelumnya:(.\nSilahkan lakukan perintah lain." << endl;
                return false;
            }
            AbilityAbilityless a;
            a.get();
            p.removeAbilityCard();

            return true;
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
    CommandParser::reg(COMMAND_REROLL);
    CommandParser::reg(COMMAND_QUADRUPLE);
    CommandParser::reg(COMMAND_QUARTER);
    CommandParser::reg(COMMAND_REVERSE);
    CommandParser::reg(COMMAND_SWAP);
    CommandParser::reg(COMMAND_SWITCH);
    CommandParser::reg(COMMAND_ABILITYLESS);

    CommandParser::setErrMsg("Oops, perintah tidak ditemukan!\nSilakan lakukan perintah lain.");

    initialized = true;
}
