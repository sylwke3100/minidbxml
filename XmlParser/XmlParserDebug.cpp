#include "XmlParserDebug.h"
#define NO_FILE
#define IS_EMPTY
void XMLParserDebug::SetSignalToDebug(int Id,string Text)
{
    if(Id==1)
        ErrorString +="No file exists: "+Text+"\n";
    if(Id==2)
        ErrorString +="File is Empty:  "+Text+"\n";
    if(Id==3)
        ErrorString +="No found \""+Text+"\" tag in xml file\n";
    if (Id==4)
        ErrorString +="Detect Tag'"+Text+"'\n";

}
void XMLParserDebug::GetSignalDebug(string& Value)
{
    Value=ErrorString;
}
