// Copyright 2018 Generalov Aleksandr

#include "include/Cone.h"

#include <string>
#include <sstream>


const double pi = 3.14;

Cone::Cone() : radius(0), h(0) {}

Cone::Cone(const double& _rad, const double& _h) {
    if (!negativeNumbers(_rad, _h)) {
        radius = _rad;
        h = _h;
    } else {
        throw std::string("Number can't be less then zero");
    }
}

double Cone::areaCone() const {
    return pi * radius * (radius + h);
}

bool Cone::negativeNumbers(const double _rad, const double _h) {
    return _rad < 0 || _h < 0;
}
