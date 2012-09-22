#include "TestValue.h"

TestValue::TestValue(vector <string> Vect)
{
    Values = Vect;
}

TestValue::~TestValue()
{
    //delete Values;
}
void TestValue::runTests(int type)
{
    switch(type){
        case 1:
        checkSize();
        break;
        case 2:
        checkNoEmptyValues();
        break;
        case 3:
        checkSize();
        checkNoEmptyValues();
        break;
    }
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
