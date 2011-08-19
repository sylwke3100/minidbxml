#include "DbExport.h"

DbExport::DbExport(string FileName)
{
    Path = FileName;
    File.open(Path.c_str(),ios::out|ios::in|ios::trunc);
    if (File.is_open()==true)
    {
        IsOpen=true;
    }
}
void DbExport::ExportToCsv(DB &B)
{
    if(IsOpen==true)
    {
        for(int z=0; z<B.GetMaxX(); z++)
        {
            for(int i=0; i<B.GetMaxY(); i++)
            {
                File<<"\""<<B.GetEntryById(z,i);
                if(B.GetMaxY()!=i)
                {
                    File<<"\",";
                }
                else
                {
                    File<<"\"";
                }
            }
            File<<endl;
        }
        File.close();

    }
}
