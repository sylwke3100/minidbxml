#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;
class XMLParser
{
private:
    ifstream file_o;
    fstream file_w;
    string BuffFile;
    string BuffSave;
    string NameFile;
public:
    string GetBuffer();
    vector<string> GetTagValues(string Name);
    void LoadFile(string FileName);
    void SaveFile();
    void SaveTag(string NameTag,string NameValue,int Level);
    int IsLoadFile();

};
#endif
