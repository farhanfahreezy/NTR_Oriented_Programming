#include <Player/Player.hpp>
#include <Deck/RegularDeck.hpp>
#include <Card/RegularCard.hpp>
#include <Card/AbilityCard.hpp>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
    RegularDeck regDeck(52);
    regDeck.shuffleDeck();
    regDeck.getCard(0).printInfo();
    Player player(1);
    player.setName("one");
    cout << player.getName() << "'s Inventory:" << endl;
    cout << player.getRegularInvSize() << endl;
    player + regDeck.getCard(2);
    player + regDeck.getCard(2);
    player + regDeck.getCard(2);
    player + regDeck.getCard(2);
    player + regDeck.getCard(2);
    player + regDeck.getCard(2);
    cout << player.getName() << "'s Inventory:" << endl;
    cout << player.getRegularInvSize() << endl;
    player - regDeck.getCard(2);
    cout << player.getName() << "'s Inventory:" << endl;
    cout << player.getRegularInvSize() << endl;
    /* Player player2(2);
    string name;
    cout << "Enter Player Name:";
    cin >> name;
    string name2;
    cout << "Enter Player Name:";
    cin >> name2;
    player.setName(name);
    player2.setName(name2);
    player.addRegularCard(regDeck.getCard(0), 2);
    player.addRegularCard(regDeck.getCard(1), 2);
    cout << player.getName() << "'s Inventory:" << endl;
    for(auto card : player.getRegularInv()){
        card.printInfo();
    }
    cout << player2.getName() << "'s Inventory:" << endl;
    player2.addRegularCard(regDeck.getCard(2), 2);
    player2.addRegularCard(regDeck.getCard(3), 2);
    for(auto card : player2.getRegularInv()){
        card.printInfo();
    } */
    /*for(int i = 0; i < 7; i++){
        string name;
        cout << "Enter Player " << i+1 << " Name:";
        cin >> name;
        Player player(i + 1);
        player.setName(name);
        players.push_back(player);
        for (int j = 0; j < 2; j++) {
            player.addRegularCard(regDeck.getCard(i*2 + j), 2);
        }
    }
    for (const Player& player : players) {
    cout << player.getName() << "'s Inventory:" << endl;
    cout << "Regular Cards:" << endl;
    const auto& inv = player.getRegularInv();
    cout << "Inventory size: " << inv.size() << endl; // add this line
    for(auto card : inv){
        card.printInfo();
    }*/

    /*for(int i = 0; i < 7; i++){
        cout << players[i].getName() << endl;
    }*/
    /*RegularDeck regDeck(52);
    regDeck.shuffleDeck();
    for(int i = 0; i < 52; i++){
        RegularCard card = regDeck.getCard(i);
        card.printInfo();
    }*/
}
    
