#include "DbControl.h"
#include "DbConnections.h"
#include "version.h"

DB::DB(string PathDb)
{
    Dbase = new XMLParser;
    Dbase -> LoadFile(PathDb);
    if(Dbase->IsLoadFile()==true)
    {
        Db.resize(1);
        vector <string> G;
        vector <string> Tmp;
        Dbase -> GetTagValues("tg",G);
        Db[0] = G;
        vector <string>Ttmp;
        Dbase -> GetTagValues("entry",Tmp);
        Db.resize(Tmp.size()+1);
        for(int z=0; z<Db[0].size(); z++)
        {
            Dbase->GetTagValues(Db[0][z],Ttmp);
            for(int i=1; i<Tmp.size()+1; i++)
            {
                Db[i].push_back(Ttmp[i-1]);
            }
            Ttmp.clear();
        }
        MaxX = Tmp.size();
        MaxY = Db[0].size();
        PathName = PathDb;
    }
}
string DB::GetEntryById(int X, int Y)
{
    if(MaxX>=X and MaxY>=Y)
    {
        PosX =X;
        PosY =Y;
        DbConnections C;
        return C.SearchConnection(Db[X][Y],*this);
    }
}
void DB::SetEntryById(int X,int Y,string Value)
{
    if(MaxX>=X and MaxY>=Y)
        Db[X][Y]=Value;
    else
    {
        if(MaxX<X)
        {
            int r = (X-MaxX);
            for(int i=0; i<r; i++)
                CreateEntriesRow();
            Db[X][Y]=Value;
        }
    }
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
void DB::DeleteEntry(int X,int Y)
{
    Db[X][Y].clear();
}
void DB::DeleteEntriesRow(int X)
{
    for(int i=0; i<MaxY; i++)
    {
        Db[X][i].clear();
    }
}
void DB::CreateRow(string NameRow)
{
    Db[0].push_back(NameRow);
    for(int i=1; i<MaxX+1; i++)
    {
        Db[i].push_back(" ");
    }
    MaxY++;
}
void DB::SaveDb()
{
    Dbase -> SaveTag("db","!OPEN",0);
    Dbase -> SaveTag("header","!OPEN",1);
    Dbase -> SaveTag("Program","MiniDBXML",2);
    Dbase -> SaveTag("Version",AutoVersion::_FULLVERSION_STRING,2);
    Dbase -> SaveTag("header","!CLOSE",1);
    Dbase -> SaveTag("tag","!OPEN",1);
    for(int i=0; i<MaxY; i++)
    {
        Dbase -> SaveTag("tg",Db[0][i],2);
    }
    Dbase -> SaveTag("tag","!CLOSE",1);
    Dbase -> SaveTag("body","!OPEN",1);
    for(int a=1; a<MaxX+1; a++)
    {
        Dbase -> SaveTag("entry","!OPEN",2);
        for(int c=0; c<MaxY; c++)
        {
            Dbase -> SaveTag(Db[0][c],Db[a][c],3);
        }
        Dbase -> SaveTag("entry","!CLOSE",2);

    }
    Dbase -> SaveTag("body","!CLOSE",1);
    Dbase -> SaveTag("db","!CLOSE",0);
    Dbase ->SaveFile();

}

string DB::GetPathName()
{
    return PathName;
}
