#include "Combo.hpp"
// ASUMSI KARTU > 5
Combo::Combo(){
    this->val = 0;
}

bool Combo::compareCard(RegularCard c1, RegularCard c2) {
    return c1.value() > c2.value();
}

bool Combo::isPair(Table tbl, Player p){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeck(i));
    }

    for (int i=0; i<p.getRegularInvSize();i++) {
        tempInv.push_back(p.getRegularInv()[i]);
    }

    //sorting
    sort(tempInv.begin(),tempInv.end(),compareCard);

    for (int i=0; i<tempInv.size()-1;i++) {
        if (tempInv[i].getNum() == tempInv[i+1].getNum()) {
            return true;
        }
    }
    return false;
}

bool Combo::isTwoPair(Table tbl, Player p){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeck(i));
    }

    for (int i=0; i<p.getRegularInvSize();i++) {
        tempInv.push_back(p.getRegularInv()[i]);
    }

    //sorting
    sort(tempInv.begin(),tempInv.end(),compareCard);

    for (int i=0; i<tempInv.size()-3;i++) {
        if (tempInv[i].getNum() == tempInv[i+1].getNum()) {
            for (int j = i+2; j<tempInv.size()-1;j++) {
                if (tempInv[j].getNum() == tempInv[j+1].getNum()) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Combo::isThreeOfAKind(Table tbl, Player p){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeck(i));
    }

    for (int i=0; i<p.getRegularInvSize();i++) {
        tempInv.push_back(p.getRegularInv()[i]);
    }

    //sorting
    sort(tempInv.begin(),tempInv.end(),compareCard);

    bool tmp = false, tmp1 = true;
    for (int i=0; i<tempInv.size()-2;i++) {
        for (int j = i; j< i+2;j++) {
            if (tempInv[j].getNum() != tempInv[j+1].getNum()) {
                tmp1 = false;
            }
        }
        if (tmp1) {
            tmp=true;
            break;
        } else {
            tmp1 = true;
        }
    }
    return tmp;
}

bool Combo::isStraight(Table tbl, Player p){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeck(i));
    }

    for (int i=0; i<p.getRegularInvSize();i++) {
        tempInv.push_back(p.getRegularInv()[i]);
    }

    //sorting
    sort(tempInv.begin(),tempInv.end(),compareCard);

    //remove duplicate number cards
    std::vector<RegularCard> tempInv2;
    for (int i = 0; i<tempInv.size() ; i++) {
        if (i!= 0) {
            if (tempInv[i].getNum()!=tempInv[i-1].getNum()) {
                tempInv.push_back(tempInv[i]);
            } 
        } else {
            tempInv.push_back(tempInv[i]);
        }
    }

    bool tmp1 = true, tmp = false;
    if (tempInv2.size()>=5) {
        for (int i=0;i<tempInv2.size()-4;i++){
            for (int j=0; j<4; j++) {
                if (tempInv2[j].getNum() != tempInv2[j+1].getNum() + 1) {
                    tmp1 = false;
                }
            }
            if (tmp1) {
                tmp = true;
                break;
            } else {
                tmp1 = true;
            }
        }
        return tmp;
    } else {
        return false;
    }
}

bool Combo::isFlush(Table tbl, Player p){
    //array counter
    std::vector<int> count;
    count.assign(4,0);

    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeck(i));
    }

    for (int i=0; i<p.getRegularInvSize();i++) {
        tempInv.push_back(p.getRegularInv()[i]);
    }


    for (int i = 0; i<tempInv.size();i++) {
        count[tempInv[i].getColor()]++;
    }

    for (int i = 0; i<count.size();i++) {
        if (count[i]>=5) {
            return true;
        }
    }
    return false;
}

bool Combo::isFullHouse(Table tbl, Player p){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeck(i));
    }

    for (int i=0; i<p.getRegularInvSize();i++) {
        tempInv.push_back(p.getRegularInv()[i]);
    }

    //sorting
    sort(tempInv.begin(),tempInv.end(),compareCard);

    int tag;
    bool tmp = false;
    bool tmp1 = true;

    for (int i=0; i<tempInv.size()-2;i++) {
        for (int j = i; j< i+2;j++) {
            if (tempInv[j].getNum() != tempInv[j+1].getNum()) {
                tmp1 = false;
            }
        }
        if (tmp1) {
            tmp = true;
            tag = i;
            break;
        } else {
            tmp1 = true;
        }
    }

    if (tmp) {
        std::vector<RegularCard> tempInv2;
        for (int i = 0; i<tempInv.size() ; i++) {
            tempInv2.push_back(tempInv[i]);      
        }
        tempInv2.erase(tempInv2.begin()+tag,tempInv2.begin()+tag+3);

        for (int i=0; i<tempInv2.size()-1;i++) {
            if (tempInv2[i].getNum() == tempInv2[i+1].getNum()) {
                return true;
            }
        }
        return false;
    } else {
        return tmp;
    }
}

bool Combo::isFourOfAKind(Table tbl, Player p){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeck(i));
    }

    for (int i=0; i<p.getRegularInvSize();i++) {
        tempInv.push_back(p.getRegularInv()[i]);
    }

    //sorting
    sort(tempInv.begin(),tempInv.end(),compareCard);

    bool tmp1 = true, tmp = false;
    for (int i=0; i<tempInv.size()-3;i++) {
        for (int j = i; j< i+3;j++) {
            if (tempInv[j].getNum() != tempInv[j+1].getNum()) {
                tmp1 = false;
            }
        }
        if (tmp1) {
            tmp = true;
            break;
        } else {
            tmp1 = true;
        }
    }
    return tmp;
}

bool Combo::isStraightFlush(Table tbl, Player p){
    if (isStraight(tbl,p)&&isFlush(tbl,p)) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeck(i));
        }

        for (int i=0; i<p.getRegularInvSize();i++) {
            tempInv.push_back(p.getRegularInv()[i]);
        }

        //sorting
        sort(tempInv.begin(),tempInv.end(),compareCard);

        bool tmp1 = true,tmp = false;
        //getting flush color
        std::vector<int> count;
        int tag = -1;
        count.assign(4,0);
        for (int i = 0; i<tempInv.size();i++) {
            count[tempInv[i].getColor()]++;
        }

        for (int i = 0; i<count.size();i++) {
            if (count[3-i]>=5) {
                tag = 3-i;
                break;
            }
        }

        //removing all non flush cards

        std::vector<RegularCard> tempInv2;
        for (int i = 0; i<tempInv.size();i++) {
            if (tempInv[i].getColor() == tag) {
                tempInv2.push_back(tempInv[i]);
            }
        }

        //checking straight
        for (int i=0; i<tempInv2.size()-4; i++) {
            for (int j = 0; j<4;j++) {
                if (tempInv2[i+j].getNum() != tempInv2[i+j+1].getNum()+1) {
                    tmp1 = false;
                }
            }
            if (tmp1) {
                tmp = true;
                break;
            } else {
                tmp1 = true;
            }
        }
        return tmp;

    } else {
        return false;
    }
}

float Combo::value(Table tbl, Player p){
    float max = 0;
    bool tmp = false;
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeck(i));
    }

    for (int i=0; i<p.getRegularInvSize();i++) {
        tempInv.push_back(p.getRegularInv()[i]);
    }

    //sorting
    sort(tempInv.begin(),tempInv.end(),compareCard);
    max = tempInv[0].value();

    if (isPair(tbl,p)) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeck(i));
        }

        for (int i=0; i<p.getRegularInvSize();i++) {
            tempInv.push_back(p.getRegularInv()[i]);
        }

        //sorting
        sort(tempInv.begin(),tempInv.end(),compareCard);

        for (int i=0; i<tempInv.size()-1;i++) {
            if (tempInv[i].getNum() == tempInv[i+1].getNum()) {
                max = tempInv[i].value() + 1.4;
            }
        }
    }

    if (isTwoPair(tbl,p)) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeck(i));
        }

        for (int i=0; i<p.getRegularInvSize();i++) {
            tempInv.push_back(p.getRegularInv()[i]);
        }

        //sorting
        sort(tempInv.begin(),tempInv.end(),compareCard);

        for (int i=0; i<tempInv.size()-3;i++) {
            if (tempInv[i].getNum() == tempInv[i+1].getNum()) {
                for (int j = i+2; j<tempInv.size()-1;j++) {
                    if (tempInv[j].getNum() == tempInv[j+1].getNum()) {
                        max = tempInv[i].value()+2.8;
                    }
                }
            }
        }
    }

    if (isThreeOfAKind(tbl,p)) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeck(i));
        }

        for (int i=0; i<p.getRegularInvSize();i++) {
            tempInv.push_back(p.getRegularInv()[i]);
        }

        //sorting
        sort(tempInv.begin(),tempInv.end(),compareCard);

        bool tmp1 = true;
        for (int i=0; i<tempInv.size()-2;i++) {
            for (int j = i; j< i+2;j++) {
                if (tempInv[j].getNum() != tempInv[j+1].getNum()) {
                    tmp1 = false;
                }
            }
            if (tmp1) {
                max = tempInv[i].value()+4.2;
                break;
            } else {
                tmp1 = true;
            }
        }
    }

    if (isStraight(tbl,p)) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeck(i));
        }

        for (int i=0; i<p.getRegularInvSize();i++) {
            tempInv.push_back(p.getRegularInv()[i]);
        }

        //sorting
        sort(tempInv.begin(),tempInv.end(),compareCard);

        //remove duplicate number cards
        std::vector<RegularCard> tempInv2;
        for (int i = 0; i<tempInv.size() ; i++) {
            if (i!= 0) {
                if (tempInv[i].getNum()!=tempInv[i-1].getNum()) {
                    tempInv.push_back(tempInv[i]);
                } 
            } else {
                tempInv.push_back(tempInv[i]);
            }
        }

        bool tmp1 = true, tmp = false;
        for (int i=0;i<tempInv2.size()-4;i++){
            for (int j=0; j<4; j++) {
                if (tempInv2[j].getNum() != tempInv2[j+1].getNum() + 1) {
                    tmp1 = false;
                }
            }
            if (tmp1) {
                max = tempInv2[i].value() + 5.6;
                break;
            } else {
                tmp1 = true;
            }
        }

    }

    if (isFlush(tbl,p)) {
        std::vector<int> count;
        count.assign(4,0);
        int tag = -1;

        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeck(i));
        }

        for (int i=0; i<p.getRegularInvSize();i++) {
            tempInv.push_back(p.getRegularInv()[i]);
        }


        for (int i = 0; i<tempInv.size();i++) {
            count[tempInv[i].getColor()]++;
        }

        for (int i = 0; i<count.size();i++) {
            if (count[i]>=5) {
                tag = i;
            }
        }
        
        //sorting
        sort(tempInv.begin(),tempInv.end(),compareCard);

        for (int i=0; i<tempInv.size();i++) {
            if (tempInv[i].getColor()==tag) {
                max = tempInv[i].value() + 7;
            }
        }
    }

    if (isFullHouse(tbl,p)) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeck(i));
        }

        for (int i=0; i<p.getRegularInvSize();i++) {
            tempInv.push_back(p.getRegularInv()[i]);
        }

        //sorting
        sort(tempInv.begin(),tempInv.end(),compareCard);

        bool tmp1 = true;
        for (int i=0; i<tempInv.size()-2;i++) {
            for (int j = i; j< i+2;j++) {
                if (tempInv[j].getNum() != tempInv[j+1].getNum()) {
                    tmp1 = false;
                }
            }
            if (tmp1) {
                max = tempInv[i].value()+8.4;
                break;
            } else {
                tmp1 = true;
            }
        }
    }

    if (isFourOfAKind(tbl,p)) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeck(i));
        }

        for (int i=0; i<p.getRegularInvSize();i++) {
            tempInv.push_back(p.getRegularInv()[i]);
        }

        //sorting
        sort(tempInv.begin(),tempInv.end(),compareCard);

        bool tmp1 = true;
        for (int i=0; i<tempInv.size()-3;i++) {
            for (int j = i; j< i+3;j++) {
                if (tempInv[j].getNum() != tempInv[j+1].getNum()) {
                    tmp1 = false;
                }
            }
            if (tmp1) {
                max = tempInv[i].value()+9.4;
                break;
            } 
        }
    }

    if (isStraightFlush(tbl,p)) {
        std::vector<int> count;
        count.assign(4,0);
        int tag = -1;

        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeck(i));
        }

        for (int i=0; i<p.getRegularInvSize();i++) {
            tempInv.push_back(p.getRegularInv()[i]);
        }


        for (int i = 0; i<tempInv.size();i++) {
            count[tempInv[i].getColor()]++;
        }

        for (int i = 0; i<count.size();i++) {
            if (count[i]>=5) {
                tag = i;
            }
        }
        
        //sorting
        sort(tempInv.begin(),tempInv.end(),compareCard);

        //removing other colors
        std::vector<RegularCard> tempInv2;
        for (int i = 0; i< tempInv.size();i++) {
            if (tempInv[i].getColor() == tag) {
                tempInv2.push_back(tempInv[i]);
            }
        }

        bool tmp1 = true;

        for (int i=0; i<tempInv2.size()-4; i++) {
            for (int j = 0; j<4;j++) {
                if (tempInv2[i+j].getNum() != tempInv2[i+j+1].getNum()+1) {
                    tmp1 = false;
                }
            }
            if (tmp1) {
                max = tempInv2[i].value() + 11.2;
                break;
            } else {
                tmp1 = true;
            }
        }
    }

    return max;
}
