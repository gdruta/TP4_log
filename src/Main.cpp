using namespace std;
#include "LogStream.h"
#include "Principale.h"
#include <string>
#include <algorithm>
#include <iostream>

static char* getCmdOption(char ** begin, char ** end, const std::string & option)
// retourne le parapetre d'une option
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

static bool cmdOptionExists(char** begin, char** end, const std::string& option)
// verifie si une option est demandée par l'utilisateur
{
    return std::find(begin, end, option) != end;
}

static void  ReadArguments(int argc,char * argv[])
{
    //Variables utilisées
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
        char * rawhour=getCmdOption(argv, argv + argc-1, "-t");
        try
        {
            hour=stoi(string(rawhour),nullptr);
        }
        catch (const exception & e)
        {
            cerr<< "ERROR : hour not specified, running without -t option"<< endl;
        }
        if ((hour>=0)&&(hour<=24))
        {
            t=true;
        }
        else
        {
            cerr<<"ERROR : no valid hour argument, running without -t option"<<endl;
        }
    }

    if(cmdOptionExists(argv, argv+argc-1, "-g"))
    {        
        char * arg = getCmdOption(argv, argv + argc-1, "-g");
        if (arg!=0)
        {
            string file=arg;
            unsigned int index=file.find(".dot");
            if (index==string::npos)
            {
                cerr<<"ERROR : file does not have a .dot extension"<<endl; 
            }
            else
            {
                g=true;
                fileDot=file;
            }
        }
        else 
        {
            cerr<<"ERROR : no .dot file provided"<<endl; 
        }
    }

    fileLog=argv[argc-1];


    LogStream ls(fileLog);
    if (!ls.good())
    {
        cerr<<"ERROR : fichier introuvable"<<endl;
    }else if (ls.peek()==EOF)
    {
        cerr<<"ERROR : fichier vide"<<endl;
    }else 
    {
        
        while (ls.peek()!=EOF)
        {
            Log l=ls.NextLine();
            if (( ((e)&&((l.GetExtension()==".png")||(l.GetExtension()==".jpg")||(l.GetExtension()==".bmp")||(l.GetExtension()==".css")))||
                   ((t)&&(l.GetHour()!=hour)) ))
            {}
            else
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

int main(int argc,char * argv[])
{
    ReadArguments(argc,argv);
}
