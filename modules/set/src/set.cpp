// Copyright 2018 Levitsky Ilya
#include "include/set.h"

set::set(int mp) {
    MaxPow = mp;
    BF = bitfield(mp);
}


set::set(set& x) {
    MaxPow = x.MaxPow;
    BF = x.BF;
}

void set::Insert(int k) {
    if (k <= 0 || k > MaxPow)
        return;
    BF.setbit(k);
}

int set::GetN(int k) {
    int isEmpty = 1;
    for (int i = 1; i <= MaxPow; i++) {
        if (Get(k)) {
            return k;
        }
    }
    if (isEmpty) {
        return 0;
    }
}

int set::Get(int k) {
    return BF.getbit(k);
}

set set :: operator+(const set& x) {
    set tmp(x.MaxPow);
    tmp.BF = BF | x.BF;
    return(tmp);
}


set set :: operator*(const set& x) {
    set tmp(x.MaxPow);
    tmp.BF = BF&x.BF;
    return(tmp);
}

set set :: operator~() {
    set tmp(MaxPow);
    tmp.BF = ~BF;
    return tmp;
}

set& set :: operator=(const set& x) {
    BF = x.BF;
    return *this;
}
