#include "Combo.hpp"
// ASUMSI KARTU > 5
Combo::Combo(){
    this->val = 0;
}

bool Combo::isPair(RegularDeck oth){
    oth.sortDeckByValue();
    for (int i=0; i<oth.getAmount()-1;i++) {
        if (oth.getCard(i).getNum() == oth.getCard(i+1).getNum()) {
            return true;
        }
    }
    return false;
}

bool Combo::isTwoPair(RegularDeck oth){
    oth.sortDeckByValue();
    for (int i=0; i<oth.getAmount()-3;i++) {
        if (oth.getCard(i).getNum() == oth.getCard(i+1).getNum()) {
            for (int j = i+2; j<oth.getAmount()-1;j++) {
                if (oth.getCard(j).getNum() == oth.getCard(j+1).getNum()) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Combo::isThreeOfAKind(RegularDeck oth){
    oth.sortDeckByValue();
    bool tmp = false, tmp1 = true;
    for (int i=0; i<oth.getAmount()-2;i++) {
        for (int j = i; j< i+2;j++) {
            if (oth.getCard(j).getNum() != oth.getCard(j+1).getNum()) {
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

bool Combo::isStraight(RegularDeck oth){
    oth.sortDeckByValue();
    RegularDeck oth1(oth);
    oth1.removeDuplicateNumbers();
    bool tmp1 = true, tmp = false;
    if (oth1.getAmount()>=5) {
        for (int i=0;i<oth1.getAmount()-4;i++){
            for (int j=0; j<4; j++) {
                if (oth1.getCard(j).getNum() != oth1.getCard(j+1).getNum() + 1) {
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

bool Combo::isFlush(RegularDeck oth){
    std::vector<int> count;
    count.assign(4,0);
    for (int i = 0; i<oth.getAmount();i++) {
        count[oth.getCard(i).getColor()]++;
    }

    for (int i = 0; i<count.size();i++) {
        if (count[i]>=5) {
            return true;
        }
    }
    return false;
}

bool Combo::isFullHouse(RegularDeck oth){
    oth.sortDeckByValue();
    int tag;
    bool tmp = false;
    bool tmp1 = true;
    for (int i=0; i<oth.getAmount()-2;i++) {
        for (int j = i; j< i+2;j++) {
            if (oth.getCard(j).getNum() != oth.getCard(j+1).getNum()) {
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
        RegularDeck oth1(oth);
        for (int k = 0; k<3; k++) {
            oth1.removeCard(tag+k);
        }
        return isPair(oth1);
    } else {
        return tmp;
    }
}

bool Combo::isFourOfAKind(RegularDeck oth){
    oth.sortDeckByValue();
    bool tmp1 = true, tmp = false;
    for (int i=0; i<oth.getAmount()-3;i++) {
        for (int j = i; j< i+3;j++) {
            if (oth.getCard(j).getNum() != oth.getCard(j+1).getNum()) {
                tmp1 = false;
            }
        }
        if (tmp1) {
            tmp = true;
            break;
        } else {
            tmp1 = true;
        } . . . . . . . 
    }
    return tmp;
}

bool Combo::isStraightFlush(RegularDeck oth){
    if (isStraight(oth)&&isFlush(oth)) {
        oth.sortDeckByValue();
        RegularDeck oth1(oth);
        bool tmp1 = true,tmp = false;
        oth1.removeOtherColor(oth.getFlushType());
        for (int i=0; i<oth1.getAmount()-4; i++) {
            for (int j = 0; j<4;j++) {
                if (oth1.getCard(i+j).getNum() != oth1.getCard(i+j+1).getNum()+1) {
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

float Combo::value(RegularDeck oth){
    float max = 0;
    bool tmp = false;
    oth.sortDeckByValue();
    max = oth.getCard(0).value();

    if (isPair(oth)) {
        for (int i=0; i<oth.getAmount()-1;i++) {
            if (oth.getCard(i).getNum() == oth.getCard(i+1).getNum()) {
                max = oth.getCard(i).value() + 1.4;
                break;
            }
        }
    }

    if (isTwoPair(oth)) {
        for (int i=0; i<oth.getAmount()-1;i++) {
            if (oth.getCard(i).getNum() == oth.getCard(i+1).getNum()) {
                for (int j = i+2; j<oth.getAmount()-1;j++) {
                    if (oth.getCard(j).getNum() == oth.getCard(j+1).getNum()) {
                        max = oth.getCard(i).value() + 2.8;
                        break;
                    }
                }
            }
        }
    }

    if (isThreeOfAKind(oth)) {
        tmp = true;
        for (int i=0; i<oth.getAmount()-2;i++) {
            for (int j = i; j< i+2;j++) {
                if (oth.getCard(j).getNum() != oth.getCard(j+1).getNum()) {
                    tmp = false;
                }
            }
            if (tmp) {
                max = oth.getCard(i).value()+4.2;
                break;
            } 
        }
    }

    if (isStraight(oth)) {
        RegularDeck oth1(oth);
        oth1.removeDuplicateNumbers();
        bool tmp1 = true;
        for (int i=0;i<oth1.getAmount()-4;i++){
            for (int j=0; j<5; j--) {
                if (oth1.getCard(j).getNum() != oth1.getCard(j+1).getNum() + 1) {
                    tmp1 = false;
                }
            }
            if (tmp1) {
                max = oth1.getCard(i).getNum() + 5.6;
                break;
            } else {
                tmp1 = true;
            }
        }
    }

    if (isFlush(oth)) {
        oth.sortDeckByValue();
        RegularDeck oth1(oth);
        oth1.removeOtherColor(oth.getFlushType());
        max = oth1.getCard(0).value() + 7;
    }

    if (isFullHouse(oth)) {
        tmp = true;
        for (int i=0; i<oth.getAmount()-2;i++) {
            for (int j = i; j< i+2;j++) {
                if (oth.getCard(j).getNum() != oth.getCard(j+1).getNum()) {
                    tmp = false;
                }
            }
            if (tmp) {
                max = oth.getCard(i).value()+8.4;
                break;
            } else {
                tmp = true;
            }
        }
    }

    if (isFourOfAKind(oth)) {
        tmp = true;
        for (int i=0; i<oth.getAmount()-3;i++) {
            for (int j = i; j< i+3;j++) {
                if (oth.getCard(j).getNum() != oth.getCard(j+1).getNum()) {
                    tmp = false;
                }
            }
            if (tmp) {
                max = oth.getCard(i).value() + 9.8;
                break;
            } else {
                tmp = true;
            }
        }
    }

    if (isStraightFlush(oth)) {
        oth.sortDeckByValue();
        RegularDeck oth1(oth);
        bool tmp1 = true;
        oth1.removeOtherColor(oth.getFlushType());
        for (int i=0; i<oth1.getAmount()-4; i++) {
            for (int j = 0; j<4;j++) {
                if (oth1.getCard(i+j).getNum() != oth1.getCard(i+j+1).getNum()+1) {
                    tmp1 = false;
                }
            }
            if (tmp1) {
                max = oth1.getCard(i).value() + 11.2;
                break;
            } else {
                tmp1 = true;
            }
        }
    }

    return max;
}
