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
    int IsConnect;
public:
    void ParseCommand(string Command,int& Signal);
    void Print(string Text);
    void Info();
    UiCommandParser();

};

#endif // UICOMMANDPARSER_H
