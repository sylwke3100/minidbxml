#include "DbSearch.h"


void DbSearch::SearchInDb(DB* Base, vector<string>& Summary)
{
    if(NameValue.length()>0)
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
}
void DbSearch::SearchInColumn(string NameColumn,DB* Base, vector<string>& Summary)
{
    if(NameValue.length()>0 && NameColumn.length()>0)
    {
        int Id = -1;
         for(int x=0; x<Base->GetMaxX(); x++)
        {
            if (Base->GetEntryById(x,0)==NameColumn){Id = x;break;}
        }
        if(Id>-1)
        {
            for(int y=0;y<Base->GetMaxY()+1;y++)
            {
                 string Value = Base ->GetEntryById(Id,y);
                if((int)Value.find(NameValue)>-1)
                {
                    Summary.push_back(Value);
                }
            }
        }
    }
}
void DbSearch::SetSearchValue(string NameValue)
{
    this->NameValue= NameValue;
}
