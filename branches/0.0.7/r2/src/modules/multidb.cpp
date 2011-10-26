/*
MiniDBXML - Multi Database Module (multidb.h)

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.

 */
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
#include <sstream>
#include "../version.h"

using namespace std;

string path_db;
class MultiDB
{

public:
    int Get_db_list(string paths,int st_p)
    {
        if(path_db.length()==NULL and st_p==0)
        {
            string*lists=new string;
            vector <string> list_db;
            int chose=0;
            DIR *Dir;
            list_db.push_back(" ");
            struct dirent *DirEntry;
            cout<<"Mini Database for XML "<<AutoVersion::_MAJOR<<"."<<AutoVersion::_MINOR<<"."<<
                AutoVersion::_REVISION<<" - "<<AutoVersion::_STATUS<<" build "<<AutoVersion::_BUILDS_COUNT<<" Set database"<<endl<<endl;
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
                            cout<<list_db.size()<<"."<<lists->substr(0,lists->length()-4)<<"";
                            list_db.push_back(lists->substr(0,lists->length()-4));
                            cout<<endl;
                        }
                    }
                }
                cout<<list_db.size()<<".New database"<<endl;
                cin>>chose;
                if(chose<=list_db.size()-1 && chose>0)
                {
                    path_db=paths+list_db[chose];
                    extern int view_menu();
                    system("clear");
                    return 1;
                }
                else
                {
                    if(chose==0)
                    {
                        return 0;
                    }
                    if(chose==list_db.size())
                    {
                        Create_db(list_db,paths,st_p);
                    }
                    if(chose>list_db.size())
                    {
                        cout<<"Correct Choose"<<endl;
                        return  Get_db_list(paths,st_p);
                    }
                }
            }
            else
            {
                cout<<" Please create folder "<<paths<<endl;
            }
        }
        else
        {
            if(path_db.length()!=NULL and st_p==1)
            {
                path_db="";
                return Get_db_list(paths,st_p);
            }
            if(path_db.length()==NULL and st_p==2)
            {
                return 1;
            }
            return 1;
        }
    }
    int Create_db(vector <string> files,string paths,int st_p)
    {
        string*title=new string;
        cout<<"Please enter name database "<<endl;
        getline( cin.ignore(100,'\n'),*title);
        for(int i=0; i<files.size(); i++)
        {
            if(*title==files[i])
            {
                char w;
                cout<<"Do you overwrite DB ? (y/n)"<<endl;
                cin>>w;
                switch (w)
                {
                case 'y':
                    break;
                case 'n':
                    system("clear");
                    return Get_db_list(paths,st_p);
                    break;
                }
            }
            else
            {

            }
        }
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
            return Get_db_list(paths,st_p);
        }
    }
};