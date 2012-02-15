#include "Prefs.h"

Prefs::Prefs(string Path)
{
    string Buff;
    this->Path = Path;
    fstream File (Path.c_str(),ios::out|ios::in);
    int count =0;
    if(File.is_open()==true)
    {
        while (!File.eof())
        {
            getline(File,Buff);
            for (int i=0; i<Buff.length(); i++)
            {
                if(Buff.substr(i,1)=="=")
                {
                    if((int)Buff.find(";",i)>0)
                    {
                        StoragePrefs.resize(StoragePrefs.size()+1);
                        StoragePrefs[count].push_back(Buff.substr(0,i));
                        StoragePrefs[count].push_back(Buff.substr((int)Buff.find("=",i)+1,(int)Buff.find(";",i)-((int)Buff.find("=",i)+1)));
                        cout<<StoragePrefs[count][0];
                        count++;
                    }
                }
            }
            File.close();
        }
    }
    else cout<<"Error: File isn't exits ";
}
string Prefs::GetPrefs(string Name)
{
    for(int i=0; i<StoragePrefs.size(); i++)
    {
        if(StoragePrefs[i][0]==Name)
            return StoragePrefs[i][1];
    }
    return "[NONE]";
}
void  Prefs::SetPrefs(string Name,string Value)
{
    for(int a = 0; a<StoragePrefs.size(); a++)
    {
        if(StoragePrefs[a][0]==Name)
            StoragePrefs[a][1]=Value;
    }
    string T;
    fstream File (Path.c_str(),ios::out|ios::in|ios::trunc);
    if(File.is_open()==true)
    {
        for(int i=0; i<StoragePrefs.size(); i++)
        {
            T += StoragePrefs[i][0]+"="+StoragePrefs[i][1]+";";
        }
        File<<T;
        File.close();
    }
}
