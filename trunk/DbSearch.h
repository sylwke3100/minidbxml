#ifndef DBSEARCH_H
#define DBSEARCH_H
#include "DbControl.h"
class DbSearch
{
private:
    string NameValue;
public:
    void SearchInDb(DB* Base,vector<string>& Summary);
    void SetSearchValue(string NameValue);
};
#endif
