#include "XmlParserTags.h"


void XmlParserTags::AddSimpleTag(string Name,string ValueTag)
{
    Tags.push_back(Name);
    Value.push_back(ValueTag);
    Type.push_back("[n]");
}
void XmlParserTags::AddOpenTag(string Name)
{
    Tags.push_back(Name);
    Type.push_back("[o]");
    Value.push_back("");
    OpenedTag = Name;
}
void XmlParserTags::AddCloseTag()
{
    if(OpenedTag.length()>0)
    {
        Tags.push_back(OpenedTag);
        Type.push_back("[c]");
        Value.push_back("");
        OpenedTag.clear();
    }
}

string XmlParserTags::ExportTags()
{
    string Buff;

    for(int i=0; i<Type.size(); i++)
    {
        if(Type[i]=="[n]")
            Buff+="<"+Tags[i]+">"+Value[i]+"</"+Tags[i]+">\n";
        if(Type[i]=="[o]")
            Buff+="<"+Tags[i]+">\n";
        if(Type[i]=="[c]")
            Buff+="</"+Tags[i]+">\n";
    }
    return Buff;
}
