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
    void SetSignalToDebug(int Id,string Text);
    void GetSignalDebug(string& Value);
};

#endif // XMLPARSERDEBUG_H
