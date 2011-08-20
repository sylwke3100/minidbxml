#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <sys/prctl.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
using namespace std;
int create_db();
string path_db="";
int st_p=0;
int get_db_list(string paths)
{
    if(path_db.length()==NULL)
    {
        string*lists=new string;
        string list_db[1000];
        int*il=new int;
        int*chose=new int;
        *il=0;
        *chose=0;
        DIR *Dir;
        struct dirent *DirEntry;
        cout<<"MiniDBXML - Set database"<<endl<<endl;
        if(Dir = opendir(paths.c_str()))
        {
            cout<<"0.Exit"<<endl;
            while(DirEntry=readdir(Dir))
            {
                *lists=DirEntry->d_name;
                if(lists->length()>=4)
                {
                    if(lists->substr(lists->length()-3,3)=="xml")
                    {
                        *il=*il+1;
                        cout<<*il<<"."<<lists->substr(0,lists->length()-4)<<"";
                        list_db[*il]=lists->substr(0,lists->length()-4);
                        cout<<endl;
                    }
                }
            }
            cout<<*il+1<<".New database"<<endl;
            cin>>*chose;
            if(*chose<=*il && *chose>0)
            {
                path_db=paths+list_db[*chose];
                extern int view_menu();
                system("clear");
                return 1;
            }
            else
            {
                if(*chose==0)
                {
                    return 0;
                }
                if(*chose==*il+1)
                {
                    create_db();
                }
            }
        }
        else
        {
            cout<<" Please create folder ./.data/"<<endl;
        }
    }
    else
    {
        if(path_db.length()!=NULL and st_p==1)
        {
            path_db="";
            get_db_list(paths);
        }
        return 1;
    }
}
int create_db()
{
    string*title=new string;
    cout<<"Please enter name database "<<endl;
    getline( cin.ignore(100,'\n'),*title);
    if(title->length()!=NULL)
    {
        string temp_p="./.data/"+*title+".xml";
        string temp_pw="./.data/"+*title+".session";
        fstream*file= new fstream;
        fstream*file_s=new fstream;
        file->open(temp_p.c_str(),ios::out|ios::app);
        file_s->open(temp_pw.c_str(),ios::out|ios::app);
        *file<<" "<<endl;
        *file_s<<" "<<endl;
        file->close();
        file_s->close();
        delete title;
        delete file;
        delete file_s;
        cout<<"Database created";
        get_db_list("./.data/");
    }
}
