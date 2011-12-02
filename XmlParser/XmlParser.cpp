#include "XmlParser.h"
#include <iostream>
using namespace std;
void XMLParser::LoadFile(string FileName)
{
    File_o.open(FileName.c_str(),ios::in);
    if(File_o.is_open())
    {
        NameFile = FileName;
        while(!File_o.eof())
        {
            string tmp;
            getline(File_o,tmp);
            BuffFile+=tmp;
        }
        File_o.close();
    }
    else
    {
        Errors.SetSignalToDebug(1,FileName);
    }
}
string XMLParser::GetBuffer()
{
    return BuffFile;
}
void XMLParser::GetTagValues(string Name,vector<string> &Values)
{
    if(BuffFile.length()<=0)
    {
        Errors.SetSignalToDebug(2,NameFile);
    }
    else
    {
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
                Errors.SetSignalToDebug(4,Name);
            }
            if(Values.size()<0) Errors.SetSignalToDebug(3,Name);
        }
    }
}
void XMLParser::SaveFile()
{
    File_w.open(NameFile.c_str(),ios::out|ios::in|ios::trunc);
    File_w << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    File_w<< BuffSave;
    File_w.close();
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
void XMLParser::ActiveChangeChar(string& Value,int Type)
{
    string tmp;
    for(int i =0; i<Value.length(); i++)
    {
        if (Type==0)
        {
            string t = Value.substr(i,1);
            char ts = t[0];
            switch(ts)
            {
            case '>':
                tmp+="&gt;";
                break;
            case '<':
                tmp+="&lt;";
                break;
            default:
                tmp+=Value.substr(i,1);
                break;
            }
        }
        else
        {
            if(Value.substr(i,4)=="&gt;")
            {
                i+=4;
                tmp+=">";
            }
            else
            {
                if (Value.substr(i,4)=="&lt;")
                {
                    i+=4;
                    tmp+="<";
                }
                else
                    tmp+=Value.substr(i,1);
            }
        }
    }
    Value = tmp;
}
int XMLParser::IsLoadFile()
{
    if(BuffFile.length()>0) return 1;
    else return 0;
}
void XMLParser::GetErrors(string& Error)
{
    Errors.GetSignalDebug(Error);
}
void XMLParser::ConvertStandard()
{
    string Tmp;
    for(int i=0; i<BuffFile.length(); i++)
    {
        if(BuffFile.substr(i,6)=="<entry")
        {
            i=i+6;
            Tmp +="<entry>";
            i = (int)BuffFile.find(">",i);
        }
        else Tmp+=BuffFile.substr(i,1);
    }
    BuffFile = Tmp;
}
