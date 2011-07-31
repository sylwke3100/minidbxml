#include "UiCommandParser.h"

 void UiCommandParser::ParseCommand(string Command)
 {
     for(int i=0;i<Command.length();i++)
     {
         if(Command.substr(i,7)=="EXIT();")
         {
            cout<<"DISCONNECT";
         }
         if(Command.substr(i,8)=="CONNECT(")
         {
             i+=8;
             if((int)Command.find(");",i)>0)
             {
                 int poz = (int)Command.find(");",i);
                base = new DB(Command.substr(i,(poz-(i))));
                cout<<"CONNECTET to base: "<<Command.substr(i,(poz-(i)))<<endl;
             }
         }
          if(Command.substr(i,8)=="GETBYID(")
         {
             i+=8;
            if((int)Command.find(",",i)>0 && (int)Command.find(");",i)>0)
            {
                int poz=(int)Command.find(",",i),x=(int)Command.find(",",i),c,d;
                istringstream a (Command.substr(i,(poz-i)));
                istringstream b(Command.substr(x+1,poz+1-x));
                a >>c;
                b >>d;
                cout<<base ->GetEntryById(c,d)<<endl;
            }
         }
     }
 }
