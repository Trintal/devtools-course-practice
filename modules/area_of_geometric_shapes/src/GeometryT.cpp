// Copyright 2017 Levitsky Ilya

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdint>

#include "include/GeometryT.h"
#include "include/Cone.h"
#include "include/Cube.h"
#include "include/Cylinder.h"
#include "include/Sphere.h"

GeometryT::GeometryT() : message_("") {}

void GeometryT::help(const char* appname, const char* message = "") {
    message_ =
        std::string(message) +
        "Please provide arguments in the following format : \n\n"

        " $" + appname +
        "Name of figure <Cone/Cube/Cylinder/Sphere>" +
        "<radius> <height> for Cylinder and Cone \n" +
        "Or <radius> for Sphere and Cube. \n\n" +

        "Where arguments are real positive numbers. \n\n";
}

bool parseDouble(int argc, const char** argv) {
    if (argc < 3 || argc > 4) {
        throw std::string("Wrong number format!");
        help(argv[0]);
    }

    return false;
}

//  int parseFigure(int argc, const char* argv) {
//    if (strcmp(argv[1], "Cone") == 0) {
//        return 1;
//    } else if (strcmp(argv[1], "Cylinder") == 0) {
//        return 2;
//    } else if (strcmp(argv[1], "Sphere") == 0) {
//        return 3;
//    } else if (strcmp(argv[1], "Cube") == 0) {
//        return 4;
//    } else {
//        throw std::string("Wrong figure format!");
//    }
//  }

std::string GeometryT::operator()(int argc, const char** argv) {
    Arguments args;

    if (!parseDouble(argc, argv)) {
        return message_;
    }

    if (argc == 3) {
        try {
            args.figure = argv[1];
            args.radius = strtod(argv[2], NULL);
        }
        catch (std::string& str) {
            return str;
        }
    } else {
        try {
            args.figure = argv[1];
            args.radius = strtod(argv[2], NULL);
            args.height = strtod(argv[3], NULL);
        }
        catch (std::string& str) {
            return str;
        }
    }


    std::ostringstream stream;

    if (strcmp(args.figure, "Cone") == 0) {
        Cone cone(args.radius, args.height);
        double res = cone.areaCone();
        stream << "Area of cone: " << res;
    } else if (strcmp(args.figure, "Cylinder") == 0) {
        Cylinder cylinder(args.radius, args.height);
        double res = cylinder.areaCyl();
        stream << "Area of cylinder: " << res;
    } else if (strcmp(args.figure, "Sphere") == 0) {
        Sphere sphere(args.radius);
        double res = sphere.areaSph();
        stream << "Area of sphere: " << res;
    } else if (strcmp(args.figure, "Cube") == 0) {
        Cube cube(args.radius);
        double res = cube.areaCube();
        stream << "Area of cube: " << res;
    }

    message_ = stream.str();

    return message_;
}
