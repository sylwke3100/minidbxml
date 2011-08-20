#include "XmlParserDebug.h"
#define NO_FILE
#define IS_EMPTY
void XMLParserDebug::SetSignalToDebug(int Id,string text)
{
    if(Id==1)
        ErrorString +="No file exists: "+text+"\n";
    if(Id==2)
        ErrorString +="File is Empty:  "+text+"\n";
    if(Id==3)
        ErrorString +="No found \""+text+"\" tag in xml file";
}
void XMLParserDebug::GetSignalDebug(string& Value)
{
    Value=ErrorString;
}
