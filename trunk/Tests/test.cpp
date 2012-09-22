#include "TestValue.h"
#include "../Ui/UiCommandParser.h"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    UiCommandParser P;
    TestValue Test(P.PrepareToParse("command cmd cmdddd"));
    Test.runTests(3);

}
