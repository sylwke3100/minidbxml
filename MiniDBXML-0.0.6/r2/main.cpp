#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "./version.h"
#include <conio.h>

using namespace std;
int view_menu();
int max_e=4000;
string dane[4000][4000];
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
            if(nr_update<=8){stat="Alpha";}
            if(nr_update<=15 and nr_update>8){stat="Beta";}
            if(nr_update==0){stat="Stable";}
            return stat;
        }
    };
struct screen
    {
        public:
        int _sleep(int time) {sleep(time);system("clear");}
        int clr(){system("clear");}
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
    file->open("./.data/base.xml",ios::in);
    while(!file->eof())
    {
      getline(*file,*mem);
      *name_tag_="<"+name_tag_find+">";
      for(int i=0;i<mem->length();i++){
      if(mem->substr(i,i+name_tag_->length())==*name_tag_)
      {
        *name_tag="</"+name_tag_find+">";
          for(int m=i+name_tag_->length();m<mem->length();m++){

              if(mem->substr(m,m+name_tag->length())==*name_tag){
                  counter_e++;
                   if(counter_e>=max_e){}
                   else{
                   dane[counter_e][vid]=mem->substr(i+name_tag_->length(),m-name_tag->length()+1) ;
                   }
              }
          }

      }
      }

    }

    file->close();
    delete name_tag_,mem,name_tag,id,file;
}

int pre_load()
{

    string* mv = new string;
    int*st_= new int;
    *st_=0;
    int *ui=new int;
    int l=0;
    for(int n=1;n<=counter_e;n++){
for(int i=1;i<=vid;i++)
    {

        dane[0][i]="";
        if(dane[n][i].length()!=NULL){

             dane[n][i].clear();}
    }
    }
    counter_e=0;
    vid=1;
    ifstream*file=new ifstream;
    file->open("./.data/base.xml",ios::in);
    while(!file->eof())
        {
            ui++;
    getline(*file,*mv);
        if(*mv=="<tag>" ){  *st_=1; } else{

        if(mv->length()!=NULL){
            if(*mv=="</tag>")
            {*st_=0; }
            else{
                if(*st_==1){
                    l++;
                dane[0][l]=mv->substr(4,mv->length()-9);
                parse_xml_tag(mv->substr(4,mv->length()-9),l);
                }
        }
        }
        }
        }
        file->close();
        delete mv,file,st_;
}

int view_database()
{
   scr.clr();
    pre_load();
    int h=0;
    int d=0,wynik=0,v=1;
            cout<<"* |";
            for(int p=1;p<=vid;p++)
            {
                if(dane[0][p].length()!=NULL){
                cout<<dane[0][p]<<" |";
                }
            }
            cout<<endl<<"---------------------------"<<endl;
        for(int m=1;m<=counter_e+1;m++)
        {
            for(int i=1;i<=vid;i++)
            {
            if(dane[m][i].length()!=NULL)
            {
            cout<<v++<<".|";
            for (int w=1;w<=vid;w++)
                {
                 cout<<dane[m][w];
                 if(dane[m][w].length()<=dane[0][w].length()){ int z=dane[m][w].length()-dane[0][w].length(); for(int k=0;k<=w;k++){cout<<" ";} }
                 cout<<"|";
                 }
            i=vid;
            cout<<endl;
            h++;
            }
            }
        }
     if(h==0){cout<<"Empty database!!!"<<endl;return view_menu();}
     cout<<endl<<endl;
    return view_menu();
    }

int save_database(int u,int wid)
{
    int d=1,z=1;
    fstream*x= new fstream;
    x->open("./.data/base.xml",ios::in|ios::out|ios::trunc);
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
        for(int y=1;y<=vid;y++)
        {
            if(dane[0][y].length()!=NULL)
            {
            *x<<"<tg>"<<dane[0][y]<<"</tg>"<<endl;
            }
        }
        *x<<"</tag>"<<endl<<"<body>"<<endl;
        if(counter_e==0){counter_e=1;}else{counter_e++;}
        for(int m=1;m<=counter_e;m++)
        {
            for(int i=1;i<=vid;i++)
            {
                if(dane[m][i].length()!=NULL)
                {
                    if(wid==m and u==1){ i=vid;} else{
                    *x<<"<entry id=\""<<d++<<"\">"<<endl;
                    for(int q=1;q<=vid;q++)
                    {
                        *x<<"<"<<dane[0][q]<<">"<<dane[m][q]<<"</"<<dane[0][q]<<">"<<endl;
                    }
                    *x<<"</entry>"<<endl;
                    i=vid;
                    }
                }
            }

        }
    *x<<"</body>"<<endl<<"</db>";
    x->close();
    delete x;

    }
int find_entry()
{
    bool *end_l= new bool;
    *end_l=false;
    scr.clr();
    string *v_dataf=new string;
    pre_load();
    cout<<"Please enter text search"<<endl;
    cin>>*v_dataf;
    cout<<endl<<"Result for  "<<*v_dataf<<endl<<"-----------------------"<<endl<<"*|";
    for(int m=1;m<=vid;m++)
            {
                if(dane[0][m].length()!=NULL){
                cout<<dane[0][m]<<" |";
                }
            }
    cout<<endl<<"________________________"<<endl;
    for(int i=1;i<=counter_e;i++)
    {
      for(int x=1;x<=vid;x++)
      {
          if(dane[i][x].length()!=NULL)
          {
              for(int sd=0;sd<(dane[i][x].length()/v_dataf->length());sd++)
              {

               if(*v_dataf==dane[i][x].substr(sd*v_dataf->length(),(sd*v_dataf->length())+v_dataf->length()))
               {

                  cout<<i<<"|";
                  for(int m=1;m<=vid;m++)
                  {
                  cout<<dane[i][m]<<" |";
                  *end_l=true;
                  }
               }
          }
         }
         if(*end_l==true){cout<<endl;*end_l=false;}
      }
    }
    cout<<endl;
    delete v_dataf,end_l;
    return view_menu();
}
int edit_col_database()
{
    pre_load();
   scr.clr();
    int v,i,p=0;
    string t;
    cout<<"Choise column to edit:"<<endl<<endl<<"0 .New column"<<endl;
    for(i=1;i<=vid;i++)
    {
        if(dane[0][i].length()!=NULL)
        {
          p++;
        cout<<i<<" ."<<dane[0][i]<<endl;
        }}
    cout<<endl; cin>>v; p++;
    if(v==0){cout<<"Enter name cols"<<endl; cin>>t;cout<<endl<<"Adds column: "<<t<<" at id "<<p<<" to database"; dane[0][p]=t;vid++; save_database(0,0); }
    else {
     if(v<=vid){
     cout<<"1.Rename column"<<endl<<"2.Delete column"<<endl;;
     char o;
     cin>>o;
     scr.clr();
     switch(o)
     {
        case '1':
        cout<<"please enter new name columns"<<endl;
        cin>>t;
        dane[0][v]=t;
        save_database(0,0);
        break;
        case '2':
        cout<<"deleted colums id "<<v<<endl;
        dane[0][v].clear();
        for(int z=1;z<=counter_e;z++)
        {
            dane[z][v].clear();
        }
        save_database(0,0);
        break;
        default:
        cout<<"Correct select"<<endl;
        return view_menu();
        break;
     }
     }
     else{scr.clr(); cout<<"Correct number columns "<<endl;}
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
   for(m=1;m<=counter_e;m++)
    {
    if(dane[m][1].length()!=NULL or dane[m][2].length()!=NULL)
    {
            cout<<m<<".";
            if(dane[m][1].length()!=NULL)
            {
            cout<<dane[m][1];
            }
            else { cout<<dane[m][2];}
           cout<<endl; z=m;
    }
    }
   cout<<z+1<<".New entry"<<endl;
   cout<<"Enter ID entry:";
   cin>>id_w;
   scr.clr();
   if(id_w==z+1 or id_w<=z){
   cout<<"Entry ID:"<<id_w<<"-"<<dane[id_w][1];
   cout<<endl<<"What do you want to edit?"<<endl;
    for(int i=1;i<=vid;i++)
    {
        if(dane[0][i].length()!=NULL){
        p++;
        cout<<i<<"."<<dane[0][i]<<endl;
        }
    }
    cout<<p+1<<".Delete entry?"<<endl;
    cout<<p+2<<".Main Menu"<<endl;
    cin>>c;
    if(c==(p+1) or c==(p+2))
    {
        if(c==(p+2)){return view_menu();}
        else{
        cout<<"deleted entry !!!"<<endl;
        u=1;
        for(int a=1;a<=vid;a++)
            {
                dane[id_w][a].clear();
            }
        }
    }
    else{
        if(c>(vid+1)){ cout<<"Wrong choice"<<endl;}
        else
        {
            cout<<endl<<"Editing "<<dane[0][c]<<": ";
          getline( cin.ignore(100,'\n'),value);

            dane[id_w][c]=value;
        }
    }
    save_database(u,id_w);
   }
   else {cout<<"Correct id entry"<<endl; }
   return view_menu();
}
int export_csv()
{
fstream*x= new fstream;
x->open("./.data/base.csv",ios::in|ios::out|ios::trunc);
pre_load();
for(int z=0;z<=counter_e;z++)
    {
        for(int i=1;i<=vid;i++)
        {
        *x<<"\""<<dane[z][i];
        if(vid!=i)
        {
        *x<<"\",";
        }
        else { *x<<"\"";  }
        }
   *x<<endl;
    }
x->close();
delete x;
cout<<"save base.csv in "<<get_current_dir_name()<<"/.data/"<<endl;
scr._sleep(1);
return view_menu();
}
int export_html()
{
string*title=new string;
fstream*x= new fstream;
if(path.length()==NULL){
    path=get_current_dir_name();
    path+="/.data/base.html";
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
if(title->length()==NULL){
cout<<"Please write title file (max 100 char)"<<endl;
getline( cin.ignore(100,'\n'),*title);
}
if(title->length()==NULL){
    cout<<"Please enter title file"<<endl; x->close();
    delete x,title; return export_html();}
*x<<"<html>"<<endl<<"<head><title>"<<*title<<"</title></head>"<<endl<<"<body><table >"<<endl;
for(int z=0;z<=counter_e;z++)
    {
        *x<<"<tr>";
        if(z==0 ) {*x<<"<td>*  </td>";}else{ *x<<"<td>"<<z<<"</td>";}
        for(int i=1;i<=vid;i++)
        {
        *x<<"<td>"<<dane[z][i]<<"</td>"<<endl;
        }
        *x<<"</tr>";
   *x<<endl;
    }
    *x<<"</table><body>"<<endl<<"</html>";
x->close();
delete x,title;
cout<<"save base.html in "<<path<<endl;
scr._sleep(2);
return view_menu();
}

int view_menu()
{
cout<<"Mini Database for xml "<<minidbxml.version<<"."<<minidbxml.subversion<<"."<<minidbxml.nr_update<<" - "<<
minidbxml.get_version_status()<<endl<<
"1.View Database"<<endl<<
"2.Find entry."<<endl<<
"3.Edit Database"<<endl<<
"4.Edit Column Database"<<endl<<
"5.Export to CSV"<<endl<<"6.Export to html "<<endl<<"q.Exit"<<endl;
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
        export_csv();
        break;
    case '6' :

        export_html();
    case 'q':
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

    minidbxml.version=0;
    minidbxml.subversion=0;
    minidbxml.nr_update=6;

    system("echo >>./.data/base.xml");
    pre_load();
    if(argv[1]!=NULL)
    {
    switch(*argv[1])
   {
    case 'c':
    if(argv[2]!=NULL)
    {
        vid++;
    dane[0][vid]=argv[2];
    save_database(0,0);

    cout<<"ok "<<vid<<" "<<argv[2]<<endl;
    }
    break;
    deafult:
    cout<< "correct options"<<endl;
    break;
    case 'e':
    if(argv[2]!=NULL )
       {
        for(int i=0;i<=vid;i++)
        {
         if(argv[2]==dane[0][i])
         {
               counter_e++;
               dane[counter_e][i]=argv[3];
               cout<<"save new entry to '"<<dane[0][i]<<"' column"<<endl;
               save_database(0,0);
            return 0;
         }
         else
         {
           if(i==vid)
           {
           cout<<"no find column";
           }
         }
        }
       }
       break;
       case 'x':
       path=argv[2];
       t=argv[3];
       export_html();
       break;
   }
    }
    else
    {

        view_menu();

    }

}
