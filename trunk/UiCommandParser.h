#ifndef UICOMMANDPARSER_H
#define UICOMMANDPARSER_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "DbControl.h"
#include "DbSearch.h"
#include "DbExport.h"
#include "version.h";
using namespace std;
class UiCommandParser
{
private:
    DB * base;
    int IsConnect;
    int Signal;
public:
    void ParseCommand(string Command,int& Signal);
    void Print(string Text);
    void ReadCommandFromFile(string Path);
    void Info();
    void SetSignal(int Singal);
    void SetState(int State);
    int GetSignal();
    int CheckState();
    UiCommandParser();

};

#endif // UICOMMANDPARSER_H
