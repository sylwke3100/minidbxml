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
    void LoadFile(string FileName);
    string GetBuffer();
    vector<string> GetTagValues(string Name);
    void SaveFile();
    void SaveTag(string NameTag,string NameValue,int Level);
    int IsLoadFile();

};
#endif
