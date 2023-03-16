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

    // Set initialState as CurrentState so it can be used in another algorithm
    GameState::setCurrentState(initialState);
    
    // Declare new GameState gameState as reference to CurrentState
    GameState &gameState = GameState::getCurrentState();


    // MASIH ERROR, ISI CANGKUL PAS DIKIRIM KOSONG
    abilityQuadruple.get();
    cout << "isi cangkul: " << initialState.getTable().getRegularInvSize() << endl;
    
    abilityReroll.get();
    cout << "isi cangkul: " << gameState.getTable().getRegularInvSize() << endl;
    gameState.printAllPlayers();

    // Main loop
    while(!gameState.isComplete()){
        // MAIN DISINI
        gameState.advance();
    }

    std::cout << " ____   ______  ____                  ____   ___   __  _    ___  ____  \n";
    std::cout << "|    \\ |      ||    \\                |    \\ /   \\ |  |/ ]  /  _]|    \\ \n";
    std::cout << "|  _  ||      ||  D  )     _____     |  o  )     ||  ' /  /  [_ |  D  )\n";
    std::cout << "|  |  ||_|  |_||    /     |     |    |   _/|  O  ||    \\ |    _]|    / \n";
    std::cout << "|  |  |  |  |  |    \\     |_____|    |  |  |     ||     ||   [_ |    \\ \n";
    std::cout << "|  |  |  |  |  |  .  \\               |  |  |     ||  .  ||     ||  .  \\\n";
    std::cout << "|__|__|  |__|  |__|\\_|               |__|   \\___/ |__|\\_||_____||__|\\_|\n";

    std::cout << " ______    ___  ____   ____  ___ ___   ____  __  _   ____  _____ ____  __ __ \n"
                 "|      |  /  _]|    \\ |    ||   |   | /    ||  |/ ] /    |/ ___/|    ||  |  |\n"
                 "|      | /  [_ |  D  ) |  | | _   _ ||  o  ||  ' / |  o  (   \\_  |  | |  |  |\n"
                 "|_|  |_||    _]|    /  |  | |  \\_/  ||     ||    \\ |     |\\__  | |  | |  _  |\n"
                 "  |  |  |   [_ |    \\  |  | |   |   ||  _  ||     ||  _  |/  \\ | |  | |  |  |\n"
                 "  |  |  |     ||  .  \\ |  | |   |   ||  |  ||  .  ||  |  |\\    | |  | |  |  |\n"
                 "  |__|  |_____||__|\\_||____||___|___||__|__||__|__||__|__| \\___||____||__|__|\n";



    
}
    
