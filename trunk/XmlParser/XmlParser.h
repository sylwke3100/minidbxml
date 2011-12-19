#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <fstream>
#include <string>
#include <vector>
#include "XmlParserDebug.h"
#include "XmlParserTags.h"

using namespace std;
class XMLParser
{
private:
    ifstream File_o;
    fstream File_w;
    string BuffFile;
    string BuffSave;
    string NameFile;
    XMLParserDebug Errors;
    XmlParserTags Tags;
public:
    string GetBuffer();
    void GetTagValues(string Name,vector<string> &Values);
    void LoadFile(string FileName);
    void ConvertStandard();
    void ActiveChangeChar(string& Value,int Type);
    void SaveFile();
    void SaveTag(string NameTag,string NameValue);
    void GetErrors(string& Error);
    int IsLoadFile();

};
#endif
