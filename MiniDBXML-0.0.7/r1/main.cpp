#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "./version.h"
#include <conio.h>
#include <cstring>
#include <sys/prctl.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
//Install Modules
#include "./modules/security.h"
#include "./modules/multidb.h"
using namespace std;
int view_menu();
vector <vector <string> >dane;
int main(int argc, char *argv[]);
int vid=1;
int counter_e=0;
string path,t;
struct ver
{
public:
    int version;
    int subversion;
    int nr_update;
    string get_version_status()
    {
        string stat;
        if(nr_update<=8)
        {
            stat="Alpha";
        }
        if(nr_update<=15 and nr_update>8)
        {
            stat="Beta";
        }
        if(nr_update==0)
        {
            stat="Stable";
        }
        return stat;
    }
};
struct screen
{
public:
    int _sleep(int time)
    {
        sleep(time);
        system("clear");
    }
    int clr()
    {
        system("clear");
    }
} ;
screen scr;
ver minidbxml;
int parse_xml_tag(string name_tag_find,int id)
{
    vid=id;
    counter_e=0;
    string*mem=new string;
    string*name_tag=new string;
    *name_tag=name_tag_find;
    string*name_tag_=new string ;
    ifstream*file= new ifstream;
    string*dw=new string;
    *dw=path_db+".xml";
    file->open(dw->c_str(),ios::in);
    while(!file->eof())
    {
        getline(*file,*mem);
        *name_tag_="<"+name_tag_find+">";
        for(int i=0; i<mem->length(); i++)
        {
            if(mem->substr(i,i+name_tag_->length())==*name_tag_)
            {
                *name_tag="</"+name_tag_find+">";
                for(int m=i+name_tag_->length(); m<mem->length(); m++)
                {
                    if(mem->substr(m,m+name_tag->length())==*name_tag)
                    {
                        counter_e++;
                        if(counter_e>=dane.size())
                        {
                            dane.resize(dane.size()+1);
                        }
                        if(dane[counter_e].size()==0)
                        {
                            dane[counter_e].push_back(" ");
                        }
                        dane[counter_e].push_back(mem->substr(i+name_tag_->length(),m-name_tag->length()+1)) ;
                    }
                }
            }
        }
    }
    file->close();
    delete dw;
    delete file;
    delete mem;
    delete name_tag_;
}
int pre_load()
{
    string* mv = new string;
    int*st_= new int;
    *st_=0;
    int l=0;
    dane.clear();
    dane.resize(1);
    dane[0].push_back("");
    counter_e=0;
    vid=1;
    ifstream*file=new ifstream;
    string*ow=new string;
    *ow=path_db+".xml";
    file->open(ow->c_str(),ios::in);
    while(!file->eof())
    {
        getline(*file,*mv);
        if(*mv=="<tag>" )
        {
            *st_=1;
        }
        else
        {
            if(mv->length()!=NULL)
            {
                if(*mv=="</tag>")
                {
                    *st_=0;
                }
                else
                {
                    if(*st_==1)
                    {
                        l++;
                        dane[0].push_back(mv->substr(4,mv->length()-9));
                        parse_xml_tag(mv->substr(4,mv->length()-9),l);
                        scr.clr();
                    }
                }
            }
        }
    }
    system("clear");
    file->close();
    delete mv;
    delete file;
    delete st_;
    delete ow;
}
string rel(string t,int x,int y)
{
    string rd;
    int i=0,pie=0,ost=0,ok=0;
    for(i=i; i<t.length(); i++)
    {
        if(t.substr(i,2)=="$(")
        {
            ok=1;
            pie=i;
            for(int m=i+1; m<t.length(); m++)
            {
                if(t.substr(m,1)==")")
                {
                    int dl=(m)-(i+2);
                    string v=t.substr(i+2,dl);
                    for(int p=0; p<=dl; p++)
                    {
                        if(v.substr(p,1)==",")
                        {
                            int a=0,b=0;
                            istringstream aa(v.substr(0,p));
                            istringstream bb(v.substr(p+1,(v.length()-p)));
                            aa >> a;
                            bb >> b;

                            if((a<dane.size() and a!=0 ) and (b<dane[a].size() and b!=0))
                            {
                                if(x==a and y==b)
                                {
                                }
                                else
                                {
                                    rd+=rel(dane[a][b],a,b);
                                }
                            }
                            i=m+1;

                        }
                    }
                }
            }
        }
        else
        {
            rd+=t.substr(i,1);
        }
    }
    return rd;
}
int view_database()
{
    scr.clr();
    pre_load();
    int h=0;
    cout<<"* |";
    for(int p=1; p<dane[0].size(); p++)
    {
        if(dane[0][p].length()!=NULL)
        {
            cout<<dane[0][p]<<" |";
        }
    }
    cout<<endl<<"---------------------------"<<endl;
    for(int m=1; m<dane.size(); m++)
    {
        h++;
        cout<<h<<".|";
        for(int i=1; i<dane[m].size(); i++)
        {
            if(!dane[m][i].empty())
            {
                cout<<rel(dane[m][i],m,i)<<"|";
            }
            else
            {
                cout<<" |";
            }
        }
        cout<<endl;
    }
    if(h==0)
    {
        cout<<"Empty database!!!"<<endl;
        return view_menu();
    }
    cout<<endl<<endl;

    return view_menu();
}
int save_database(int u,int wid)
{
    int d=1,z=1;
    fstream*x= new fstream;
    string*za=new string;
    *za=path_db+".xml";
    x->open(za->c_str(),ios::in|ios::out|ios::trunc);
    *x<<"<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"<<endl;
    *x<<"<db>"<<endl;
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    *x<<"<header>"<<endl<<"<Program>MiniDBXML</Program>"<<endl<<"<Version>"<<minidbxml.version<<"."<<minidbxml.subversion<<"."<<
    minidbxml.nr_update<<" - "<<minidbxml.get_version_status()<<
    "</Version>"<<endl<<"<Time_Date>"<<asctime (timeinfo)<<"</Time_Date>"<<endl<<"</header>"<<endl;
    *x<<"<tag>"<<endl;
    for(int y=1; y<dane[0].size(); y++)
    {
        if(dane[0][y].length()!=NULL)
        {
            *x<<"<tg>"<<dane[0][y]<<"</tg>"<<endl;
        }
    }
    *x<<"</tag>"<<endl<<"<body>"<<endl;
    if(counter_e==0)
    {
        counter_e=1;
    }
    else
    {
        counter_e++;
    }
    for(int m=1; m<dane.size(); m++)
    {
        for(int i=1; i<dane[m].size(); i++)
        {
            if(dane[m][i].length()!=NULL)
            {
                if(wid==m and u==1)
                {
                    i=dane[0].size();
                }
                else
                {
                    *x<<"<entry id=\""<<d++<<"\">"<<endl;
                    for(int q=1; q<dane[m].size(); q++)
                    {
                        *x<<"<"<<dane[0][q]<<">"<<dane[m][q]<<"</"<<dane[0][q]<<">"<<endl;
                    }
                    *x<<"</entry>"<<endl;
                    i=dane[0].size();
                }
            }
        }
    }
    *x<<"</body>"<<endl<<"</db>";
    x->close();
    delete x;
    delete za;
}
int find_entry()
{
    scr.clr();
    string *v_dataf=new string;
    pre_load();
    cout<<"Please enter text search"<<endl;
    cin>>*v_dataf;
    cout<<endl<<"Result for  "<<*v_dataf<<endl<<"-----------------------"<<endl<<"*|";
    for(int m=1; m<dane[0].size(); m++)
    {
        if(dane[0][m].length()!=NULL)
        {
            cout<<dane[0][m]<<" |";
        }
    }
    cout<<endl<<"________________________"<<endl;
    for(int i=1; i<dane.size(); i++)
    {
        for(int x=1; x<dane[i].size(); x++)
        {
            if(dane[i][x].length()!=NULL)
            {
                string fake=rel(dane[i][x],i,x);
                for(int c=0; c<fake.length(); c++)
                {
                    if(*v_dataf==fake.substr(c,v_dataf->length()))
                    {
                        cout<<i<<".|";
                        for(int m=0; m<dane[i].size(); m++)
                        {
                            cout<<rel(dane[i][m],i,m)<<" |";
                        }
                        cout<<endl;
                    }
                    c=c+v_dataf->length();
                }
            }
        }
    }
    cout<<endl;
    delete v_dataf;
    return view_menu();
}
int edit_col_database()
{
    pre_load();
    scr.clr();
    int v,i,p=0;
    string t;
    cout<<"Choise column to edit:"<<endl<<endl<<"0 .New column"<<endl;
    for(i=1; i<dane[0].size(); i++)
    {
        if(dane[0][i].length()!=NULL)
        {
            p++;
            cout<<i<<" ."<<dane[0][i]<<endl;
        }
    }
    cout<<endl;
    cin>>v;
    p++;
    if(v==0)
    {
        cout<<"Enter name column"<<endl;
        cin>>t;
        dane[0].push_back(t);
        cout<<endl<<"Adds column: "<<t<<" at id "<<p<<" to database";
        save_database(0,0);
    }
    else
    {
        if(v<dane[0].size())
        {
            scr.clr();
            cout<<"Edit - '"<<dane[0][v]<<"' "<<endl<<endl;
            cout<<"1.Rename column"<<endl<<"2.Delete column"<<endl;;
            char o;
            cin>>o;
            scr.clr();
            switch(o)
            {
            case '1':
                cout<<"Please enter new name columns"<<endl;
                cin>>t;
                dane[0][v]=t;
                save_database(0,0);
                break;
            case '2':
                cout<<"Deleted colums id "<<v<<endl;
                dane[0][v].clear();
                for(int c=1; c<dane.size(); c++)
                {
                    if(v>dane[c].size())
                    {
                        dane[c][v]="";
                    }
                }
                save_database(0,0);
                break;
            default:
                cout<<"Correct select"<<endl;
                return view_menu();
                break;
            }
        }
        else
        {
            scr.clr();
            cout<<"Correct number columns "<<endl;
        }
    }
    cout<<endl<<endl;
    return view_menu();
}
int edit_database()
{
    int u=0;
    int m=0;
    pre_load();
    scr.clr();
    int id_w=0,c=0,z=0,p=0;
    string value;
    for(m=1; m<dane.size(); m++)
    {
        if(dane[m][1].length()!=NULL or dane[m][2].length()!=NULL)
        {
            cout<<m<<".";
            if(dane[m][1].length()!=NULL)
            {
                cout<<dane[m][1];
            }
            else
            {
                cout<<dane[m][2];
            }
            cout<<endl;
            z=m;
        }
    }
    cout<<z+1<<".New entry"<<endl;
    cout<<"Enter ID entry:";
    cin>>id_w;
    scr.clr();
    if(!(id_w==z+1) or id_w<=z)
    {
        cout<<"Entry ID:"<<id_w<<"-"<<dane[id_w][1];
        cout<<endl<<"What do you want to edit?"<<endl;
        for(int i=1; i<dane[0].size(); i++)
        {
            if(dane[0][i].length()!=NULL)
            {
                p++;
                cout<<i<<"."<<dane[0][i]<<endl;
            }
        }
        cout<<p+1<<".Delete entry?"<<endl;
        cout<<p+2<<".Main Menu"<<endl;
        cin>>c;
        if(c==(p+1) or c==(p+2))
        {
            if(c==(p+2))
            {
                return view_menu();
            }
            else
            {
                cout<<"deleted entry !!!"<<endl;
                u=1;
                for(int a=1; a<dane[0].size(); a++)
                {
                    dane[id_w][a].clear();
                }
            }
        }
        else
        {
            if(c>(dane[id_w].size()+1))
            {
                cout<<"Wrong choice"<<endl;
            }
            else
            {
                if(c>dane[id_w].size())
                {
                    for(int xcc=0; xcc<=(dane[0].size()-dane[id_w].size()); xcc++)
                    {
                        dane[id_w].push_back(" ");
                    }
                }
                cout<<endl<<"Editing "<<dane[0][c]<<": ";
                getline( cin.ignore(100,'\n'),value);
                dane[id_w][c]=value;
            }
        }
        save_database(u,id_w);
    }
    else
    {
        if(id_w==dane.size())
        {
            dane.resize(dane.size()+1);
            counter_e++;
            for(int qw=0; qw<dane[0].size(); qw++)
            {
                dane[counter_e].push_back(" ");
            }
            save_database(0,0);
        }
        else
        {
            cout<<"Correct id entry"<<endl;
        }
    }
    return view_menu();
}
int export_csv()
{
    fstream*x= new fstream;
    string pc;
    pc=path_db+".csv";
    x->open(pc.c_str(),ios::in|ios::out|ios::trunc);
    pre_load();
    for(int z=0; z<dane.size(); z++)
    {
        for(int i=1; i<dane[z].size(); i++)
        {
            *x<<"\""<<dane[z][i];
            if(vid!=i)
            {
                *x<<"\",";
            }
            else
            {
                *x<<"\"";
            }
        }
        *x<<endl;
    }
    x->close();
    delete x;
    cout<<"save csv"<<endl;
    scr._sleep(1);
    return view_menu();
}
int export_html()
{
    string*title=new string;
    fstream*x= new fstream;
    if(path.length()==NULL)
    {
        path+=path_db+".html";
        x->open(path.c_str(),ios::in|ios::out|ios::trunc);
    }
    else
    {
        string g_path="echo >> ";
        g_path+=path;
        system(g_path.c_str());
        x->open(path.c_str(),ios::in|ios::out|ios::trunc);
    }
    pre_load();
    *title=t;
    if(title->length()==NULL)
    {
        cout<<"Please write title file (max 100 char)"<<endl;
        getline( cin.ignore(100,'\n'),*title);
    }
    if(title->length()==NULL)
    {
        cout<<"Please enter title file"<<endl;
        x->close();
        delete x,title;
        return export_html();
    }
    *x<<"<html>"<<endl<<"<head><title>"<<*title<<"</title></head>"<<endl<<"<body><table >"<<endl;
    for(int z=0; z<dane.size(); z++)
    {
        *x<<"<tr>";
        if(z==0 )
        {
            *x<<"<td>*  </td>";
        }
        else
        {
            *x<<"<td>"<<z<<"</td>";
        }
        for(int i=0; i<dane[z].size(); i++)
        {
            if(z==0)
            {
                *x<<"<th>"<<dane[z][i]<<"</th>"<<endl;
            }
            else
                *x<<"<td>"<<dane[z][i]<<"</td>"<<endl;
        }
        *x<<"</tr>";
        *x<<endl;
    }
    *x<<"</table><body>"<<endl<<"</html>";
    x->close();
    delete x;
    delete title;
    cout<<"save base.html in "<<path<<endl;
    scr._sleep(2);
    return view_menu();
}
int view_menu()
{
    cout<<"Mini Database for XML "<<minidbxml.version<<"."<<minidbxml.subversion<<"."<<minidbxml.nr_update<<" - "<<
        minidbxml.get_version_status()<<endl<<endl<<"Active DB: "<<path_db<<".xml"<<endl<<endl<<
        "Main Menu:"<<endl<<
        "1.View Database"<<endl<<
        "2.Find entry."<<endl<<
        "3.Edit Database"<<endl<<
        "4.Edit Column Database"<<endl<<
        "5.Export DB"<<endl<<"6.Change Database"<<endl<<
        "7.Session Killer"<<endl<<
        "q.Exit"<<endl;
    char wybor;
    cin>>wybor;
    switch(wybor)
    {
    case '1' :
        view_database();
        break;
    case '2' :
        find_entry();
        break;
    case '3' :
        edit_database();
        break;
    case '4':
        edit_col_database();
        break;
    case '5':
        int cd;
        scr.clr();
        cout<<" Chose format to Export"<<endl<<endl<<"1. CSV"<<endl<<"2. HTML"
            <<endl<<"3. Return to Main Menu"<<endl;
        cin>>cd;
        switch(cd)
        {
        case 1:
            export_csv();
            break;
        case 2:
            export_html();
            break;
        case 3:
            scr.clr();
            view_menu();
            break;
        default:
            scr.clr();
            return view_menu();
            break;
        }
        break;
    case '6' :
        scr.clr();
        if(get_db_list("./.data/")==true)
        {
            view_menu();
        }
        break;
    case '7':
        Kill_session(NULL);
        view_menu();
        break;
    case 'q':
        End_session();
        kill(chilpid,SIGTERM);
        return 0;
        break;
    default:
        cout<<"Please enter correct number !!!";
        break;
    }
    return 1;
}
int main(int argc, char *argv[])
{
    int cd=0;
    prctl(PR_SET_NAME, "minidbxml-core", 0, 0, 0);
    if(argc>=3)
    {
        st_p=0;
        path_db=argv[2];
    }
    else
    {
        cd==1;
    }
    if(get_db_list("./.data/")==true)
    {
        switch(fork())
        {
        case -1:
            cout<<"Error"<<endl;
            return 0;
        case 0:
            if(cd==0)
            {
                prctl(PR_SET_NAME, "minidbxml-scr", 0, 0, 0);
                sleep(2);
                Manage_session();
            }
            break;
        default:
            pid=getpid();
            st_p=1;
            minidbxml.version=0;
            minidbxml.subversion=0;
            minidbxml.nr_update=7;
            pre_load();
            if(argc>3)
            {
                switch(*argv[1])
                {
                case 'v':
                    for(int t=0; t<dane.size(); t++)
                    {
                        for(int a=1; a<dane[t].size(); a++)
                        {
                            cout<<rel(dane[t][a],t,a);
                            if(a==dane[t].size()-1)
                            {
                                cout<<"|>|";
                            }
                            else
                            {
                                cout<<" ||";
                            }
                        }
                    }
                    break;
                case 'e' :
                    if(*argv[4]>=(dane[*argv[3]].size()+1))
                    {
                        cout<<"Wrong choose"<<endl;
                    }
                    else
                    {
                        if(*argv[4]>dane[*argv[3]].size())
                        {
                            cout<<"ok";
                            for(int xcc=0; xcc<=(dane[0].size()-dane[*argv[3]].size()); xcc++)
                            {
                                dane[*argv[3]].push_back(" ");
                            }
                        }
                        stringstream bf;
                        string cdd;
                        bf << argv[5];
                        bf >> cdd;
                        dane[*argv[3]][*argv[4]]=cdd;
                        cout<<dane[*argv[3]][*argv[4]]<<endl;
                    }
                    save_database(0,0);
                    break;
                default:
                    view_menu();
                    break;
                }
            }
            else
            {
                view_menu();
            }
            break;
        }
    }
}
