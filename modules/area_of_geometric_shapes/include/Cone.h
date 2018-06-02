// Copyright 2018 Generalov Aleksandr

#ifndef MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CONE_H_
#define MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CONE_H_

class Cone {
 public:
    Cone();
    Cone(const double& _rad, const double& _h);
    Cone(const Cone& _c);

    double areaCone() const;
 private:
    bool negativeNumbers(const double _rad, const double _h);
    double radius;
    double h;
};

#endif  // MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CONE_H_
