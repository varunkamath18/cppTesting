#include <my_new_dummy_class.h>

int DummyClass::handleRequest1(int request, int context, Class1* mocker)
{
    Class1 obj1;
    Class1* ptr = &obj1;
    if (mocker)
    {
        ptr = mocker;
    }
    int rc = ptr->processFirstThing();
    if (rc != 0)
    {
        std::cout << "Error occurred" << std::endl;
        return -1;
    }

    rc = ptr->processSecondThing();
    if (rc != 0)
    {
        std::cout << "Error Occurred for 2nd thing. " << std::endl;
        return -2;
    }

    int response = 0;
    ptr->initializeResponse(&response);

    return response;
}

int DummyClass::handleRequest2(int request, int context, Class2* mocker)
{
    Class2 obj2;
    Class2* ptr2 = &obj2;
    if (mocker)
    {
        ptr2 = mocker;
    }

    int rc = ptr2->calcFirstThing();
    if (rc != 0)
    {
        std::cout << "Error occurred while calculating first thing. " << std::endl;
        return -1;
    } 

    rc = ptr2->calcSecondThing();
    if (rc != 0)
    {
        std::cout << "Error occurred while calculating second thing" << std::endl;
        return -2;
    }

    return 0;
}