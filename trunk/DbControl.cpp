#include "DbControl.h"
#include "version.h"

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
string DB::GetEntryById(int X, int Y)
{
    return Db[X][Y];
}
void DB::SetEntryById(int X,int Y,string Value)
{
    if(MaxX>=X and MaxY>=Y)
        Db[X][Y]=Value;
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
    for(int i=1;i<MaxX+1;i++)
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
    for(int i=0; i<MaxY;i++)
    {
        Dbase -> SaveTag("tg",Db[0][i],2);
    }
    Dbase -> SaveTag("tag","!CLOSE",1);
    Dbase -> SaveTag("body","!OPEN",1);
    for(int a=1;a<MaxX+1;a++)
    {
        Dbase -> SaveTag("entry","!OPEN",2);
        for(int c=0;c<MaxY;c++)
        {
            Dbase -> SaveTag(Db[0][c],Db[a][c],3);
        }
        Dbase -> SaveTag("entry","!CLOSE",2);

    }
    Dbase -> SaveTag("body","!CLOSE",1);
    Dbase -> SaveTag("db","!CLOSE",0);
    Dbase ->SaveFile();

}


