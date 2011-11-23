#ifndef DB_CONTROL_H
#define DB_CONTROL_H

#include <vector>
#include "../XmlParser/XmlParser.h"
#include "../SessionsStorage.h"
#include "DbPos.h"
#include "../Prefs.h"

class DB: public DbPos
{

private:

    string PathName;
    SessionsStorage *Session;
    XMLParser *Dbase;
    vector<vector <string> >Db;
    Prefs *Pr;
    int IsLoad;
public:
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
    bool IsLoaded();
    ~DB();
};
#endif
