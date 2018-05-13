// Copyright 2018 Levitsky Ilya

#include <gtest/gtest.h>

#include "include/set.h"

TEST(Levitsky_Ilya_setTest, Can_Create_Set) {
  // Arrange
  set A;

  // Act
  A.Insert(5);

  // Assert
  EXPECT_EQ(5, A.GetN(5));
}

TEST(Levitsky_Ilya_setTest, Disjunctio_Sets) {
  // Arrange
  set A;
  set B;
  set C;

  A.Insert(4);
  B.Insert(7);

  // Act
  C = A + B;

  // Assert
  EXPECT_EQ(4, C.GetN(4));
  EXPECT_EQ(7, C.GetN(7));
}

TEST(Levitsky_Ilya_setTest, Conjuctio_Sets) {
  // Arrange
  set A;
  set B;
  set C;

  A.Insert(2);
  A.Insert(4);
  A.Insert(6);

  B.Insert(3);
  B.Insert(4);
  B.Insert(9);
  B.Insert(6);

  // Act
  C = A*B;

  // Assert
  EXPECT_EQ(4, C.GetN(4));
  EXPECT_EQ(6, C.GetN(6));
}

TEST(Levitsky_Ilya_setTest, Addition_Set) {
  // Arrange
  set A;
  set C;

  A.Insert(5);
  A.Insert(4);
  A.Insert(6);
  A.Insert(3);
  A.Insert(2);

  // Act
  C = ~A;

  // Assert
  EXPECT_EQ(1, C.GetN(1));
  EXPECT_EQ(7, C.GetN(7));
  EXPECT_EQ(8, C.GetN(8));
  EXPECT_EQ(9, C.GetN(9));
  EXPECT_EQ(10, C.GetN(10));
}

TEST(Levitsky_Ilya_setTest, Can_Get_Bit) {
    // Arrange
    set A;

    // Act
    A.Insert(5);

    // Assert
    EXPECT_EQ(256, A.Get(5));
}

TEST(Levitsky_Ilya_setTest, Can_Assign_Set) {
    // Arrange
    set A;
    set B;

    // Act
    A.Insert(5);
    A.Insert(6);
    A.Insert(2);

    B = A;

    // Assert
    EXPECT_EQ(5, B.GetN(5));
    EXPECT_EQ(6, B.GetN(6));
    EXPECT_EQ(2, B.GetN(2));
}

TEST(Levitsky_Ilya_setTest, Can_Not_Get_Num) {
    // Arrange
    set A;

    // Act
    A.Insert(5);

    // Assert
    EXPECT_EQ(0, A.GetN(4));
}

TEST(Levitsky_Ilya_setTest, Dif_Disjunctio_Sets) {
    // Arrange
    set A;
    set B;
    set C;

    A.Insert(4);
    B.Insert(7);
    B.Insert(5);

    // Act
    C = A + B;

    // Assert
    EXPECT_EQ(4, C.GetN(4));
    EXPECT_EQ(7, C.GetN(7));
    EXPECT_EQ(5, C.GetN(5));
}

TEST(Levitsky_Ilya_setTest, Can_Copy) {
    // Arrange
    set A;

    // Act
    A.Insert(5);
    set B(A);

    // Assert
    EXPECT_EQ(5, B.GetN(5));
}
class SetTest : public ::testing::Test {
protected:
    // virtual void SetUp() {}

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
    Set A;
    string output_;
};
