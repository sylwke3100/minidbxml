#ifndef DBEXPORT_H
#define DBEXPORT_H

#include <string>
#include <fstream>
#include "DbControl.h"
using namespace std;
class DbExport
{
private:
    string Path;
    fstream File;
    int IsOpen;
public:
    DbExport(string FileName);
    void ExportToCsv(DB &B);

};



#endif
