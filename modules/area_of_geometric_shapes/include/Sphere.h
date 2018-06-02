// Copyright 2018 Generalov Aleksandr

#ifndef MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_SPHERE_H_
#define MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_SPHERE_H_

class Sphere {
 public:
    Sphere();
    explicit Sphere(const double& _rad);
    Sphere(const Sphere& _s);

    double areaSph() const;
 private:
    bool negativeNumbers(const double _radius);
    double radius;
};

#endif  // MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_SPHERE_H_
