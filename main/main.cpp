#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "./version.h"
using namespace std;
int view_menu();
string dane[10][20];
int main();
int vid=1;
int st=0;
int parse_xml_tag(string name_tag_find,int id)
{
   vid++;
    string mem;
    string name_tag=name_tag_find;
    string name_tag_;
    ifstream file;
    int lst=1;
    int buf=0;
    file.open("plik.xml",ios::in);
    while(!file.eof())
    {
      getline(file,mem);
      name_tag_="<"+name_tag_find+">";
      for(int i=0;i<mem.length();i++){
      if(mem.substr(i,i+name_tag_.length())==name_tag_)
      {
        name_tag="</"+name_tag_find+">";
          for(int m=i+name_tag_.length();m<mem.length();m++){

              if(mem.substr(m,m+name_tag.length())==name_tag){
                   dane[id][lst++]=mem.substr(i+name_tag_.length(),m-name_tag.length()+1) ;


              }
          }

      }
      }

    }

    file.close();
}

int pre_load()
{
    vid=1;
    string mv;
    int st_=0,ui=0;
    int l=0;
    for(int n=1;n<=20;n++){
for(int i=1;i<=vid;i++)
    {

        dane[0][i]="";
        if(dane[i][n].length()!=NULL){ dane[i][n]="";}
    }
    }
    ifstream file;
    file.open("plik.xml",ios::in);
    while(!file.eof())
        {
            ui++;

    getline(file,mv);
        if(mv=="<tag>" ){  st_=1; } else{
        if(mv.length()!=NULL){
            if(mv=="</tag>")
            {st_=0; }
            else{
                if(st_==1){
                    l++;

                dane[0][l]=mv;
                parse_xml_tag(mv,l);

                }
        }
        }
        }
        }
        file.close();


}

int view_database()
{
    system("clear");
    pre_load();

    int d=0,wynik=0,v=1;
            cout<<"* |";
            for(int i=1;i<vid;i++)
            {

                if(dane[0][i].length()!=NULL){
                cout<<dane[0][i]<<" |";
                }

            }
            cout<<endl<<"---------------------------"<<endl;

        for(int m=1;m<=20;m++)
        {


            for(int i=1;i<vid;i++)
            {

                if(dane[i][m].length()!=NULL){
                if(d==0){cout<<m<<".|"; d=1;}

                cout<<dane[i][m];
                if(dane[i][m].length()<dane[0][i].length())
                {
                    wynik= dane[0][i].length()-dane[i][m].length();
                   for(v=1;v<wynik+1;v++){
                        cout<<" ";
                        }
                }
                cout<<" |";
                }
                else { cout<<endl<<"_______________"<<endl; return view_menu();}
            }
            cout<<endl;
            d=0;
        }


    }


int save_database(int u,int wid)
{

    int d,z=1;
    fstream x;
    x.open("plik.xml",ios::in|ios::out);
        x.clear();
        x<<"<?xml version='1.0' encoding='UTF-8'?>"<<endl;
        x<<"<db>"<<endl;
        x<<"<tag>"<<endl;
        for(int y=1;y<=vid;y++)
        {
            if(dane[0][y].length()!=NULL)
            {
            x<<dane[0][y]<<endl;
            }
        }
        x<<"</tag>"<<endl<<"<body>"<<endl;

        for(int m=1;m<20;m++)
        {
            for(int i=1;i<=vid;i++)
            {

                if(dane[i][m].length()!=NULL){


                 if(i==1){ x<<"<entry id='"<<z++<<"' >"<<endl;}

               x<<"<"<<dane[0][i]<<">"<<dane[i][m]<<"</"<<dane[0][i]<<">"<<endl;

                }
                else { if((u==1 and wid>0))  { x<<endl;}
                    else{if(m==i and dane[0][i].length()!=NULL) {x<<"<"<<dane[0][i]<<">"<<" "<<"</"<<dane[0][i]<<">"<<endl;}
                    }}

            }

            if(dane[1][m].length()!=NULL or dane[2][m].length()!=NULL){x<<"</entry>"<<endl;}
        }
    x<<"</body>"<<endl<<"</db>";
    x.close();
    pre_load();
    }
int find_entry()
{
    bool end_l=false;
    system("clear");
    string v_dataf;
    pre_load();
    cout<<"Please enter text search"<<endl;
    cin>>v_dataf;
    cout<<"Result for  "<<v_dataf<<endl<<"-----------------------"<<endl;

    for(int m=1;m<vid;m++)
            {

                if(dane[0][m].length()!=NULL){
                cout<<dane[0][m]<<" |";
                }

            }
    cout<<endl<<"________________________"<<endl;
    for(int i=0;i<20;i++)
    {
      for(int x=0;x<vid;x++)
      {
          if(dane[x][i].length()!=NULL)
          {
              if(v_dataf==dane[x][i])
              {
                  for(int m=1;m<vid;m++)
                  {
                  cout<<dane[m][i]<<" |";
                  end_l=true;
                  }
              }

         }

         if(end_l==true){cout<<endl;end_l=false;}
      }


    }

    cout<<endl;
    return view_menu();
}
int edit_col_database()
{
    pre_load();
    system("clear");
    int v,i;
    string t;
    cout<<"Choise cols to edit:"<<endl<<endl<<"0 .New"<<endl;
    for(i=1;i<vid;i++)
    {

        if(dane[0][i].length()!=NULL)
        {
        cout<<i<<" ."<<dane[0][i]<<endl;
        }
    }
    cout<<endl;
    cin>>v;
    if(v==0){ cout<<"Enter name cols"<<endl; cin>>t;cout<<endl<<"Adds cols: "<<t<<"at id "<<i<<" to database"; dane[0][i]=t; vid++; } else {
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
   for(m=1;m<20;m++)
    {
    if(dane[1][m].length()!=NULL)
    {

            cout<<m<<"."<<dane[1][m]<<endl;
            z=m;

    }
    }
   cout<<z+1<<".New entry"<<endl;
   cout<<"Enter ID entry:";
   cin>>id_w;
   system("clear");
   cout<<"Entry ID:"<<id_w<<"-"<<dane[1][id_w];
   cout<<endl<<"What do you want to edit?"<<endl;
    for(int i=1;i<vid;i++)
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
                dane[a][id_w]="";

            }

    }
    else{
        if(c>(vid+1)){ cout<<"Wrong choice"<<endl;}
        else
        {
            cout<<endl<<"Editing "<<dane[0][c]<<": ";
            char*swe;


           getline( cin.ignore(100,'\n'),value);

            dane[c][id_w]=value;
        }
    }
    save_database(u,id_w);
    return view_menu();

}
int view_menu()
{

    cout<<"Mini Database for xml 0.0.3"<<endl<<endl<<"1.View Database"<<endl<<"2.Find entry."<<endl<<"3.Edit Database"<<endl<<"4.Edit Cols Database"<<endl<<"q.Exit"<<endl;
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

int main()
{
 system("echo ''>>plik.xml");
 pre_load();
 view_menu();
}

