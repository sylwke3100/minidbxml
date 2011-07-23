#include "DbControl.h"

void DB::CreateDatabase(string PathDb)
{
    Dbase = new XMLParser;
    Dbase -> LoadFile(PathDb);
    if(Dbase->IsLoadFile()==true)
    {
        Db.resize(1);
        Db[0] = Dbase -> GetTagValues("tg");
        vector <string> Tmp;
        vector <string>Ttmp;
        Tmp = Dbase -> GetTagValues("entry");
        Db.resize(Tmp.size()+1);
        for(int z=0; z<Db[0].size(); z++)
        {
            Ttmp = Dbase->GetTagValues(Db[0][z]);
            for(int i=1; i<Tmp.size()+1; i++)
            {
                Db[i].push_back(Ttmp[i-1]);
            }
            Ttmp.clear();
        }
    }
}
string DB::GetEntryById(int x, int y)
{
    return Db[x][y];
}







