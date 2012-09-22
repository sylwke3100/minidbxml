#include "UiCommandParser.h"
#include "UiCommandStatus.h"

UiCommandParser::UiCommandParser()
{
    IsConnect = 0;
}
int UiCommandParser::CheckState()
{
    return IsConnect;
}
void UiCommandParser::SetState(int State)
{
    IsConnect = State;
}
void UiCommandParser::SetSignal(int Signal)
{
    this->Signal = Signal;
}
int UiCommandParser::GetSignal()
{
    return Signal;
}
void UiCommandParser::Info()
{
    Print("Shell Command for MiniDBXML ");
    Print(AutoVersion::_FULLVERSION_STRING);
    Print(" \n\n>>");
}
vector<string> UiCommandParser::PrepareToParse(string CommandLine)
{
    vector<string> Data;
    int Last = 0;
    for (int i =0; i<CommandLine.length(); i++)
    {
        if((int)CommandLine.find(" ",i)!=-1)
        {
            int pos =(int)CommandLine.find(" ",i);
            Data.push_back(CommandLine.substr(Last,pos-Last));
            i = pos+1;
            Last = pos+1;
        }
        if (CommandLine.length()==i+1)
        {
            Data.push_back(CommandLine.substr(Last,i+1));
        }
    }
    return Data;
}
void UiCommandParser::ParseCommand(string Command,int& Signal)
{
    this->Signal = Signal;
    vector <string> Line = this->PrepareToParse(Command);
    if (Line[0] == "exit")
    {
        delete base;
        SetSignal(SIGNAL_EXIT);
    }
    if(Line[0] == "connect" && CheckState()==false)
    {
        base = new DB(Line[1]);
        if(base->IsLoaded()==true)
        {
            Print("Connected to base: ");
            Print(Line[1]);
            Print("\n");
            SetState(1);
        }
        else
            Print("Error read db\n");
    }
    if(Line[0] == "disconnect" && CheckState()==true)
    {
        Print("Disconnect from database\n");
        delete base;
        SetState(0);
    }
    if (Line[0] == "getcolumn" && CheckState()==true)
    {
        int t =0;
        for(int i=0;i<base->GetMaxX();i++)
        {
            if(base->GetEntryById(i,0)==Line[1]) t=1;
            cout<<"ok"<<endl;
        }
        if(t==1)
        {
            vector<string>V;
            DbSearch A;
            A.SearchInColumn(Line[1],base,V);
            for(int i=0;i<V.size();i++){
                Print(V[i]);
                Print("\n");
            }
        }
    }
    for(int i=0; i<Command.length(); i++)
    {

        if(Command.substr(i,7)=="Exit();")
        {
            delete base;
            SetSignal(1);
        }
        if(Command.substr(i,8)=="Connect(")
        {
            i+=8;
            if((int)Command.find(");",i)>0)
            {
                if (CheckState()==false)
                {
                    int poz = (int)Command.find(");",i);
                    base = new DB(Command.substr(i,(poz-(i))));
                    if(base->IsLoaded()==1)
                    {
                        Print("Connected to base: ");
                        Print(Command.substr(i,(poz-(i))));
                        Print("\n");
                        i= poz;
                        SetState(1);
                    }
                    else
                        Print("Error read db\n");
                }
                else Print("Please first disconnect\n");
            }
        }
        if(Command.substr(i,8)=="GetById(" && CheckState()==true)
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
        if(Command.substr(i,12)=="ExportHTML('" && CheckState()==true)
        {
            i+=12;
            if((int)Command.find("','",i)>0 && (int)Command.find("');",i)>0)
            {
                int poz=(int)Command.find("','",i),x=(int)Command.find("');",i);
                string Path = Command.substr(i,(poz-i));
                string Title= Command.substr(poz+3,x-(poz+3));
                DbExport E(Path);
                E.ExportToHTML(*base,Title);
            }
        }
        if(Command.substr(i,8)=="DelById(" && CheckState()==true)
        {
            i+=8;
            if((int)Command.find(",",i)>0 && (int)Command.find(");",i)>0)
            {
                int poz=(int)Command.find(",",i),x=(int)Command.find(");",i),c,d;
                istringstream a (Command.substr(i,(poz-i)));
                istringstream b(Command.substr(x+1,poz+1-x));
                a >>c;
                b >>d;
                base ->DeleteEntry(c,d);
                i=x;
            }
        }
        if (Command.substr(i,8)=="Search('"&& CheckState()==true)
        {
            i+=8;
            if((int)Command.find("');")>0)
            {
                DbSearch S;
                vector <string> Values;
                S.SetSearchValue(Command.substr(i,(int)Command.find("');")-i));
                S.SearchInDb(base,Values);
                for(int o=0; o<Values.size(); o++)
                {
                    Print(Values[o]);
                    Print("\n");
                }
                i=(int)Command.find("');")+3;
            }
        }
        if (Command.substr(i,11)=="ExportCSV('"&& CheckState()==true)
        {
            i+=11;
            if((int)Command.find("');")>0)
            {

                DbExport E(Command.substr(i,(int)Command.find("');")-i));
                E.ExportToCsv(*base);
            }
        }
        if(Command.substr(i,8)=="SetById(" && CheckState()==true)
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
                base->SetById(c,d,t);
                i=y;
            }
        }
        if(Command.substr(i,16)=="SearchByColumn('" && CheckState()==true)
        {
            i+=16;
            if((int)Command.find("','",i)>0 && (int)Command.find("');",i)>0)
            {
                int s = (int)Command.find("','",i),d = (int)Command.find("');",i);
                string a = Command.substr(i,s-i),b = Command.substr(s+3,d-(s+3));
                vector <string> D;
                DbSearch S;
                S.SetSearchValue(b);
                S.SearchInColumn(a,base,D);
                for(int o=0; o<D.size(); o++)
                {
                    Print(D[o]);
                    Print("\n");
                }
                i=d+3;
            }
        }
        if(Command.substr(i,7)=="Save();" && CheckState()==true)
        {
            base ->SaveDb();
            i+=7;
        }
        if(Command.substr(i,13)=="Disconnect();" && CheckState()==true)
        {
            Print("Disconnect from database\n");
            delete base;
            SetState(0);
            i=i+13;
        }
        Signal = GetSignal();
    }
}
void UiCommandParser::Print(string Text)
{
    cout<<Text;
}
void UiCommandParser::ReadCommandFromFile(string Path)
{
    fstream File(Path.c_str(),ios::out|ios::in);
    string mem;
    int Signal=0;
    if(File.is_open()==true)
    {
        while (!File.eof())
        {
            getline(File,mem);
            ParseCommand(mem,Signal);
            if (Signal == 1)break;
        }
        File.close();
    }
    else Print("File no found \n");
}
