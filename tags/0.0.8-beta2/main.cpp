#include <iostream>
#include <cstdlib>
#include <vector>
#include "DbControl.h"
#include "XmlParser.h"
#include "DbSearch.h"
#include "UiCommandParser.h"
using namespace std;



int main(int argc,char *argv[])
{
    UiCommandParser* Text = new UiCommandParser();
    if(argc>1)
    {
        Text->ReadCommandFromFile(argv[1]);
    }
    else
    {
        string str;
        Text->Info();
        while(getline(cin,str))
        {
            int Signal;
            Text->ParseCommand(str,Signal);
            if(Signal==1)
            {
                break;
            }
            cout<<">>";
        }
    }
}
