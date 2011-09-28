#include "DbConnections.h"
#include "DbControl.h"
#include "version.h"


DB::DB(string PathDb)
{
    Dbase = new XMLParser;
    Dbase -> LoadFile(PathDb);
    if(Dbase->IsLoadFile()==true)
    {
        Pr = new Prefs("config.conf");
        Db.resize(1);
        vector <string> G;
        vector <string> Tmp;
        Dbase -> GetTagValues("tg",G);
        Db[0] = G;
        vector <string>Ttmp,T;
        int tru = false;
        Dbase -> GetTagValues("entry",Tmp);
        Dbase -> GetTagValues("Session",T);
        Session = new SessionsStorage();
        if (T.size()>0){
            if (T[0].length()>0)
            {
                SessionsStorage S;
                Session->ConvertToSession(T[0],S);
                tru =Session->CheckSession(S);
            }
                }
        if (tru==0 or T[0].length()<0)
        {
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
            IsLoad = 1;
            if(Pr->GetPrefs("Lock_Session")=="true"){
            Session->LockSession();
            SaveDb();}
        }
    }
}
bool DB::IsLoaded()
{
    return IsLoad;
}
string DB::GetEntryById(int X, int Y)
{
    if(MaxX>=X and MaxY>=Y and IsLoad == 1)
    {
        PosX =X;
        PosY =Y;
        DbConnections C;
        string tmp =C.SearchConnection(Db[X][Y],*this,1,"");
        Dbase->ActiveChangeChar(tmp,1);
        return tmp;
    }
}
void DB::SetById(int X,int Y,string Value)
{
    if(IsLoad==1)
    {
        DbConnections C;
        if(MaxX>=X and MaxY>=Y)
            C.SearchConnection(Db[X][Y],*this,2,Value);
        else
        {
            if(MaxX<X)
            {
                int r = (X-MaxX);
                for(int i=0; i<r; i++)
                    CreateEntriesRow();
                C.SearchConnection(Db[X][Y],*this,2,Value);
            }
        }
    }
}
void DB::SetEntryById(int X,int Y,string Value)
{
    if(IsLoad==1)
    {
        if(MaxX>=X and MaxY>=Y)
        {
            Dbase->ActiveChangeChar(Value,0);
            Db[X][Y]=Value;
        }
        else
        {
            if(MaxX<X)
            {
                int r = (X-MaxX);
                for(int i=0; i<r; i++)
                    CreateEntriesRow();
                Dbase->ActiveChangeChar(Value,0);
                Db[X][Y]=Value;
            }
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
    if(IsLoad==1)
    {
        Db[X][Y].clear();
    }
}
void DB::DeleteEntriesRow(int X)
{
    if(IsLoad==1)
    {
        for(int i=0; i<MaxY; i++)
        {
            Db[X][i].clear();
        }
    }
}
void DB::CreateRow(string NameRow)
{
    if(IsLoad==1)
    {
        Db[0].push_back(NameRow);
        for(int i=1; i<MaxX+1; i++)
        {
            Db[i].push_back(" ");
        }
        MaxY++;
    }
}
void DB::SaveDb()
{
    Dbase -> SaveTag("db","!OPEN",0);
    Dbase -> SaveTag("header","!OPEN",1);
    Dbase -> SaveTag("Program","MiniDBXML",2);
    Dbase -> SaveTag("Version",AutoVersion::_FULLVERSION_STRING,2);
    if (Session->StatusSession()==0)
        Dbase ->SaveTag("Session","",2);
    else
    {
        ostringstream w;
        w<< Session->GetSessionID();
        Dbase ->SaveTag("Session",w.str(),2);
    }
    Dbase -> SaveTag("header","!CLOSE",1);
    Dbase -> SaveTag("tag","!OPEN",1);
    for(int i=0; i<MaxY; i++)
    {
        if (Db[0][i].length()>0)
            Dbase -> SaveTag("tg",Db[0][i],2);
    }
    Dbase -> SaveTag("tag","!CLOSE",1);
    Dbase -> SaveTag("body","!OPEN",1);
    for(int a=1; a<MaxX+1; a++)
    {
        Dbase -> SaveTag("entry","!OPEN",2);
        for(int c=0; c<MaxY; c++)
        {
            if (Db[a][c].length()>0)
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
DB::~DB()
{
    Session->UnlockSession();
    SaveDb();
    delete Session;
}

