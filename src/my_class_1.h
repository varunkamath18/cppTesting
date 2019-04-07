#ifndef MY_CLASS_1
#define MY_CLASS_1

class Class1 {
public:
    virtual int processFirstThing();
    virtual int processSecondThing();
    virtual void initializeResponse(int* response);
    virtual ~Class1(){};
};

#endif
