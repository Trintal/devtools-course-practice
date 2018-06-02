// Copyright 2018 Generalov Aleksandr

#include "include/Sphere.h"

#include <string>

const double pi = 3.14;


Sphere::Sphere(const double& _rad) {
    if (!negativeNumbers(_rad))
        radius = _rad;
    else
        throw std::string("Number can't be less then zero");
}

double Sphere::areaSph() const {
    return 4 * pi * radius * radius;
}

bool Sphere::negativeNumbers(const double _radius) {
    return _radius < 0;
}
