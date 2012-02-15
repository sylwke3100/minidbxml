#include "XmlParserDebug.h"
#define NO_FILE
#define IS_EMPTY
void XMLParserDebug::SetSignalToDebug(int Id,string Text)
{
    switch(Id)
    {
    case 1:
        ErrorString +="No file exists: "+Text+"\n";
        break;
    case 2:
        ErrorString +="File is Empty:  "+Text+"\n";
        break;
    case 3:
        ErrorString +="No found \""+Text+"\" tag in xml file\n";
        break;
    case 4:
        ErrorString +="Detect Tag'"+Text+"'\n";
        break;
    }
}
void XMLParserDebug::GetSignalDebug(string& Value)
{
    Value=ErrorString;
}
