#include "Combo.hpp"

Combo::Combo(){
    this->val = 0;
}

bool Combo::isPair(RegularDeck oth){
    oth.sortDeckByValue();
    for (int i=0; i<oth.getAmount()-2;i++) {
        if (oth.getCard(i).getNum() == oth.getCard(i+1).getNum()) {
            return true;
        }
    }
    return false;
}

bool Combo::isTwoPair(RegularDeck oth){
    oth.sortDeckByValue();
    for (int i=0; i<oth.getAmount()-2;i++) {
        if (oth.getCard(i).getNum() == oth.getCard(i+1).getNum()) {
            for (int j = i+2; j<oth.getAmount()-2;j++) {
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
    bool tmp = true;
    for (int i=0; i<oth.getAmount()-3;i++) {
        for (int j = i; j< i +3;j++) {
            if (oth.getCard(j).getNum() != oth.getCard(j+1).getNum()) {
                tmp = false;
            }
        }
        if (tmp) {
            return tmp;
        } else {
            tmp = false;
        }
    }
    return tmp;
}

bool Combo::isStraight(RegularDeck oth){
    oth.sortDeckByValue();
    bool tmp = true;
    for (int i=0;i<3;i++){
        for (int j=oth.getCard(i).getNum(); j> oth.getCard(i).getNum()-5; j--) {
            if (j != oth.getCard(i).getNum()) {
                tmp = false;
            }
        }
        if (tmp) {
            return tmp;
        } else {
            tmp = true;
        }
    }
    return tmp;
}

bool Combo::isFlush(RegularDeck oth){
    oth.sortDeckByValue();
    bool tmp = true;
    for (int i=0;i<3;i++){
        for (int j=i; j<i+5; j++) {
            if (oth.getCard(j).getColor() != oth.getCard(j).getColor()) {
                tmp = false;
            }
        }
        if (tmp = true) {
            return true;
        } else {
            tmp = true;
        }
    }
    return tmp;
}

bool Combo::isFullHouse(RegularDeck oth){

}

bool Combo::isFourOfAKind(RegularDeck oth){
    oth.sortDeckByValue();
    bool tmp = true;
    for (int i=0; i<oth.getAmount()-4;i++) {
        for (int j = i; j< i+4;j++) {
            if (oth.getCard(j).getNum() != oth.getCard(j+1).getNum()) {
                tmp = false;
            }
        }
        if (tmp) {
            return tmp;
        } else {
            tmp = false;
        }
    }
    return tmp;
}

bool Combo::isStraightFlush(RegularDeck oth){
    oth.sortDeckByValue();
    bool tmp = true;
    for (int i=0;i<3;i++){
        for (int j=i; j<i+5; j++) {
            if ((oth.getCard(j).getColor() != oth.getCard(j).getColor())&&(oth.getCard(j).getNum() != oth.getCard(j+1).getNum()+1)){
                tmp = false;
            }
        }
        if (tmp = true) {
            return true;
        } else {
            tmp = true;
        }
    }
    return tmp;
}

float Combo::value(RegularDeck oth){
    float max = 0;
    bool tmp = false;
    oth.sortDeckByValue();
    max = oth.getCard(0).value();

    if (isPair(oth)) {
        for (int i=0; i<oth.getAmount()-2;i++) {
            if (oth.getCard(i).getNum() == oth.getCard(i+1).getNum()) {
                max = oth.getCard(i).value() + 1.4;
            }
        }
    }

    if (isTwoPair(oth)) {
        for (int i=0; i<oth.getAmount()-2;i++) {
            if (oth.getCard(i).getNum() == oth.getCard(i+1).getNum()) {
                for (int j = i+2; j<oth.getAmount()-2;j++) {
                    if (oth.getCard(j).getNum() == oth.getCard(j+1).getNum()) {
                        if (max < oth.getCard(i).value() + 2.8) {
                            max = oth.getCard(i).value() + 2.8;
                        }
                    }
                }
            }
        }
    }

    if (isThreeOfAKind(oth)) {
        tmp = true;
        for (int i=0; i<oth.getAmount()-3;i++) {
            for (int j = i; j< i +3;j++) {
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
        tmp = true;
        for (int i=0;i<3;i++){
            for (int j=oth.getCard(i).getNum(); j> oth.getCard(i).getNum()-5; j--) {
                if (j != oth.getCard(i).getNum()) {
                    tmp = false;
                }
            }
            if (tmp) {
                max = oth.getCard(i).value()+5.6;
                break;
            } 
        }
    }

    if (isFlush(oth)) {
    tmp = true;
    int mtemp = 0;
        for (int i=0;i<3;i++){
            for (int j=i; j<i+5; j++) {
                if (oth.getCard(j).getColor() != oth.getCard(j).getColor()) {
                    tmp = false;
                } else {
                    if (mtemp < oth.getCard(j).value()) {
                        mtemp = oth.getCard(j).value();
                    }
                    if (mtemp < oth.getCard(j+1).value()) {
                        mtemp = oth.getCard(j+1).value();
                    }
                }

            }
            if (tmp) {
                max = mtemp + 7;
                break;
            }
        }
    }

    if (isFullHouse(oth)) {
        // TO DO: FULLHOUSE, max = max + 8.4
    }

    if (isFourOfAKind(oth)) {
        tmp = true;
        for (int i=0; i<oth.getAmount()-4;i++) {
            for (int j = i; j< i+4;j++) {
                if (oth.getCard(j).getNum() != oth.getCard(j+1).getNum()) {
                    tmp = false;
                }
            }
            if (tmp) {
                max = oth.getCard(i).value() + 9.8;
                break;
            }
        }
    }

    if (isStraightFlush(oth)) {
        tmp = true;
        for (int i=0;i<3;i++){
            for (int j=i; j<i+5; j++) {
                if ((oth.getCard(j).getColor() != oth.getCard(j).getColor())&&(oth.getCard(j).getNum() != oth.getCard(j+1).getNum()+1)){
                    tmp = false;
                }
            }
            if (tmp) {
                max = oth.getCard(i).value() + 11.2;
                break;
            }
        }
    }
    
    return max;
}
