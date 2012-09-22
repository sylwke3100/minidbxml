#ifndef TESTVALUE_H
#define TESTVALUE_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#define checksize 1
#define checkempty 2
#define all 3
using namespace std;



class TestValue
{
public:
    TestValue(vector <string> Vect);
    void runTests(int type);
    void checkSize();
    void checkNoEmptyValues();
    virtual ~TestValue();
private:
    vector <string> Values;
};

#endif // TESTVALUE_H
