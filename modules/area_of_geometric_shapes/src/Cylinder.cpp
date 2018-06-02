// Copyright 2018 Generalov Aleksandr

#include "include/Cylinder.h"

#include <string>
#include <sstream>


const double pi = 3.14;


Cylinder::Cylinder(const double& _rad, const double& _h) {
    if (!negativeNumbers(_rad, _h)) {
        radius = _rad;
        h = _h;
    } else {
        throw std::string("Number can't be less then zero");
    }
}

double Cylinder::areaCyl() const {
    return 2 * pi * radius * h;
}

bool Cylinder::negativeNumbers(const double _rad, const double _h) {
    return _rad < 0 || _h < 0;
}
