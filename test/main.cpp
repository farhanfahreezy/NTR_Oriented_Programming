#include <Player/Player.hpp>
#include <Deck/RegularDeck.hpp>
#include <Card/RegularCard.hpp>
#include <Card/AbilityCard.hpp>
#include <Table/Table.hpp>
#include <Combo/Combo.hpp>
#include <Game/GameAbility.hpp>
#include <Game/GameCommands.hpp>
#include <Game/GameState.hpp>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
    GameState initialState(7);
    std::cout << " ____   ______  ____                  ____   ___   __  _    ___  ____  \n";
    std::cout << "|    \\ |      ||    \\                |    \\ /   \\ |  |/ ]  /  _]|    \\ \n";
    std::cout << "|  _  ||      ||  D  )     _____     |  o  )     ||  ' /  /  [_ |  D  )\n";
    std::cout << "|  |  ||_|  |_||    /     |     |    |   _/|  O  ||    \\ |    _]|    / \n";
    std::cout << "|  |  |  |  |  |    \\     |_____|    |  |  |     ||     ||   [_ |    \\ \n";
    std::cout << "|  |  |  |  |  |  .  \\               |  |  |     ||  .  ||     ||  .  \\\n";
    std::cout << "|__|__|  |__|  |__|\\_|               |__|   \\___/ |__|\\_||_____||__|\\_|\n";

    initialState.setPlayersName();

    int pilihan = 0;
    cout << "Silahkan pilih opsi input kartu yang akan dimainkan: " << endl;
    cout << "1. Generate Random" << endl << "2. Input dari File" << endl;
    while (pilihan < 1 || pilihan > 2)
    {
        cout << "  > ";
        cin >> pilihan;
    }
    if(pilihan == 1){
        RegularDeck regDeck(52);
        initialState.shareRegularCardToPlayers(regDeck);
    } else {
        // INPUT DARI FILE AKU KURANG NGERTI
    }
    

    AbilityReroll abilityReroll;
    AbilityQuadruple abilityQuadruple;
    AbilityQuarter abilityQuarter;
    AbilityReverse abilityReverse;
    AbilitySwap abilitySwap;
    AbilitySwitch abilitySwitch;
    AbilityAbilityless abilityAbilityles;

    initialState.printAllPlayers();

    GameState::setCurrentState(initialState);

    GameState &gameState = GameState::getCurrentState();

    // PROGRAMNYA MULAI DARI SINI

    // MASIH ERROR, ISI CANGKUL PAS DIKIRIM KOSONG
    abilityReroll.get();
    gameState.printAllPlayers();

    
}
    
