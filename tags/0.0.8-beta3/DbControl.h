#ifndef DB_CONTROL_H
#define DB_CONTROL_H

#include <vector>
#include "XmlParser.h"
#include "SessionsStorage.h"
#include "Prefs.h"

class DB
{
private:
    string PathName;
    SessionsStorage *Session;

    XMLParser *Dbase;
    vector<vector <string> >Db;
    Prefs *Pr;
    int MaxX;
    int MaxY;
    int IsLoad;
public:
    int PosX;
    int PosY;
    DB(string PathDb);
    string GetPathName();
    string GetEntryById(int X, int Y);
    void SetEntryById(int X,int Y,string Value);
    void SetById(int X,int Y,string Value);
    void CreateEntriesRow();
    void CreateRow(string NameRow);
    void DeleteEntry(int X,int y);
    void DeleteEntriesRow(int X);
    void SaveDb();
    int GetMaxX();
    int GetMaxY();
    bool IsLoaded();
    ~DB();
};
#endif
