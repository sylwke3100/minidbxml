#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "./version.h"
#include <conio.h>
#include <sstream>
using namespace std;
int*session=new int;
struct sessions
{
    public:
    int Create_session()
    {
        *session=0;
        string data;
        srand(time(0));
        *session=rand()%2000000;
        fstream*file= new fstream;
        file->open("./.data/minidbxml.session",ios::in|ios::out|ios::app);
        time_t*ra= new time_t;
        struct tm * timeinfo;

        time ( ra );
        *file<<*session<<"-"<<time(ra)<<endl;
        file->close();
        delete ra,file;
    }
    int End_session()
    {
        int counter;
        string session_list[20][20];
        string*data=new string;
        ifstream*file= new ifstream;
        file->open("./.data/minidbxml.session",ios::in|ios::out|ios::app);

        getline(*file,*data);
        for(int i=0;i<data->length();i++)
        {
          if(data->substr(i,1)=="-")
          {
              counter++;
              session_list[counter][1]=data->substr(0,i);
             session_list[counter][2]=data->substr(i+1,data->length());
          }
        }

        ostringstream v_z;
        v_z << session;
        file->close();
        fstream*d=new fstream;
        for(int z=0;z<counter;z++)
        {
          if(session_list[z][1]==v_z.str()){cout<<"ok"; session_list[z][1]="";session_list[z][2]=""; }
        }
        d->open("./.data/minidbxml.session",ios::in|ios::out|ios::trunc);
        for(int k=0;k<counter;k++)
        {
            if(session_list[k][1].length()!=NULL)
            {
                *d<<session_list[k][1]<<"-"<<session_list[k][2]<<endl;
            }
        }

        delete session,d,file;
    }

};
