#include "DbControl.h"

DB::DB(string PathDb)
{
    Dbase = new XMLParser;
    Dbase -> LoadFile(PathDb);
    if(Dbase->IsLoadFile()==true)
    {
        Db.resize(1);
        Db[0] = Dbase -> GetTagValues("tg");
        vector <string> Tmp;
        vector <string>Ttmp;
        Tmp = Dbase -> GetTagValues("entry");
        Db.resize(Tmp.size()+1);
        for(int z=0; z<Db[0].size(); z++)
        {
            Ttmp = Dbase->GetTagValues(Db[0][z]);
            for(int i=1; i<Tmp.size()+1; i++)
            {
                Db[i].push_back(Ttmp[i-1]);
            }
            Ttmp.clear();
        }
        MaxX = Tmp.size();
        MaxY = Db[0].size();
    }
}
string DB::GetEntryById(int x, int y)
{
    return Db[x][y];
}
void DB::SetEntryById(int x,int y,string Value)
{
    if(MaxX>=x and MaxY>=y)
        Db[x][y]=Value;
}
int DB::GetMaxX()
{
    return MaxX;
}
int DB::GetMaxY()
{
    return MaxY;
}
void DB::CreateEntriesRow()
{
    Db.resize(Db.size()+1);
    MaxX++;
    for(int i=0; i<MaxY+1; i++)
    {
        Db[MaxX].push_back(" ");
    }
}
void DB::DeleteEntry(int x,int y)
{
    Db[x][y].clear();
}






