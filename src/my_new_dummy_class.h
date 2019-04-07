#ifndef MY_NEW_DUMMY_CLASS
#define MY_NEW_DUMMY_CLASS
#include <iostream>
#include <my_class_1.h>
#include <my_class_2.h>

class DummyClass
{
    public:
    int handleRequest1(int request, int context, Class1* mocker=NULL);
    int handleRequest2(int request, int context, Class2* mocker=NULL);
};

#endif
