#ifndef XMLPARSERTAGS_H
#define XMLPARSERTAGS_H

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class XmlParserTags
{
public:
    void AddSimpleTag(string Name,string ValueTag);
    void AddOpenTag(string Name);
    void AddCloseTag();
    void Clear();
    string ExportTags();

protected:

private:
    string OpenedTag;
    vector <string> Tags;
    vector <string> Type;
    vector <string> Value;

};

#endif // XMLPARSERTAGS_H
