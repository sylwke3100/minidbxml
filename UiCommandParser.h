#ifndef UICOMMANDPARSER_H
#define UICOMMANDPARSER_H
#include <iostream>
#include <string>
#include <sstream>
#include "DbControl.h"
using namespace std;
class UiCommandParser
{
private:
    DB * base;
public:
    void ParseCommand(string Command,int& Signal);

};

#endif // UICOMMANDPARSER_H
