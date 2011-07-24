#include "XmlParser.h"

using namespace std;
void XMLParser::LoadFile(string FileName)
{
    file_o.open(FileName.c_str(),ios::out);
    NameFile = FileName;
    while(!file_o.eof())
    {
        string tmp;
        getline(file_o,tmp);
        BuffFile+=tmp;
    }
    file_o.close();
}
string XMLParser::GetBuffer()
{
    return BuffFile;
}
vector<string> XMLParser::GetTagValues(string Name)
{
    vector<string> Values;
    int Istag = 0;
    for(int i=0; i<BuffFile.length(); i++)
    {
        if(BuffFile.substr(i,Name.length()+3)=="</"+Name+">" && Istag>=0)
        {
            Values.push_back(BuffFile.substr(Istag,(i-Istag)));
            i+=Name.length()+3;
            Istag = -1;
        }
        if(BuffFile.substr(i,Name.length()+2)=="<"+Name+">")
        {
            i+=Name.length()+2;
            Istag = i;
        }

    }
    return Values;
}
void XMLParser::SaveFile()
{
    file_w.open(NameFile.c_str(),ios::out|ios::in|ios::trunc);
    file_w << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    file_w<< BuffSave;
    file_w.close();
    BuffSave.clear();
}
void XMLParser::SaveTag(string NameTag,string NameValue,int Level)
{
    string P;
    for(int i=0; i<Level; i++)
    {
        P+=" ";
    }
    if(NameValue!="!OPEN" and NameValue!="!CLOSE")
        BuffSave+=P+"<"+NameTag+">"+NameValue+"</"+NameTag+">\n";
    else
    {
        if(NameValue=="!OPEN")
            BuffSave+=P+"<"+NameTag+">\n";
        if(NameValue=="!CLOSE")
            BuffSave+=P+"</"+NameTag+">\n";
    }
}

int XMLParser::IsLoadFile()
{
    if(BuffFile.length()>0) return 1;
    else return 0;
}

