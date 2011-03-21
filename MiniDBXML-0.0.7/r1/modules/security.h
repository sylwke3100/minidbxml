#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <cstring>
#include <sys/prctl.h>
#include <signal.h>
using namespace std;
int*session=new int;
extern string path_db;
pid_t chilpid,pid;
int Create_session()
{
    string*p_session=new string;
    *p_session=path_db+".session";
    *session=0;
    string data;
    srand(time(0));
    *session=rand()%200000;
    fstream*file= new fstream;
    file->open(p_session->c_str(),ios::in|ios::out|ios::app);
    time_t*ra= new time_t;
    struct tm * timeinfo;
    time ( ra );
    *file<<*session<<"-"<<time(ra)<<endl;
    file->close();
    delete ra;
    delete file;
    delete p_session;
}
int End_session()
{
    string*p_session=new string;
    *p_session=path_db+".session";
    int counter=0;
    string session_list[20][20];
    string*data=new string;
    ifstream*file= new ifstream;
    file->open(p_session->c_str(),ios::in|ios::out);
    while(file->eof())
    {
        getline(*file,*data);
        for(int i=0; i<data->length(); i++)
        {
            if(data->substr(i,1)=="-")
            {
                counter++;
                cout<<counter<<endl;
                session_list[counter][1]=data->substr(0,i);
                session_list[counter][2]=data->substr(i+1,data->length());
            }
        }
    }
    ostringstream v_k;
    v_k << session;
    string v_z=v_k.str();
    file->close();
    fstream*d=new fstream;
    cout<<counter;
    for(int zqe=0; zqe<=counter; zqe++)
    {
        if(session_list[zqe][1]==v_z)
        {
            session_list[zqe][1]="";
            session_list[zqe][2]="";
        }
    }
    d->open(p_session->c_str(),ios::in|ios::out|ios::trunc);

    for(int k=0; k<=counter; k++)
    {
        if(session_list[k][1].length()!=NULL)
        {
            *d<<session_list[k][1]<<"-"<<session_list[k][2]<<endl;
        }
    }
    d->close();
    delete d;
    delete file;
    delete p_session;
}
int Update_session()
{
    string*p_session=new string;
    *p_session=path_db+".session";
    int*is_session=new int;
    *is_session=0;
    time_t*ra= new time_t;
    struct tm * timeinfo;
    time ( ra );
    int counter=0;
    string session_list[20][20];
    string*data=new string;
    ifstream*file= new ifstream;
    file->open(p_session->c_str(),ios::in|ios::out);
    while(!file->eof())
    {
        getline(*file,*data);
        for(int i=0; i<data->length(); i++)
        {
            if(data->substr(i,1)=="-")
            {
                counter++;
                session_list[counter][1]=data->substr(0,i);
                session_list[counter][2]=data->substr(i+1,data->length());
            }
        }
    }
    ostringstream es;
    ostringstream ks;
    ks <<time(ra);
    es << *session;
    string v_z = es.str();
    file->close();
    fstream*d=new fstream;
    for(int z=0; z<=counter; z++)
    {
        if(session_list[z][1]==v_z)
        {
            session_list[z][1]=v_z;
            session_list[z][2]=ks.str();
            *is_session=1;
        }
    }
    if(*is_session==0)
    {
        system("clear");
        cout<<"Error Session ... Program Closed"<<endl;
        sleep(4);
        kill(pid,SIGKILL);
    }
    d->open(p_session->c_str(),ios::in|ios::out|ios::trunc);

    for(int k=0; k<=counter; k++)
    {
        if(session_list[k][1].length()!=NULL)
        {
            *d<<session_list[k][1]<<"-"<<session_list[k][2]<<endl;
        }
    }
    d->close();
    delete d;
    delete file;
    delete ra;
    delete is_session;
    delete p_session;
    sleep(5);
    Update_session();
}
int Kill_session(int id)
{
    system("clear");
    fstream*d=new fstream;
    int*k_se=new int;
    int counter=0;
    string*p_session=new string;
    *p_session=path_db+".session";
    int*is_session=new int;
    *is_session=0;
    string session_list[20][20];
    string*data=new string;
    ifstream*file= new ifstream;
    file->open(p_session->c_str(),ios::in|ios::out);
    cout<<" List sesssion:"<<endl<<endl;
    while(!file->eof())
    {
        getline(*file,*data);
        for(int i=0; i<data->length(); i++)
        {
            if(data->substr(i,1)=="-")
            {
                counter++;
                session_list[counter][1]=data->substr(0,i);
                session_list[counter][2]=data->substr(i+1,data->length());
                cout<<counter<<"."<<session_list[counter][1]<<endl;
            }
        }
    }
    file->close();
    if(id==NULL)
    {
        cout<<endl<<"Enter number session to kill"<<endl;
        cin>>*k_se;
    }
    else
    {
        *k_se=id;
    }

    if(*k_se>0 and *k_se<=counter)
    {
        session_list[*k_se][1]="";
        d->open(p_session->c_str(),ios::in|ios::out|ios::trunc);
        for(int k=0; k<=counter; k++)
        {
            if(session_list[k][1].length()!=NULL)
            {
                *d<<session_list[k][1]<<"-"<<session_list[k][2]<<endl;
            }
        }
    }
    d->close();
    delete k_se;
    delete d;
    delete file;
    delete is_session;
    delete p_session;
    return 0;
}
int Manage_session()
{
    chilpid=getpid();
    if(*session>0)
    {
        Update_session();
    }
    if(*session<=0)
    {
        Create_session();
    }
    sleep(1);
    Manage_session();
}
