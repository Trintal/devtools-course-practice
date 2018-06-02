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

    Assert("Usage:*");
}

TEST_F(GeometryTTest, Can_Calculate_Cone_Area) {
    vector<string> args = { "-n", "2.1", "4.5" };

    Act(args);

    Assert("Area = 43.5204");
}

TEST_F(GeometryTTest, Cant_Calculate_Cone_Negative) {
    vector<string> args = { "-n", "-2", "3" };

    Act(args);

    Assert("Number can't be less then zero");
}


TEST_F(GeometryTTest, Can_Calculate_Cube_Area) {
    vector<string> args = { "-b", "2" };

    Act(args);

    Assert("Area = 24");
}

TEST_F(GeometryTTest, Cant_Calculate_Cube_Negative) {
    vector<string> args = { "-b", "-2" };

    Act(args);

    Assert("Number can't be less then zero");
}

TEST_F(GeometryTTest, Can_Calculate_Cylinder_Area) {
    vector<string> args = { "-c", "2", "3" };

    Act(args);

    Assert("Area = 37,68");
}

TEST_F(GeometryTTest, Cant_Calculate_Cylinder_Negative) {
    vector<string> args = { "-c", "-2", "3" };

    Act(args);

    Assert("Number can't be less then zero");
}

TEST_F(GeometryTTest, Can_Calculate_Sphere_Area) {
    vector<string> args = { "-s", "2" };

    Act(args);

    Assert("Area = 50,24");
}

TEST_F(GeometryTTest, Cant_Calculate_Sphere_Negative) {
    vector<string> args = { "-s", "-2" };

    Act(args);

    Assert("Number can't be less then zero");
}
