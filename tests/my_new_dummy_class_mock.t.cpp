#include <my_new_dummy_class.h>

#include <mock_my_classes.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::AtLeast;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::_;

class DummyClassTest: public ::testing::Test
{
public:
    DummyClass *dummy;
    void SetUp()
    {
        dummy = new DummyClass();
    }
    void TearDown()
    {
        delete dummy;
    }
};

TEST_F(DummyClassTest, testHandleRequest1)
{
    MockClass1 obj1;
    EXPECT_CALL(obj1, processFirstThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(0));

    EXPECT_CALL(obj1, processSecondThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(0));

    EXPECT_CALL(obj1, initializeResponse(_))
    .Times(AtLeast(1));

    int rc = dummy->handleRequest1(1,2, &obj1);

    ASSERT_EQ(rc, 0);
}


TEST_F(DummyClassTest, testHandleRequest1Fail1)
{
    MockClass1 obj1;
    EXPECT_CALL(obj1, processFirstThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(1));

    int rc = dummy->handleRequest1(1,2, &obj1);

    ASSERT_EQ(rc, -1);
}


TEST_F(DummyClassTest, testHandleRequest1Fail2)
{
    MockClass1 obj1;
    EXPECT_CALL(obj1, processFirstThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(0));

    EXPECT_CALL(obj1, processSecondThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(1));


    int rc = dummy->handleRequest1(1,2, &obj1);

    ASSERT_EQ(rc, -2);
}

struct InitializeResponseDummy
{
public:
void init(int* resp)
{
    *resp = 5;
}
};

TEST_F(DummyClassTest, testHandleRequest1Fail3)
{
    MockClass1 obj1;
    EXPECT_CALL(obj1, processFirstThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(0));

    EXPECT_CALL(obj1, processSecondThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(0));

    InitializeResponseDummy dum;
    EXPECT_CALL(obj1, initializeResponse(_))
    .Times(AtLeast(1))
    .WillRepeatedly(Invoke(&dum, &InitializeResponseDummy::init));

    int rc = dummy->handleRequest1(1,2, &obj1);

    ASSERT_EQ(rc, 5);
}


TEST_F(DummyClassTest, testHandleRequest1Orig)
{
    MockClass1 obj1;
    EXPECT_CALL(obj1, processFirstThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(0));

    EXPECT_CALL(obj1, processSecondThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(0));

    Class1 orig;
    EXPECT_CALL(obj1, initializeResponse(_))
    .Times(AtLeast(1))
    .WillRepeatedly(Invoke(&orig, &Class1::initializeResponse));

    int rc = dummy->handleRequest1(1,2, &obj1);

    ASSERT_EQ(rc, 1);
}

TEST_F(DummyClassTest, testHandleRequest2)
{
    MockClass2 obj2;
    EXPECT_CALL(obj2, calcFirstThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(0));

    EXPECT_CALL(obj2, calcSecondThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(0));

    int rc = dummy->handleRequest2(1,2, &obj2);

    ASSERT_EQ(rc, 0);
}

TEST_F(DummyClassTest, testHandleRequest2Fail1)
{
    MockClass2 obj2;
    EXPECT_CALL(obj2, calcFirstThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(1));

    int rc = dummy->handleRequest2(1,2, &obj2);

    ASSERT_EQ(rc, -1);
}

TEST_F(DummyClassTest, testHandleRequest2Fail2)
{
    MockClass2 obj2;
    EXPECT_CALL(obj2, calcFirstThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(0));

    EXPECT_CALL(obj2, calcSecondThing())
    .Times(AtLeast(1))
    .WillRepeatedly(Return(2));

    int rc = dummy->handleRequest2(1,2, &obj2);

    ASSERT_EQ(rc, -2);
}