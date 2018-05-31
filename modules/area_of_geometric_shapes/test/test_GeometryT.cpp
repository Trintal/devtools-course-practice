// Copyright 2018 Levitsky Ilya

#include <gtest/gtest.h>

#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

#include "include/GeometryT.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class GeometryTTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    GeometryT app_;
    string output_;
};

TEST(GeometryTTest, Can_Calculate_Cone_Area) {
    //Arrange
    int argc = 3;
    double res = 0;
    vector<const char*> v = { "Cone", "2.1", "4.5" };
    const char** argv = v.data();
    Cone cone(2.1, 4.5);

    //Act
    res = cone.areaCone();

    //Assert
    EXPECT_EQ(res, 43.5425)
}

TEST(GeometryTTest, Cant_Calculate_Cone_Negative) {
    //Arrange
    int argc = 3;
    double res = 0;
    vector<const char*> v = { "Cone", "-2", "3" };
    const char** argv = v.data();
    Cone cone(-2, 3);

    //Act
    res = cone.areaCone();

    //Assert
    EXPECT_EQ(res, 0)
}


TEST(GeometryTTest, Can_Calculate_Cube_Area) {
    //Arrange
    int argc = 2;
    double res = 0;
    vector<const char*> v = { "Cube", "2" };
    const char** argv = v.data();
    Cube cube(2);

    //Act
    res = cube.areaCube();

    //Assert
    EXPECT_EQ(res, 24)
}

TEST(GeometryTTest, Cant_Calculate_Cube_Negative) {
    //Arrange
    int argc = 2;
    double res = 0;
    vector<const char*> v = { "Cube", "-2" };
    const char** argv = v.data();
    Cube cube(-2);

    //Act
    res = cube.areaCube();

    //Assert
    EXPECT_EQ(res, 0)
}

TEST(GeometryTTest, Can_Calculate_Cylinder_Area) {
    //Arrange
    int argc = 3;
    double res = 0;
    vector<const char*> v = { "Cylinder", "2", "3" };

    //Act
    res = cylinder.areaCyl();

    //Assert
    EXPECT_EQ(res, 37.68)
}

TEST(GeometryTTest, Cant_Calculate_Cylinder_Negative) {
    //Arrange
    int argc = 3;
    double res = 0;
    vector<const char*> v = { "Cylinder", "-2", "3" };

    //Act
    res = cylinder.areaCyl();

    //Assert
    EXPECT_EQ(res, 0)
}

TEST(GeometryTTest, Can_Calculate_Sphere_Area) {
    //Arrange
    int argc = 2;
    double res = 0;
    vector<const char*> v = { "Sphere", "2" };

    //Act
    res = sphere.areaSph();

    //Assert
    EXPECT_EQ(res, 50.24)
}

TEST(GeometryTTest, Cant_Calculate_Sphere_Negative) {
    //Arrange
    int argc = 2;
    double res = 0;
    vector<const char*> v = { "Sphere", "-2" };

    //Act
    res = sphere.areaSph();

    //Assert
    EXPECT_EQ(res, 0)
}
