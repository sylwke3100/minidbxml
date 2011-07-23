#ifndef DB_CONTROL_H
#define DB_CONTROL_H

#include <vector>
#include "XmlParser.h"

class DB
{
private:
    XMLParser *Dbase;
    vector<vector <string> >Db;
public:
    void CreateDatabase(string PathDb);
    string GetEntryById(int x, int y);
};
#endif
