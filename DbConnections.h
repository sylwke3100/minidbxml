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
private:


public:
    string SearchConnection(string DbValue,DB& B);
    string GetNormalConnect(int X, int Y,DB B);
};
#endif
