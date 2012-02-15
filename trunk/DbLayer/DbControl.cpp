#include "DbConnections.h"
#include "DbControl.h"
#include "../version.h"


DB::DB(string PathDb)
{
    Dbase = new XMLParser;
    Dbase -> LoadFile(PathDb);
    if(Dbase->IsLoadFile()==1)
    {
        Pr = new Prefs("config.conf");
        Db.resize(1);
        vector <string> ap,G,Tmp,Ttmp,T;
        Dbase->GetTagValues("Version",ap);
        if(ap.size()>0)
            if(ap[0] == "0.0.7 - Alpha")
                Dbase->ConvertStandard();

        Dbase -> GetTagValues("tg",G);
        Db[0] = G;
        int tru = false;
        Dbase -> GetTagValues("entry",Tmp);
        Dbase -> GetTagValues("Session",T);
        Session = new SessionsStorage();
        if (T.size()>0)
        {
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
            if(Pr->GetPrefs("Lock_Session")=="true")
            {
                Session->LockSession();
                SaveDb();
            }
        }
    }
    else IsLoad =0;
}
bool DB::IsLoaded()
{
    return Dbase->IsLoadFile();
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
    else return "";
}
void DB::SetById(int X,int Y,string Value)
{
    if(IsLoad==1)
    {
        DbConnections C;
        if(MaxX>=X and MaxY>=Y)
            if(C.SearchConnection(Db[X][Y],*this,2,Value)=="NO_TO_SET")
                Db[X][Y]=Value;
            else
            {
                if(MaxX<X)
                {
                    int r = (X-MaxX);
                    for(int i=0; i<r; i++)
                        CreateEntriesRow();
                    if(C.SearchConnection(Db[X][Y],*this,2,Value)=="NO_TO_SET")
                        Db[X][Y]=Value;
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
                Db[X][Y]=Value;;
            }
        }
        if (Pr->GetPrefs("Autosave")=="true")
        {
            SaveDb();
        }
    }
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
        Db[X][Y].clear();
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
    Dbase -> SaveTag("db","!OPEN");
    Dbase -> SaveTag("header","!OPEN");
    Dbase -> SaveTag("Program","MiniDBXML");
    Dbase -> SaveTag("Version",AutoVersion::_FULLVERSION_STRING);
    if (Session->StatusSession()==0)
        Dbase ->SaveTag("Session","");
    else
    {
        ostringstream w;
        w<< Session->GetSessionID();
        Dbase ->SaveTag("Session",w.str());
    }
    Dbase -> SaveTag("header","!CLOSE");
    Dbase -> SaveTag("tag","!OPEN");
    for(int i=0; i<MaxY; i++)
    {
        if (Db[0][i].length()>0)
            Dbase -> SaveTag("tg",Db[0][i]);
    }
    Dbase -> SaveTag("tag","!CLOSE");
    Dbase -> SaveTag("body","!OPEN");
    for(int a=1; a<MaxX+1; a++)
    {
        Dbase -> SaveTag("entry","!OPEN");
        for(int c=0; c<MaxY; c++)
        {
            if (Db[a][c].length()>0)
                Dbase -> SaveTag(Db[0][c],Db[a][c]);
        }
        Dbase -> SaveTag("entry","!CLOSE");

    }
    Dbase -> SaveTag("body","!CLOSE");
    Dbase -> SaveTag("db","!CLOSE");
    Dbase ->SaveFile();

}

string DB::GetPathName()
{
    return PathName;
}
DB::~DB()
{
    if(Pr->GetPrefs("Lock_Session")=="true")
        Session->UnlockSession();
    SaveDb();

    delete Session;
}

