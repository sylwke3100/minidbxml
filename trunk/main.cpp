#include <iostream>
#include <cstdlib>
#include <vector>
#include "DbControl.h"
#include "XmlParser.h"
#include "DbSearch.h"
#include "UiCommandParser.h"
using namespace std;



int main()
{
    UiCommandParser Text;
    string str;
    while(getline(cin,str))
    {
        int Signal;
        Text.ParseCommand(str,Signal);
        if(Signal==1)
        {
            break;
        }
    }
}
