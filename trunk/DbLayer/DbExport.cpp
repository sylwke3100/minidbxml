#include "DbExport.h"

DbExport::DbExport(string FileName)
{
    Path = FileName;
    File.open(Path.c_str(),ios::out|ios::in|ios::trunc);
    if (File.is_open()==true)
        IsOpen=true;
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
                    File<<"\",";
                else
                    File<<"\"\n";
            }
        }
        File.close();
    }
}
void DbExport::ExportToHTML(DB &B,string Title)
{
    if(IsOpen==true)
    {
        File<<"<html>\n<head>\n<title>"<<Title<<"</title></head>\n<body>\n<table>\n";
        for(int z=0; z<B.GetMaxX(); z++)
        {
            File<<"<tr>";
            if(z==0)
                File<<"<td>*  </td>\n";
            else
                File<<"<td>"<<z<<"</td>\n";
            for(int i=0; i<B.GetMaxY(); i++)
            {
                if(z==0)
                    File<<"<th>"<<B.GetEntryById(z,i)<<"</th>\n";
                else
                    File<<"<td>"<<B.GetEntryById(z,i)<<"</td>\n";
            }
            File<<"</tr>\n";
        }
        File<<"</table><body>\n</html>";
        File.close();
    }
}
