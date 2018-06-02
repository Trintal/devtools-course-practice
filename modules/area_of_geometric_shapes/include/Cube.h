// Copyright 2018 Generalov Aleksandr

#ifndef MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CUBE_H_
#define MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CUBE_H_

class Cube {
 public:
    Cube();
    explicit Cube(const double& _h);
    Cube(const Cube& _c);

    double areaCube() const;
 private:
    bool negativeNumbers(const double _h);
    double h;
};

#endif  // MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CUBE_H_
