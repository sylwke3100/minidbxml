#include "Prefs.h"
Prefs::Prefs(string Path)
{
    this->Path=Path;
}
void Prefs::Load()
{
    Buff.clear();
    ifstream*file= new ifstream;
    file->open(Path.c_str(),ios::in|ios::out);
    if(file->is_open())
    {
        while(!file->eof())
        {
            string tmp;
            getline(*file,tmp);
            Buff+=tmp;
        }
    }
    file->close();
}
void Prefs::Set_pref(string Name,string Value)
{
    Load();
    fstream*file= new fstream;
    file->open(Path.c_str(),ios::in|ios::out|ios::trunc);
    int poz_s=0,poz_k=0,j=0,zn=0;
    string wynik;
    for(int i=0; i<Buff.length(); i++)
    {
        if(Buff.substr(i,Name.length()+1)==Name+"=")
        {
            poz_s=i+Name.length()+1;
            j=1;
        }
        if(Buff.substr(i,1)==";" and j==1)
        {
            poz_k=i-1;
            wynik+=Name+"="+Value+";\r\n";
            j=0;
            zn=1;
        }
        if(j==0)
            wynik+=Buff.substr(i,1);
    }
    if(zn==0)
        *file<<Name<<"="<<Value<<";"<<endl;
    *file<<wynik;
    file->close();
    delete file;
}
string Prefs::Get_pref(string Name)
{
    Load();
    int poz_s=0,poz_k=0,j=0;
    for(int i=0; i<Buff.length(); i++)
    {
        if(Buff.substr(i,Name.length()+1)==Name+"=")
        {
            poz_s=i+Name.length()+1;
            j=1;
        }
        if(Buff.substr(i,1)==";" and j==1)
        {
            poz_k=i;
            return Buff.substr(poz_s,(poz_k-poz_s));
        }
    }
}
