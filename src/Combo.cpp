#include "Combo.hpp"
// ASUMSI KARTU > 5
Combo::Combo(Table tblt, Player pt){
    this->val = 0;
    this->tbl = tblt;
    this->p = pt;
}

bool Combo::compareCard(RegularCard c1, RegularCard c2) {
    return c1.value() > c2.value();
}

bool Combo::isPair(){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeckCard(i));
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

bool Combo::isTwoPair(){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeckCard(i));
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

bool Combo::isThreeOfAKind(){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeckCard(i));
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

bool Combo::isStraight(){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeckCard(i));
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

bool Combo::isFlush(){
    //array counter
    std::vector<int> count;
    count.assign(4,0);

    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeckCard(i));
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

bool Combo::isFullHouse(){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeckCard(i));
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

bool Combo::isFourOfAKind(){
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeckCard(i));
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

bool Combo::isStraightFlush(){
    if (isStraight()&&isFlush()) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeckCard(i));
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

float Combo::value(){
    float max = 0;
    bool tmp = false;
    std::vector<RegularCard> tempInv;
    //gabung
    for (int i=0; i<tbl.getTableDeckSize();i++) {
        tempInv.push_back(tbl.getTableDeckCard(i));
    }

    for (int i=0; i<p.getRegularInvSize();i++) {
        tempInv.push_back(p.getRegularInv()[i]);
    }

    //sorting
    sort(tempInv.begin(),tempInv.end(),compareCard);
    max = tempInv[0].value();

    if (isPair()) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeckCard(i));
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

    if (isTwoPair()) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeckCard(i));
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

    if (isThreeOfAKind()) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeckCard(i));
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

    if (isStraight()) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeckCard(i));
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

    if (isFlush()) {
        std::vector<int> count;
        count.assign(4,0);
        int tag = -1;

        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeckCard(i));
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

    if (isFullHouse()) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeckCard(i));
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

    if (isFourOfAKind()) {
        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeckCard(i));
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

    if (isStraightFlush()) {
        std::vector<int> count;
        count.assign(4,0);
        int tag = -1;

        std::vector<RegularCard> tempInv;
        //gabung
        for (int i=0; i<tbl.getTableDeckSize();i++) {
            tempInv.push_back(tbl.getTableDeckCard(i));
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

    val = max;
    return max;
}


int Combo::getCombo(){
    if (val < 1.4) {
        return 0; // HIGH CARD
    } else if (val < 2.8) {
        return 1; // PAIR
    } else if (val < 4.2) {
        return 2; // TWO PAIR
    } else if (val < 5.6) {
        return 3; // THREE OF A KIND
    } else if (val < 7) {
        return 4; // STRAIGHT
    } else if (val < 8.4) {
        return 5; // FLUSH
    } else if (val < 9.8) {
        return 6; // FULL HOUSE
    } else if (val < 11.2) {
        return 7; // FOUR OF A KIND
    } else {
        return 8; // STRAIGHT FLUSH
    }
}

Player Combo::getWinner(GameState game){
    std::vector<Combo> cmbs;
    Combo ctemp(game.getTable(),game.getPlayerWithId(0));
    cmbs.push_back(ctemp);
    for (int i = 1; i<game.getNumberOfPlayer();i++) {
        ctemp.setPlayer(game.getPlayerWithId(i));
        cmbs.push_back(ctemp);
    }

    std::vector<float> vals;
    int tmp;
    for (int i = 0; i< cmbs.size();i++) {
        tmp = cmbs[i].value();
        vals.push_back(tmp);
    }

    int tag =0;
    bool multp=false;
    float max = vals[0];
    for (int i = 1; i<vals.size();i++) {
        if (max<vals[i]) {
            max = vals[i];
            tag = i;
        }
    }

    for (int i = 0; i<vals.size();i++) {
        if (max==vals[i]) {
            multp=true;
        }
    }

    if (multp) {
        int type = cmbs[tag].getCombo();
        if (type == 5 || type == 8) {
            //KASUS FLUSH + STRAIGHT FLUSH
            std::vector<int> count;
            count.assign(4,0);
            int tag2 = -1;

            std::vector<RegularCard> tempInv;
            //gabung
            for (int i=0; i<tbl.getTableDeckSize();i++) {
                tempInv.push_back(cmbs[tag].tbl.getTableDeckCard(i));
            }

            for (int i=0; i<p.getRegularInvSize();i++) {
                tempInv.push_back(cmbs[tag].p.getRegularInv()[i]);
            }


            for (int i = 0; i<tempInv.size();i++) {
                count[tempInv[i].getColor()]++;
            }

            for (int i = 0; i<count.size();i++) {
                if (count[i]>=5) {
                    tag2 = i;
                }
            }

            std::vector<RegularCard> cardsT;
            std::vector<int> cardsOwner;
            for (int i = 0; i<cmbs.size();i++) {
                if (cmbs[i].value()==max) {
                    for (int j = 0; j<game.getPlayerWithId(i).getRegularInvSize();j++) {
                        if (game.getPlayerWithId(i).getRegularInv()[i].getColor()==tag2) {
                            cardsT.push_back(game.getPlayerWithId(i).getRegularInv()[i]);
                            cardsOwner.push_back(i);
                        }
                    }

                    
                }
            }
            max = cardsT[0].value();
            tag = 0;
            for (int i = 1;i<cardsT.size();i++) {
                if (cardsT[i].value()>max) {
                    max = cardsT[i].value();
                    tag = i;
                }
            }
        } else {
            std::vector<RegularCard> cardsT;
            std::vector<int> cardsOwner;
            for (int i = 0; i<cmbs.size();i++) {
                if (cmbs[i].value()==max) {
                    for (int j = 0; j<game.getPlayerWithId(i).getRegularInvSize();j++) {
                        cardsT.push_back(game.getPlayerWithId(i).getRegularInv()[i]);
                        cardsOwner.push_back(i);
                    }
                }
            }
            max = cardsT[0].value();
            tag = 0;
            for (int i = 1;i<cardsT.size();i++) {
                if (cardsT[i].value()>max) {
                    max = cardsT[i].value();
                    tag = i;
                }
            }
        }
    }
    
    return game.getPlayerWithId(tag);
}
