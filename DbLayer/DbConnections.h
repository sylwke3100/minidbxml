#ifndef DB_CONNECTIONS_H
#define DB_CONNECTIONS_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "DbControl.h"
using namespace std;
class DbConnections
{
public:
    int StateConnect ;
    string SearchConnection(string DbValue,DB& B,int Type,string Value);
    string GetNormalConnect(int X, int Y,DB B);
    string BetweenConnect(string Path,int X,int Y, DB B);
    void SetNormalConEntry(string Value,DB& B,int X,int Y);
    void SetBettwenConEntry(string Value,int X,int Y,string Path);
};
#endif
