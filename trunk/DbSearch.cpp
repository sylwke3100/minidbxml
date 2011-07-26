#include "DbSearch.h"


void DbSearch::SearchInDb(DB* Base,string NameValue, vector<string>& Summary)
{
    for(int x=1;x<Base->GetMaxX()+1;x++)
    {
        for(int y=0;y<Base->GetMaxY();y++)
        {
            string Value = Base ->GetEntryById(x,y);
            for(int i=0;i<Value.length();i++)
            {
                if(Value.substr(i,NameValue.length())==NameValue)
                {
                    Summary.push_back(Value);
                    break;
                }
            }
        }
    }
}
