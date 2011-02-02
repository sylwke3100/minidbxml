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
int get_db_list(string paths)
{
string*lists=new string;
string list_db[1000];
int*il=new int;
int*chose=new int;
*il=0;
*chose=0;
DIR *Dir;

struct dirent *DirEntry;
Dir = opendir(paths.c_str());
cout<<" Set database"<<endl<<endl;
cout<<"0.Exit"<<endl;
while(DirEntry=readdir(Dir))
{
   *lists=DirEntry->d_name;
   if(lists->length()>=4){
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
view_menu();

}
else {
    if(*chose==0){return 0;}
    if(*chose==*il+1){create_db();}
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
