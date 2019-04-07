#include <iostream>

#include <my_new_dummy_class.h>

int main(int argc, char* argv[])
{
    DummyClass dummy;

    std::cout << dummy.handleRequest1(1, 2) << std::endl;
    std::cout << dummy.handleRequest2(5, 5) << std::endl;

    return 0;
}