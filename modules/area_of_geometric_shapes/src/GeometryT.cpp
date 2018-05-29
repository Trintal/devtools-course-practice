// Copyright 2017 Levitsky Ilya

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <cstring>

#include "include/GeometryT.h"
#include "include/Cone.h"
#include "include/Cube.h"
#include "include/Cylinder.h"
#include "include/Sphere.h"

GeometryT::GeometryT() : message_("") {}

void GeometryT::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a area of geometric figure.\n\n" +
        "Please provide arguments in the following format : \n\n"

        " $" + appname + " <radius> <height> for Cylinder and Cone \n" +
        "Or <radius/height> for Sphere and Cube. \n\n" +

        "Where arguments are real positive numbers. \n\n";
}

bool GeometryT::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc > 4) {
        help(argv[0], "ERROR: Should be not more than 3 arg");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int parseFigure(const char* arg) {
    if (strcmp(arg, "Cone") == 0) {
        return 1;
    } else if (strcmp(arg, "Cylinder") == 0) {
        return 2;
    } else if (strcmp(arg, "Sphere") == 0) {
        return 3;
    } else if (strcmp(arg, "Cube") == 0) {
        return 4;
    } else {
        throw std::string("Wrong figure format!");
    }
}

std::string GeometryT::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    if (argc == 3) {
        try {
            args.figure = parseFigure(argv[1]);
            args.radius = parseDouble(argv[2]);
        }
        catch (std::string& str) {
            return str;
        }
    } else {
        try {
            args.figure = parseFigure(argv[1]);
            args.radius = parseDouble(argv[2]);
            args.height = parseDouble(argv[3]);
        }
        catch (std::string& str) {
            return str;
        }
    }

	double res = 0;

    std::ostringstream stream;

    switch (args.figure) {
    case 1:
            Cone cone(args.radius, args.height);
            res = cone.areaCone();
            stream << "Area of cone: " << res;
            break;
    case 2:
            Cylinder cyliner(args.radius, args.height);
            res = cylinder.areaCyl();
            stream << "Area of cylinder: " << res;
            break;
    case 3:
            Sphere sphere(args.radius);
            res = sphere.areaSph();
            stream << "Area of sphere: " << res;
            break;
    case 4:
            Cube cube(args.radius);
            res = cube.areaCube();
            stream << "Area of cube: " << res;
            break;
    }

    message_ = stream.str();

    return message_;
}
