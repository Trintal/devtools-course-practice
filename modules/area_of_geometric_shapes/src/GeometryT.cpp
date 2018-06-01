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

void GeometryT::help(const char* appname, const char* message) {
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

int parseFigure(int argc, const char* argv) {
    if (argv[1] == const_cast<char*>("Cone")) {
        return 1;
    } else if (argv[1] == const_cast<char*>("Cylinder")) {
        return 2;
    } else if (argv[1] == const_cast<char*>("Sphere")) {
        return 3;
    } else if (argv[1] == const_cast<char*>("Cube")) {
        return 4;
    } else {
        throw std::string("Wrong figure format!");
    }
}

std::string GeometryT::operator()(int argc, const char** argv) {
    Arguments args;

    if (!parseDouble(argc, argv)) {
        return message_;
    }

    if (argc == 3) {
        try {
            args.figure = parseFigure(argc, argv[1]);
            args.radius = strtod(argv[2], NULL);
        }
        catch (std::string& str) {
            return str;
        }
    } else {
        try {
            args.figure = parseFigure(argc, argv[1]);
            args.radius = strtod(argv[2], NULL);
            args.height = strtod(argv[3], NULL);
        }
        catch (std::string& str) {
            return str;
        }
    }


    std::ostringstream stream;

    switch (args.figure) {
    case 1: {
        Cone cone(args.radius, args.height);
        double res = cone.areaCone();
        stream << "Area of cone: " << res;
        break; }
    case 2: {
        Cylinder cylinder(args.radius, args.height);
        double res = cylinder.areaCyl();
        stream << "Area of cylinder: " << res;
        break; }
    case 3: {
        Sphere sphere(args.radius);
        double res = sphere.areaSph();
        stream << "Area of sphere: " << res;
        break; }
    case 4: {
        Cube cube(args.radius);
        double res = cube.areaCube();
        stream << "Area of cube: " << res;
        break; }
    }

    message_ = stream.str();

    return message_;
}
