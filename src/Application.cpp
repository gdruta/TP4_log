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
    if(cmdOptionExists(argv, argv+argc, "-e"))
    {
        e=true;
    }

    if(cmdOptionExists(argv, argv+argc, "-t"))
    {
        t=true;
        string rawhour=getCmdOption(argv, argv + argc, "-t");
        hour=stoi(rawhour,nullptr);
    }

    if(cmdOptionExists(argv, argv+argc, "-g"))
    {
        g=true;
        fileDot = getCmdOption(argv, argv + argc, "-g");
    }

    fileLog=argv[argc-1];


    LogStream ls(e,t,hour,fileLog);
    if (ls.good())
    {
        for (int i=0;i<5;i++)
        {
            pr.AjouterLog(ls.NextLine());
        }        
    }
    if (g) 
    {
        pr.CreateGraph(fileDot);
    }
    pr.Afficher();
    
}