#include <my_class_2.h>
#include "gtest/gtest.h"

#include <iostream>

class Class2Test: public ::testing::Test
{
protected:
    Class2 *second;
    void SetUp()
    {
        second = new Class2();
    }
    void TearDown()
    {
        delete second;
    }
};

TEST_F(Class2Test, testCalcFirst)
{
    int rc = second->calcFirstThing();
    ASSERT_EQ(rc, 0);
}

TEST_F(Class2Test, testCalcSecond)
{
    int rc = second->calcSecondThing();
    ASSERT_EQ(rc, 0);
}
