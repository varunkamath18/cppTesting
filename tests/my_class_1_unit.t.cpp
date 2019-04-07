#include <my_class_1.h>
#include "gtest/gtest.h"

#include <iostream>

class Class1Test: public ::testing::Test
{
protected:
    Class1* first;
    void SetUp()
    {
        // std::cout << "Set up: Class1Test" << std::endl;
        first = new Class1();
    }
    void TearDown()
    {
        // std::cout << "Tear Down: Class1Test" << std::endl;
        delete first;
    }
};

TEST_F(Class1Test, testFirstThing)
{
    int rc = first->processFirstThing();
    ASSERT_EQ(rc, 0);
}

TEST_F(Class1Test, testSecondThing)
{
    int rc = first->processSecondThing();
    ASSERT_EQ(rc, 0);
}

TEST_F(Class1Test, testInitializeResponse)
{
    int response = 0;
    first->initializeResponse(&response);

    ASSERT_EQ(response, 1);
}

