#ifndef PREFS_H
#define PREFS_H

#include <string>
#include <fstream>
using namespace std;
class Prefs
{

private:
    string Buff;
    string Path;
public:
Prefs(string Path);
void Load();
void Set_pref(string Name,string Value);
string Get_pref(string Name);
};
#endif
