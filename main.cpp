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

    /*  cout<<"Ladowanie bazy\n";
      DB * base = new DB("a.xml");
      cout<<"Ladowanie bazy2\n";
      cout<<base->GetEntryById(1,0);
      vector <string> Elo;
      DbSearch Szukaj;
      Szukaj.SetSearchValue("s");
      Szukaj.SearchInDb(base,Elo);
      cout<<"Szukanie\n";
      cout<<"Wyniki wyszukiwania:\n";
      for(int i=0; i<Elo.size(); i++)
      {
          cout<<Elo[i]<<"\n";
      }
    */
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
