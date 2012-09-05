#include "TestValue.h"

TestValue::TestValue(vector <string> Vect)
{
    Values = Vect;
}

TestValue::~TestValue()
{
    //delete Values;
}
void TestValue::runTest()
{
    checkSize();
    checkNoEmptyValues();
}
void TestValue::checkSize()
{
    cout<<Values.size()<<endl;
}
void TestValue::checkNoEmptyValues()
{
    for(int i =0; i<Values.size(); i++)
    {
        if(Values[i].length()>0) cout<<"True"<<" - "<<Values[i]<<endl;
        else cout<<"False"<<endl;
    }
}
