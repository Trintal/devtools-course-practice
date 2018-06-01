// Copyright 2018 Levitsky Ilya

#ifndef MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_GEOMETRYT_H_
#define MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_GEOMETRYT_H_

#include <string>

class GeometryT {
 public:
    GeometryT();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    std::string message_;
    typedef struct {
        const char* figure;
        double radius;
        double height;
    } Arguments;
};

#endif  // MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_GEOMETRYT_H_
