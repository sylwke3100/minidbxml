#ifndef PREFS_H
#define PREFS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class Prefs
{

private:
    vector<vector <string> > StoragePrefs;
    string Path;
public:
    Prefs(string Path);
    string GetPrefs(string Name);
    void SetPrefs(string Name,string Value);
};
#endif
