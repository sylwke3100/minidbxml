#ifndef DB_CONTROL_H
#define DB_CONTROL_H

#include <vector>
#include "XmlParser.h"

class DB
{
private:
    XMLParser *Dbase;
    vector<vector <string> >Db;
    int MaxX;
    int MaxY;
public:
    DB(string PathDb);
    string GetEntryById(int x, int y);
    void SetEntryById(int x,int y,string Value);
    void CreateEntriesRow();
    void DeleteEntry(int x,int y);
    void DeleteEntriesRow(int X);
    int GetMaxX();
    int GetMaxY();
};
#endif
