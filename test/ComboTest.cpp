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
    Player p(1);
    Player p2(2);
    Table t;
    RegularCard card0(1,3);
    RegularCard card1(2,3);
    RegularCard card2(3,3);
    RegularCard card3(4,3);
    RegularCard card4(5,3);
    RegularCard card5(5,1);
    RegularCard card6(10,1);
    RegularCard card7(5,2);
    RegularCard card8(7,1);
    t + card0;
    t + card1;
    t + card2;
    t + card3;
    t + card4;
    p + card5;
    p + card6;
    p2 + card7;
    p2 + card8;
    Combo c(p.getRegularInv(), t.getRegularInv());
    Combo c1(p2.getRegularInv(), t.getRegularInv());
    cout << "Combined Inv: " << endl;
   /* vector<RegularCard> comboP1 = c.combineAndSortRegularCard();
    for(auto card : comboP1){
        card.printInfo();
    }
     cout << "Combined Inv: " << endl;
    vector<RegularCard> comboP2 = c1.combineAndSortRegularCard();
    for(auto card : comboP2){
        card.printInfo();
    }*/
    float result = c.value();
    float result2 = c1.value();
    int combo1 = c.getCombo();
    int combo2 = c1.getCombo();
    cout << result << " " << combo1 << " " << result2 << " " << combo2 << endl;
    if(c > c1){
        cout << "player 1 menang" << endl;
    }
    else{
        cout << "player 2 menang" << endl;
    }

    return 0;
}