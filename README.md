# cppTesting
This repository is to demonstrate using gtest and gmock.

# Source Code
The source code is a boiled down version of an application.
You have the following things:
* The Co-ordinator, DummyClass:
    This is the starting point of your application. It supports the following two methods:
    1. int request1(int, int)
    2. int request2(int, int)

* Business Logic:
    The business logic of the application is handled by the 2 main classes. Class1 and Class2.
    They don't have any external dependencies.
    * Class1:
      This class handles all of the processing for handling request1. However, the way to handle request1 is to perform the following things in order:

      1. int processFirstThing() -> returns 0 on sucess
      2. int processSecondThing() -> returns 0 on success
      3. void initializeResponse(int *response) -> assuming both things are processed, it will initialize the response with a positive number.

      You get a negative response for request1 if it fails at any point.

    * Class2:
        Very similar to Class 1, this class handles processing for request2. The following tasks need to be performed for request2. To handle request2, you need to perform the following tasks with Class2:
        1. int calcFirstThing() -> returns 0 on success
        2. int calcSecondThing() -> returns 0 on success

        Assuming both these calculations are successful, request 2 is considered successful and returns 0 

# Testing

Given the above information, testing this application comes down to the following:
* Unit tests for Class1 and Class2 respectively to ensure proper functioning.
* Unit tests for DummyClass mocking functionality of Class1 and Class2 respectively.