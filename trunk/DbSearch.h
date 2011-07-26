#include "DbControl.h"
class DbSearch
{
private:
    string NameValue;
public:
    void SearchInDb(DB* Base,vector<string>& Summary);
    void SetSearchValue(string NameValue);
};
