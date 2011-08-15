#include "DbConnections.h"
#include "DbControl.h"

string DbConnections::SearchConnection(string DbValue,DB& B,int Type,string Value)
{
    for(int i=0; i<DbValue.length(); i++)
    {
        if((int)DbValue.find("^(",i)>=0 && (int)DbValue.find(",",i)>=0 && (int)DbValue.find(")",i)>=0)
        {
            int a = (int)DbValue.find("^(",i)+2,b = (int)DbValue.find(",",i),c = (int)DbValue.find(")",i),d,e;
            istringstream k (DbValue.substr(a,(b-a)));
            istringstream z(DbValue.substr(b+1,(c-(b+1))));
            k >> d;
            z >>e;
            if (Type ==1)
                return GetNormalConnect(d,e,B);
            else
                SetNormalConEntry(Value,B,d,e);
        }
        if((int)DbValue.find("#(")>=0 &&  (int)DbValue.find(",",i)>=0 && (int)DbValue.find(",|",i)>=0 && (int)DbValue.find("|)",i)>=0)
        {
            int a = (int)DbValue.find("#(",i)+2,b = (int)DbValue.find(",",i),c = (int)DbValue.find(",|",i),d,e;
            istringstream k (DbValue.substr(a,(b-a)));
            istringstream z(DbValue.substr(b+1,(c-(b+1))));
            string p = DbValue.substr(c+2,(int)DbValue.find("|)")-(c+2));
            k >> d;
            z >>e;
            if (Type ==1)
                return BetweenConnect(p,d,e,B);
            else
                SetBettwenConEntry(Value,d,e,p);
        }
    }
    return DbValue;
}
string DbConnections::GetNormalConnect(int X, int Y,DB B)
{
    if(B.GetMaxX()>=X and B.GetMaxY()>=Y and (B.PosX!=X or B.PosY!=Y))
    {
        return B.GetEntryById(X,Y);
    }
    else return " ";
}
string DbConnections::BetweenConnect(string Path,int X,int Y, DB B)
{
    DB x(Path);
    if(x.GetMaxX()>=X and x.GetMaxY()>=Y  and Path!=B.GetPathName())
    {
        return x.GetEntryById(X,Y);
    }
    else return " ";
}
void DbConnections::SetNormalConEntry(string Value,DB& B,int X,int Y)
{
    if(B.GetMaxX()>=X and B.GetMaxY()>=Y)
    {
        B.SetEntryById(X,Y,Value);
    }
}
void DbConnections::SetBettwenConEntry(string Value,int X,int Y,string Path)
{
    DB B(Path);
    if(B.GetMaxX()>=X and B.GetMaxY()>=Y)
    {
        B.SetEntryById(X,Y,Value);
    }
}
