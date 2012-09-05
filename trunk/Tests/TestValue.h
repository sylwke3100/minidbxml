#ifndef TESTVALUE_H
#define TESTVALUE_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;



class TestValue
{
public:
    TestValue(vector <string> Vect);
    void runTest();
    void checkSize();
    void checkNoEmptyValues();
    virtual ~TestValue();
private:
    vector <string> Values;
};

#endif // TESTVALUE_H
