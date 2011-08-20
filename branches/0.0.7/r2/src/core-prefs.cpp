/*
MiniDBXML - Core preferences (core-prefs.h)

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
#include <fstream>
using namespace std;
class Prefs
{

private:
    string buff;
    string path;
public:

    Prefs(string path)
    {
        this->path=path;
    }
    void load()
    {
        buff.clear();
        ifstream*file= new ifstream;
        file->open(path.c_str(),ios::in|ios::out);
        if(file->is_open())
        {
            while(!file->eof())
            {
                string tmp;
                getline(*file,tmp);
                buff+=tmp;
            }
        }
        file->close();
    }
    void set_pref(string name,string value)
    {
        load();
        fstream*file= new fstream;
        file->open(path.c_str(),ios::in|ios::out|ios::trunc);
        int poz_s=0,poz_k=0,j=0,zn=0;
        string wynik;
        for(int i=0; i<buff.length(); i++)
        {
            if(buff.substr(i,name.length()+1)==name+"=")
            {
                poz_s=i+name.length()+1;
                j=1;
            }
            if(buff.substr(i,1)==";" and j==1)
            {
                poz_k=i-1;
                wynik+=name+"="+value+";\r\n";
                j=0;
                zn=1;
            }
            if(j==0)
                wynik+=buff.substr(i,1);
        }
        if(zn==0)
            *file<<name<<"="<<value<<";"<<endl;
        *file<<wynik;
        file->close();
        delete file;
    }
    string get_pref(string name)
    {
        load();
        int poz_s=0,poz_k=0,j=0;
        for(int i=0; i<buff.length(); i++)
        {
            if(buff.substr(i,name.length()+1)==name+"=")
            {
                poz_s=i+name.length()+1;
                j=1;
            }
            if(buff.substr(i,1)==";" and j==1)
            {
                poz_k=i;
                return buff.substr(poz_s,(poz_k-poz_s));
            }
        }
    }
};
