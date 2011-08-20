#ifndef XMLPARSERDEBUG_H
#define XMLPARSERDEBUG_H
#include <string>
using namespace std;

class XMLParserDebug
{
private:
    string ErrorString;
    int Count;
public:
    void SetSignalToDebug(int Id,string text);
    void GetSignalDebug(string& Value);
};

#endif // XMLPARSERDEBUG_H
