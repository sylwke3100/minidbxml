#include <iostream>
#include <cstdlib>
#include <vector>
#include "./DbLayer/DbControl.h"
#include "./XmlParser/XmlParser.h"
#include "./DbLayer/DbSearch.h"
#include "./Ui/UiCommandParser.h"
using namespace std;


int main(int argc,char *argv[])
{
    UiCommandParser* Text = new UiCommandParser();
    Prefs* Pr = new Prefs("config.conf");
    if(argc>1 && Pr->GetPrefs("Allow_Read_From_File")=="true")
        Text->ReadCommandFromFile(argv[1]);
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
