#include "Combo.hpp"
#include <typeinfo>
using namespace std;

Combo :: Combo(){
    this->val = 0;
}

vector<RegularCard> Combo :: combineAndSortRegularCard(vector<RegularCard> vec1, vector<RegularCard> vec2){
    vector<RegularCard> resultVec(vec1);
    resultVec.insert(resultVec.end(), vec2.begin(), vec2.end());
    int n = resultVec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (resultVec[j].getNum() < resultVec[i].getNum()) {
                RegularCard temp = resultVec[i];
                resultVec[i] = resultVec[j];
                resultVec[j] = temp;
            }
        }
    }
    return resultVec;
}

vector<RegularCard> Combo::sortByColor(vector<RegularCard> combined){
    int n = combined.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (combined[j].getColor() < combined[i].getColor()) {
                RegularCard temp = combined[i];
                combined[i] = combined[j];
                combined[j] = temp;
            }
        }
    }
    return combined;

}

vector<RegularCard> Combo :: HighCard(vector<RegularCard> hand){
    //Kalo udah ngga ada combo samsek
    vector<RegularCard> HighCard;
    int n = hand.size();
    for(int i = 0; i < n; i++){
        if(hand[0].getNum() > hand[1].getNum()){
            HighCard.push_back(hand[0]);
            return HighCard;
        }
        if(hand[0].getNum() == hand[1].getNum()){
            if(hand[0].getColor() > hand[1].getColor()){
                HighCard.push_back(hand[0]);
                return HighCard;
            }
            else{
                HighCard.push_back(hand[1]);
                return HighCard;
            }
        }
        else{
            HighCard.push_back(hand[1]);
            return HighCard;
        }
        
    }
    return HighCard;
}

vector<RegularCard> Combo :: Pair(vector<RegularCard> table, vector<RegularCard> player){
    int n = table.size();
    int m = player.size();
    vector<RegularCard> Pair;
    //int count = 0;
    if(player[0].getNum() == player[1].getNum()){
        Pair.push_back(player[0]);
        Pair.push_back(player[1]);
        return Pair;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(table[i].getNum() == player[j].getNum()){
                Pair.push_back(table[i]);
                Pair.push_back(player[j]);
                return Pair;
            }
        }
    }
    return Pair;
}

vector<RegularCard> Combo :: TwoPair(vector<RegularCard> table, vector<RegularCard> player){
    int n = table.size();
    int m = player.size();
    int count = 0;
    vector<RegularCard> TwoPair;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(player[i].getNum() == table[j].getNum()){
                TwoPair.push_back(table[j]);
                TwoPair.push_back(player[i]);
                if(count == 2){
                    return TwoPair;
                }
            }
        }
    }
    return TwoPair;
}

vector<RegularCard> Combo::ThreeOfAKind(vector<RegularCard> combined){
    int n = combined.size();
    int count = 0;
    vector<RegularCard> Threes;
    for (int i = 0; i < n; i++) {
        Threes.push_back(combined[i]);
        for (int j = i + 1; j < n; j++) { // start from i + 1 to avoid duplicates
            if (combined[i].getNum() == combined[j].getNum()) {
                Threes.push_back(combined[j]);
                count++;
                if (count == 2) {
                    return Threes;
                }
            }
        }
        count = 0;
        Threes.clear(); // clear the vector after each iteration
    }
    return Threes;
}

vector<RegularCard> Combo::Straight(vector<RegularCard> combined/*, vector<RegularCard> table, vector<RegularCard> player*/) {
    vector<RegularCard> straight;
    int n = combined.size();
    int count = 0;
    for (int i = n-1; i >= 1; i--) {
        if (combined[i].getNum() == combined[i-1].getNum() + 1) {
            count++;
            if(!straight.empty()){
                if(straight.back().getNum() != combined[i].getNum()){
                    straight.push_back(combined[i]);
                }
            }
            else{
                straight.push_back(combined[i]);
            }
            if (count == 4) {
                straight.push_back(combined[i-1]);
                 // reverse the order
                return straight;
            }
        } else if (combined[i].getNum() == combined[i-1].getNum()) {
            if(!straight.empty()){
                if(straight.back().getNum() != combined[i].getNum()){
                    if(combined[i].getColor() > combined[i-1].getColor()) {
                    straight.push_back(combined[i]);
                } 
                else {
                    straight.push_back(combined[i-1]);
                }
                }
            }
        } else {
            count = 0; // reset the count if the cards are not consecutive
            straight.clear(); // clear the straight vector
        }
    }   

// No straight found
    return straight;
}


vector<RegularCard> Combo::Flush(vector<RegularCard> combined){
    vector<RegularCard> Flush;
    vector<RegularCard> newCombined = this->sortByColor(combined);
    int n = newCombined.size();
    int count = 0;
    /*for (int i = n - 1; i >= 1; i--) {
        if (newCombined[i].getColor() == newCombined[i - 1].getColor()) {
            count++;
            Flush.push_back(newCombined[i]);
            if (count == 4) {
                Flush.push_back(newCombined[i - 1]);
                return Flush;
            }
        }
    }*/
    for (int i = n-1; i >= 1; i--) {
        Flush.clear(); // clear Flush vector for each new iteration
        Flush.push_back(combined[i]); // add current card to Flush vector
        count = 0; // reset count for each new iteration
        for (int j = i-1; j >= 0; j--) { // iterate backwards
            /*int tes = combined[i].getNum();
            int tes2 = combined[j].getNum();
            int tes3 = combined[i].getColor();
            int tes4 = combined[j].getColor();*/
            //cout << tes << " " << tes3 << " " << tes2 << " " << tes4 << endl;
            if (combined[i].getNum() == combined[j].getNum()) {
                continue; // skip if same number
            }
            if (combined[i].getColor() == combined[j].getColor()) {
                Flush.push_back(combined[j]); // add card to StraightFlush vector
                count++; // increment count
                 if (count == 4) {
                    return Flush; // return StraightFlush if found
                }
                } else {
                    break; // break out of loop if not consecutive
                }
            }
        }
    
    Flush.clear(); // clear StraightFlush vector if not found
    // No flush found
    return Flush;
}

vector<RegularCard> Combo::FullHouse(vector<RegularCard> combined){
    vector<RegularCard> fullHouse;
    int count = 0;
    int currentNum = -1;
    for (int i = 0; i < combined.size() - 2; i++) {
        if (combined[i].getNum() == combined[i+1].getNum() && combined[i+1].getNum() == combined[i+2].getNum()) {
            count = 3;
            currentNum = combined[i].getNum();
            fullHouse.push_back(combined[i]);
            fullHouse.push_back(combined[i+1]);
            fullHouse.push_back(combined[i+2]);
            break;
        }
    }

    // Check for a pair of cards with a different number
    if (count == 3) {
        for (int i = 0; i < combined.size() - 1; i++) {
            if (combined[i].getNum() != currentNum && combined[i].getNum() == combined[i+1].getNum()) {
                fullHouse.push_back(combined[i]);
                fullHouse.push_back(combined[i+1]);
                return fullHouse;
            }
        }
    }

    // No full house found
    fullHouse.clear();
    return fullHouse;
}

vector<RegularCard> Combo::FourOfAKind(vector<RegularCard> combined){
    vector<RegularCard> Fours;
    int n = combined.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        Fours.push_back(combined[i]);
        for (int j = i + 1; j < n; j++) { // start from i + 1 to avoid duplicates
            if (combined[i].getNum() == combined[j].getNum()) {
                Fours.push_back(combined[j]);
                count++;
                if (count == 3) {
                    return Fours;
                }
            }
        }
        count = 0;
        Fours.clear(); // clear the vector after each iteration
    }
    return Fours;

}

vector<RegularCard> Combo::StraightFlush(vector<RegularCard> combined){
    vector<RegularCard> StraightFlush;
    int n = combined.size();
    int count = 0;
    int amount = 0;
    for (int i = n-1; i >= 1; i--) {
        StraightFlush.clear(); // clear StraightFlush vector for each new iteration
        StraightFlush.push_back(combined[i]); // add current card to StraightFlush vector
        count = 0; // reset count for each new iteration
        for (int j = i-1; j >= 0; j--) { // iterate backwards
            /*int tes = combined[i].getNum();
            int tes2 = combined[j].getNum();
            int tes3 = combined[i].getColor();
            int tes4 = combined[j].getColor();*/
            //cout << tes << " " << tes3 << " " << tes2 << " " << tes4 << endl;
            if (combined[i].getNum() == combined[j].getNum()) {
                continue; // skip if same number
            }
            if (combined[i].getColor() == combined[j].getColor()) {
                amount++;
                if (combined[i].getNum() == combined[j].getNum() + amount) {
                    StraightFlush.push_back(combined[j]); // add card to StraightFlush vector
                    count++; // increment count
                    if (count == 4) {
                        return StraightFlush; // return StraightFlush if found
                    }
                } else {
                    break; // break out of loop if not consecutive
                }
            }
        }
    }
    StraightFlush.clear(); // clear StraightFlush vector if not found
    return StraightFlush;

    /*for (int i = n-1; i >= 1; i--) {
        if (combined[i].getNum() == combined[i-1].getNum() + 1 && combined[i].getColor() == combined[i-1].getColor()) {
            count++;
            if(!StraightFlush.empty()){
                if(StraightFlush.back().getNum() != combined[i].getNum()){
                    StraightFlush.push_back(combined[i]);
                }
            }
            else{
                StraightFlush.push_back(combined[i]);
            }
            if (count == 4) {
                StraightFlush.push_back(combined[i-1]);
                 // reverse the order
                return StraightFlush;
            }
        } else if (combined[i].getNum() == combined[i-1].getNum()) {
            if(!StraightFlush.empty()){
                if(StraightFlush.back().getNum() != combined[i].getNum()){
                    if(combined[i].getColor() == StraightFlush.back().getColor()) {
                    StraightFlush.push_back(combined[i]);
                } 
                else if(combined[i-1].getColor() == StraightFlush.back().getColor()){
                    StraightFlush.push_back(combined[i-1]);
                }
                }
            }
        } else {
            count = 0; // reset the count if the cards are not consecutive
            StraightFlush.clear(); // clear the StraightFlush vector
        }
    }   

// No StraightFlush found
    return StraightFlush;*/
    return StraightFlush;
}










float Combo :: value(vector<RegularCard> combined, vector<RegularCard> table, vector<RegularCard> player){
    if(this->StraightFlush(combined).size() == 5){
        cout << "Straight Flush!" << endl;
        return 9.0;
    }
    if(this->FourOfAKind(combined).size() == 4){
        cout << "Fours!" << endl;
        return 8.0;
    }
    if(this->FullHouse(combined).size() == 5){
        cout << "Full House!" << endl;
        return 7.0;
    }
    if(this->Flush(combined).size() == 5){
        cout << "Flush!" << endl;
        return 6.0;
    }
    if(this->Straight(combined).size() == 5){
        cout << "Straight!" << endl;
        return 5.0;
    }
    if(this->ThreeOfAKind(combined).size() == 3){
        cout << "Threes!" << endl;
        return 4.0;
    }
    if(this->TwoPair(table, player).size() == 4){
        cout << "Two Pair!" << endl;
        return 3.0;
    }
    if(this->Pair(table, player).size() == 2){
        cout << "Pair!" << endl;
        return 2.0;
    }
    if(this->HighCard(player).size() == 1){
        cout << "High Card!" << endl;
        return 1.0;
    }
    return 0.0;
}
