#include "UiCommandParser.h"
void UiCommandParser::Info()
{
    cout<<"Command Parser for MiniDBXML \n\n>>";
}
void UiCommandParser::ParseCommand(string Command,int& Signal) /**< Parse Command  */
{
    for(int i=0; i<Command.length(); i++)
    {
        if(Command.substr(i,7)=="Exit();")
        {
            delete base;
            Signal = 1;
        }
        if(Command.substr(i,8)=="Connect(")
        {
            i+=8;
            if((int)Command.find(");",i)>0)
            {
                int poz = (int)Command.find(");",i);
                base = new DB(Command.substr(i,(poz-(i))));
                cout<<"Connected to base: "<<Command.substr(i,(poz-(i)))<<endl;
                i= poz;
                IsConnect = 1;
            }
        }
        if(Command.substr(i,8)=="GetById(" && IsConnect==true)
        {
            i+=8;
            if((int)Command.find(",",i)>0 && (int)Command.find(");",i)>0)
            {
                int poz=(int)Command.find(",",i),x=(int)Command.find(");",i),c,d;
                istringstream a (Command.substr(i,(poz-i)));
                istringstream b(Command.substr(x+1,poz+1-x));
                a >>c;
                b >>d;
                cout<<base ->GetEntryById(c,d)<<endl;
                i=x;
            }
        }
        if(Command.substr(i,8)=="SetById(" && IsConnect==true)
        {
            i+=8;
            if((int)Command.find(",",i)>0 && (int)Command.find("');",i)>0 && (int)Command.find(",'",i)>0)
            {
                int poz=(int)Command.find(",",i),x=(int)Command.find(",'",i),y=(int)Command.find("');"),c,d;
                stringstream a (Command.substr(i,(poz-i)));
                istringstream b(Command.substr(poz+1,x-(poz+1)));
                a >>c;
                b >>d;
                string t = Command.substr(x+2,y-(x+1)-1);
                base->SetEntryById(c,d,t);
                i=y;
            }
        }
        if(Command.substr(i,7)=="Save();" && IsConnect==true)
        {
            base ->SaveDb();
            i+=7;
        }
        if(Command.substr(i,13)=="Disconnect();")
        {
            cout<<"Disconnect from database"<<endl;
            delete base;
            IsConnect = 0;
        }

    }
}
