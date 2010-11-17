#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "./version.h"
using namespace std;
int view_menu();
string dane[2000][2000];
int main(int argc, char *argv[]);
int vid=1;
int counter_e=0;
int parse_xml_tag(string name_tag_find,int id)
{
    vid=id;
    string*mem=new string;
    string*name_tag=new string;
    *name_tag=name_tag_find;
    string*name_tag_=new string ;
    ifstream*file= new ifstream;
    file->open("plik.xml",ios::in);
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
                   dane[counter_e][vid]=mem->substr(i+name_tag_->length(),m-name_tag->length()+1) ;

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
    file->open("plik.xml",ios::in);
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
                dane[0][l]=*mv;
                parse_xml_tag(*mv,l);

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
    system("clear");
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
            }
            h++;
            }
        }
        cout<<endl<<endl;
     if(h==0){cout<<"Empty database!!!"<<endl;return view_menu();}
    return view_menu();
    }

int save_database(int u,int wid)
{
    int d=1,z=1;
    fstream*x= new fstream;
    x->open("plik.xml",ios::in|ios::out|ios::trunc);
        *x<<"<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"<<endl;
        *x<<"<db>"<<endl;
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        *x<<"<header>"<<endl<<"<Program>MiniDBXML</Program>"<<endl<<"<Version>0.0.4 - Alpha </Version>"<<endl<<"<Time_Date>"<<asctime (timeinfo)<<"</Time_Date>"<<endl<<"</header>"<<endl;
        *x<<"<tag>"<<endl;
        for(int y=1;y<=vid;y++)
        {
            if(dane[0][y].length()!=NULL)
            {
            *x<<dane[0][y]<<endl;
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
    system("clear");
    string *v_dataf=new string;
    pre_load();
    cout<<"Please enter text search"<<endl;
    cin>>*v_dataf;
    cout<<"Result for  "<<*v_dataf<<endl<<"-----------------------"<<endl;

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

              if(*v_dataf==dane[x][i].substr(0,v_dataf->length()))
              {
                  for(int m=1;m<=vid;m++)
                  {
                  cout<<dane[i][m]<<" |";
                  *end_l=true;
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
    system("clear");
    int v,i;
    string t;
    cout<<"Choise cols to edit:"<<endl<<endl<<"0 .New"<<endl;
    for(i=1;i<=vid;i++)
    {

        if(dane[0][i].length()!=NULL)
        {
        cout<<i<<" ."<<dane[0][i]<<endl;
        }
    }
    cout<<endl;
    cin>>v;
    if(v==0){ cout<<"Enter name cols"<<endl; cin>>t;cout<<endl<<"Adds cols: "<<t<<" at id "<<i<<" to database"; dane[0][i]=t; vid++; } else {
     cout<<"Enter new name cols"<<endl; cin>>t; dane[0][v]=t;
     }
    cout<<endl<<endl;
    save_database(0,i+1);
    return view_menu();
}

int edit_database()
{
   int u=0;
   int m=0;
   pre_load();
   system("clear");
   int id_w=0,c=0,z=0,p=0;
   string value;
   z=0;
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
   system("clear");
   cout<<"Entry ID:"<<id_w<<"-"<<dane[id_w][1];
   cout<<endl<<"What do you want to edit?"<<endl;
    for(int i=1;i<=vid;i++)
    {
        p++;
        cout<<i<<"."<<dane[0][i]<<endl;
    }
    cout<<p+1<<".Delete entry?"<<endl;
    cin>>c;
    if(c==(p+1))
    {
        cout<<"deleted entry !!!"<<endl;
        u=1;
        for(int a=1;a<=vid;a++)
            {
                dane[id_w][a]="";

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
    return view_menu();

}
int view_menu()
{

cout<<"Mini Database for xml 0.0.4"<<endl<<endl<<"1.View Database"<<endl<<"2.Find entry."<<endl<<"3.Edit Database"<<endl<<"4.Edit Cols Database"<<endl<<"q.Exit"<<endl;
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
    system("echo ''>>plik.xml");
    pre_load();
    view_menu();
}

