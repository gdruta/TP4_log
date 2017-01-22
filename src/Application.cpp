using namespace std;
#include "LogStream.h"
#include "Principale.h"
#include <string>
#include <algorithm>
#include <iostream>

char* getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

int main(int argc,char * argv[]){
    bool e=false;
    bool t=false;
    bool g=false;
    string fileLog;
    string fileDot;
    int hour=0;
    Principale pr;
    if(cmdOptionExists(argv, argv+argc-1, "-e"))
    {
        e=true;
    }

    if(cmdOptionExists(argv, argv+argc-1, "-t"))
    {
        t=true;
        string rawhour=getCmdOption(argv, argv + argc-1, "-t");
        hour=stoi(rawhour,nullptr);
    }

    if(cmdOptionExists(argv, argv+argc-1, "-g"))
    {
        g=true;        
        fileDot = getCmdOption(argv, argv + argc, "-g");
    }

    fileLog=argv[argc-1];


    LogStream ls(fileLog);
    if (!ls.good())
    {
        cout<<"fichier introuvable"<<endl;
    }else if (ls.peek()==EOF)
    {
        cout<<"fichier vide"<<endl;
    }else 
    {
        
        while (ls.peek()!=EOF)
        {
            cout<<ls.peek()<<endl;
            Log l=ls.NextLine();
            if (!( ((e)&&((l.GetExtension()==".png")||(l.GetExtension()==".jpg")||(l.GetExtension()==".bmp")))||
                   ((t)&&(l.GetHour()!=hour)) ))
            {
                
                pr.AjouterLog(l);
            }            
        }        
    }
    if (g) 
    {
        pr.CreateGraph(fileDot);
    }
    pr.Afficher();
    
}