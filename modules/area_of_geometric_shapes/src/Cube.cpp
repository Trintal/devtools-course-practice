// Copyright 2018 Generalov Aleksandr

#include "include/Cube.h"

#include <string>


Cube::Cube(const double& _h) {
    if (!negativeNumbers(_h))
        h = _h;
    else
        throw std::string("Number can't be less then zero");
}

double Cube::areaCube() const {
    return 6 * h * h;
}

bool Cube::negativeNumbers(const double _h) {
    return _h < 0;
}
