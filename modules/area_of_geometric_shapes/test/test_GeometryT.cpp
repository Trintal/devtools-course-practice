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

TEST_F(GeometryTTest, Do_Print_Help_No_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is calculation of area of geometric figures application\\..*");
}

TEST_F(GeometryTTest, Can_Calculate_Cone_Area) {
    vector<string> args = { "Cone", "2", "3" };

    Act(args);

    Assert("Area of cone: 31,41592653589793238463");
}

TEST_F(GeometryTTest, Cant_Calculate_Cone_Negative) {
    vector<string> args = { "Cone", "-2", "3" };

    Act(args);

    Assert("Number can't be less then zero");
}


TEST_F(GeometryTTest, Can_Calculate_Cube_Area) {
    vector<string> args = { "Cube", "2" };

    Act(args);

    Assert("Area of cube: 24");
}

TEST_F(GeometryTTest, Cant_Calculate_Cube_Negative) {
    vector<string> args = { "Cube", "-2" };

    Act(args);

    Assert("Number can't be less then zero");
}

TEST_F(GeometryTTest, Can_Calculate_Cylinder_Area) {
    vector<string> args = { "Cylinder", "2", "3" };

    Act(args);

    Assert("Area of cylinder: 37,699111843077518861556");
}

TEST_F(GeometryTTest, Cant_Calculate_Cylinder_Negative) {
    vector<string> args = { "Cylinder", "-2", "3" };

    Act(args);

    Assert("Number can't be less then zero");
}

TEST_F(GeometryTTest, Can_Calculate_Sphere_Area) {
    vector<string> args = { "Sphere", "2" };

    Act(args);

    Assert("Area of sphere: 50,265482457436691815408");
}

TEST_F(GeometryTTest, Cant_Calculate_Sphere_Negative) {
    vector<string> args = { "Sphere", "-2" };

    Act(args);

    Assert("Number can't be less then zero");
}
