#include <my_class_1.h>
#include <my_class_2.h>
#include "gtest/gtest.h"

#include "gmock/gmock.h"

class MockClass1: public Class1
{
public:
    MOCK_METHOD0(processFirstThing, int());
    MOCK_METHOD0(processSecondThing, int());
    MOCK_METHOD1(initializeResponse, void (int* response));
};

class MockClass2: public Class2
{
public:
    MOCK_METHOD0(calcFirstThing, int());
    MOCK_METHOD0(calcSecondThing, int());
};