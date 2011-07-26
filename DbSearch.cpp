#include "DbSearch.h"


void DbSearch::SearchInDb(DB* Base, vector<string>& Summary)
{
    for(int x=1; x<Base->GetMaxX()+1; x++)
    {
        for(int y=0; y<Base->GetMaxY(); y++)
        {
            string Value = Base ->GetEntryById(x,y);
                if((int)Value.find(NameValue)>-1)
                {
                    Summary.push_back(Value);
                }
        }
    }
}
void DbSearch::SetSearchValue(string NameValue)
{
    this->NameValue= NameValue;
}
