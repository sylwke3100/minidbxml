#include "DbConnections.h"
#include "DbControl.h"

string DbConnections::SearchConnection(string DbValue,DB& B)
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
            return GetNormalConnect(d,e,B);
        }
    }
    return DbValue;
}
string DbConnections::GetNormalConnect(int X, int Y,DB B)
{
    if(B.GetMaxX()>=X and B.GetMaxY()>=Y and (B.PosX!=X and B.PosY!=Y))
    {
        return B.GetEntryById(X,Y);
    }
    else return " ";
}
