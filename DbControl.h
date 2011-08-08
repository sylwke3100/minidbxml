#ifndef DB_CONTROL_H
#define DB_CONTROL_H

#include <vector>
#include "XmlParser.h"

class DB
{
private:
    string PathName;
    XMLParser *Dbase;
    vector<vector <string> >Db;
    int MaxX;
    int MaxY;
public:
    int PosX;
    int PosY;
    DB(string PathDb);
    string GetPathName();
    string GetEntryById(int X, int Y);
    void SetEntryById(int X,int Y,string Value);
    void CreateEntriesRow();
    void CreateRow(string NameRow);
    void DeleteEntry(int X,int y);
    void DeleteEntriesRow(int X);
    void SaveDb();
    int GetMaxX();
    int GetMaxY();
};
#endif
