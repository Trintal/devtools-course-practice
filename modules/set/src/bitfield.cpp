// Copyright 2018 Levitsky Ilya
#include "include/bitfield.h"

bitfield::bitfield(int _SizeU) {
    sizeU = _SizeU;

    if (sizeU != 0) {
       n = (_SizeU + (sizeof(int) << 3) - 1) / sizeof(int) << 3;
       arr = new int[n];
       for (int i = 0; i < n; i++) {
            arr[i] = 0;
       }
    }
}

bitfield::~bitfield() {
    delete[] arr;
}

int bitfield::Mem_index(int k) {
    return k / sizeof(int) << 3;;
}

int bitfield::Mask(int k) {
    return 1 << (k % sizeof(int) << 3);
}

void bitfield::setbit(int T) {
    arr[Mem_index(T)] |= Mask(T);
}

int bitfield::getbit(int T) {
    return arr[Mem_index(T)] & Mask(T);
}

bitfield bitfield :: operator&(const bitfield& X) {
    int len = sizeU;
    bitfield res(len);
    for (int i = 0; i < n; i++) {
        res.arr[i] = arr[i];
    }
    for (int i = 0; i < X.n; i++) {
        res.arr[i] = arr[i] & X.arr[i];
    }
    return res;
}

bitfield bitfield :: operator|(const bitfield& X) {
    int len = sizeU;
    bitfield res(len);
    for (int i = 0; i < n; i++) {
    res.arr[i] = arr[i];
    }
    for (int i = 0; i < X.n; i++) {
        res.arr[i] = arr[i] | X.arr[i];
    }
    return res;
}

bitfield& bitfield :: operator=(const bitfield& X) {
    sizeU = X.sizeU;
    if (arr != NULL)
        delete arr;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = X.arr[i];
    }
    return *this;
}

bitfield bitfield :: operator~() {
    bitfield tmp(sizeU);
    for (int i = 0; i < n; i++) {
    tmp.arr[i] = ~arr[i];
    }
    return tmp;
}