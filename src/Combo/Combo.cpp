#include "Combo.hpp"

#include <typeinfo>
using namespace std;

Combo :: Combo(vector<RegularCard> player, vector<RegularCard> table) : Value(){
    this->player = player;
    this->table = table;
    this->com = this->combineAndSortRegularCard();
}

vector<RegularCard> Combo :: combineAndSortRegularCard() {
    vector<RegularCard> resultVec(table);
    resultVec.insert(resultVec.end(), player.begin(), player.end());
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
    this->com = resultVec;
    return resultVec;
}

vector<RegularCard> Combo::sortByColor() const{
    vector<RegularCard> combined = this->com;
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

vector<RegularCard> Combo :: sortByValue(vector<RegularCard> combo) const{
    vector<RegularCard> combined = combo;
    int n = combined.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (combined[j].value() > combined[i].value()) {
                RegularCard temp = combined[i];
                combined[i] = combined[j];
                combined[j] = temp;
            }
        }
    }
    return combined;
}

vector<RegularCard> Combo :: HighCard() const{
    //Kalo udah ngga ada combo samsek
    vector<RegularCard> HighCard;
    int n = player.size();
    for(int i = 0; i < n; i++){
        if(player[0].getNum() > player[1].getNum()){
            HighCard.push_back(player[0]);
            return HighCard;
        }
        if(player[0].getNum() == player[1].getNum()){
            if(player[0].getColor() > player[1].getColor()){
                HighCard.push_back(player[0]);
                return HighCard;
            }
            else{
                HighCard.push_back(player[1]);
                return HighCard;
            }
        }
        else{
            HighCard.push_back(player[1]);
            return HighCard;
        }
        
    }
    return HighCard;
}

vector<RegularCard> Combo::Pair() const{
    vector<RegularCard> Pair;
    vector<RegularCard> combined = this->com;
    int n = combined.size();

    for (int i = n - 1; i >= 1; i--) {
        if (combined[i].getNum() == combined[i-1].getNum()) {
            Pair.push_back(combined[i]);
            Pair.push_back(combined[i-1]);
            return Pair;
        }
    }

    return Pair;
}

vector<RegularCard> Combo::TwoPair() const{
    vector<RegularCard> combined = this->com;
    int n = combined.size();
    int count = 0;
    vector<RegularCard> TwoPair;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(combined[i].getNum() == combined[j].getNum()) {
                TwoPair.push_back(combined[i]);
                TwoPair.push_back(combined[j]);
                count++;
                if(count == 2) {
                    return TwoPair;
                }
            }
        }
    }
    TwoPair.clear(); // if no two pairs found, return an empty vector
    return TwoPair;
}


vector<RegularCard> Combo::ThreeOfAKind() const{
    vector<RegularCard> combined = this->com;
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

vector<RegularCard> Combo::Straight() const {
    vector<RegularCard> combined = this->com;
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


vector<RegularCard> Combo::Flush() const{
    vector<RegularCard> combined = this->com;
    vector<RegularCard> Flush;
    vector<RegularCard> newCombined = this->sortByColor();
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
            if (combined[i].getNum() == combined[j].getNum() && combined[i].getColor() != combined[j].getColor()) {
                continue; // skip if same number
            }
            if (combined[i].getColor() == combined[j].getColor()) {
                Flush.push_back(combined[j]); // add card to StraightFlush vector
                count++; // increment count
                 if (count == 4) {
                    return Flush; // return StraightFlush if found
                }
        
            }
            }
        }
    
    // clear StraightFlush vector if not found
    // No flush found
    return Flush;
}

vector<RegularCard> Combo::FullHouse() const{
    vector<RegularCard> combined = this->com;
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

vector<RegularCard> Combo::FourOfAKind() const{
    vector<RegularCard> combined = this->com;
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

vector<RegularCard> Combo::StraightFlush() const{
    vector<RegularCard> combined = this->com;
    vector<RegularCard> StraightFlush;
    int n = combined.size();
    int count = 0;
    int amount = 0;
    for (int i = n-1; i >= 1; i--) {
        StraightFlush.clear(); // clear StraightFlush vector for each new iteration
        StraightFlush.push_back(combined[i]); // add current card to StraightFlush vector
        count = 0; // reset count for each new iteration
        amount = 0;
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
    //StraightFlush.clear(); // clear StraightFlush vector if not found
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

int Combo::getCombo() const{
    if (this->value() < 1.4) {
        //cout << "High Card!" << endl;
        return 0; // HIGH CARD
    } else if (this->value() < 2.8) {
        //cout << "Pair!" << endl;
        return 1; // PAIR
    } else if (this->value() < 4.2) {
        //cout << "Two Pair!" << endl;
        return 2; // TWO PAIR
    } else if (this->value() < 5.6) {
        //cout << "Threes!" << endl;
        return 3; // THREE OF A KIND
    } else if (this->value() < 7) {
        //cout << "Straight!" << endl;
        return 4; // STRAIGHT
    } else if (this->value() < 8.4) {
        //cout << "Flush!" << endl;
        return 5; // FLUSH
    } else if (this->value() < 9.8) {
        //cout << "Full House!" << endl;
        return 6; // FULL HOUSE
    } else if (this->value() < 11.2) {
        //cout << "Fours!" << endl;
        return 7; // FOUR OF A KIND
    } else {
        //cout << "Straight Flush!" << endl;
        return 8; // STRAIGHT FLUSH
    }
}


float Combo :: value() const{
    if(this->StraightFlush().size() == 5){
        vector<RegularCard> result = this->StraightFlush();
        result = this->sortByValue(result);
        return result[0].value() + 11.2;
    }
    if(this->FourOfAKind().size() == 4){
        vector<RegularCard> result = this->FourOfAKind();
        result = this->sortByValue(result);
        return result[0].value() + 9.8;
    }
    if(this->FullHouse().size() == 5){
        vector<RegularCard> result = this->ThreeOfAKind();
        result = this->sortByValue(result);
        return result[0].value() + 8.4;
    }
    if(this->Flush().size() == 5){
        vector<RegularCard> result = this->Flush();
        result = this->sortByValue(result);
        return result[0].value() + 7.0;
    }
    if(this->Straight().size() == 5){
        vector<RegularCard> result = this->Straight();
        result = this->sortByValue(result);
        return result[0].value() + 5.6;
    }
    if(this->ThreeOfAKind().size() == 3){
        vector<RegularCard> result = this->ThreeOfAKind();
        result = this->sortByValue(result);
        return result[0].value() + 4.2;
    }
    if(this->TwoPair().size() == 4){
        vector<RegularCard> result = this->TwoPair();
        result = this->sortByValue(result);
        return result[0].value() + 2.8;
    }
    if(this->Pair().size() == 2){
         vector<RegularCard> result = this->Pair();
        result = this->sortByValue(result);
        return result[0].value() + 1.4;
    }
    if(this->HighCard().size() == 1){
        return this->HighCard()[0].value();
    }
    return 0.0;
}

float Combo:: TieBreaker() const{
    float val = this->value();
    if(this->getCombo() == 8){
        if(this->ThreeOfAKind().size() == 3){
            vector<RegularCard> result = this->ThreeOfAKind();
            result = this->sortByValue(result);
            return result[0].value() + 4.2;
        }
        if(this->TwoPair().size() == 4){
            vector<RegularCard> result = this->TwoPair();
            result = this->sortByValue(result);
            return result[0].value() + 2.8;
        }
        if(this->Pair().size() == 2){
            vector<RegularCard> result = this->Pair();
            result = this->sortByValue(result);
            return result[0].value() + 1.4;
        }
        if(this->HighCard().size() == 1){
            return this->HighCard()[0].value();
        }
    }
    if(this->getCombo() == 5){
        //kasus flush
        int color = this->Flush()[0].getColor();
        if(player[0].getColor() == player[1].getColor()){
            if(player[0].value() > player[1].value()){
                if(player[0].getColor() == color){
                    return player[0].value() + 1.4;
                }
                else{
                    return player[0].value();
                }
            }else{
                if(player[1].getColor() == color){
                    return player[1].value() + 1.4;
                }
                else{
                    return player[1].value();
                }

            }
        }
        for(int i = 0; i < player.size(); i++){
            if(player[i].getColor() == color){
                return player[i].value() + 1.4;
            }
        }
        return this->HighCard()[0].value();
    }
    if(this->getCombo() == 4){
        if(this->ThreeOfAKind().size() == 3){
            vector<RegularCard> result = this->ThreeOfAKind();
            result = this->sortByValue(result);
            return result[0].value() + 4.2;
        }
        if(this->TwoPair().size() == 4){
            vector<RegularCard> result = this->TwoPair();
            result = this->sortByValue(result);
            return result[0].value() + 2.8;
        }
        if(this->Pair().size() == 2){
            vector<RegularCard> result = this->Pair();
            result = this->sortByValue(result);
            return result[0].value() + 1.4;
        }
        if(this->HighCard().size() == 1){
            return this->HighCard()[0].value();
        }
    }
    else{
        return this->HighCard()[0].value();
    }
    return 0.0;

}

bool Combo::operator>(const Combo& c) const{
    if(this->value() > c.value()){
        return true;
    }
    if(this->value() == c.value()){
        return this->TieBreaker() > c.TieBreaker();
    }
    return false;
}
