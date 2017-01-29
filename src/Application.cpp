/*************************************************************************
 Application  -  description
 -------------------
 début                : 16 janv. 2017
 copyright            : (C) 2017 par  gdruta & epetit
 *************************************************************************/

//---------- Réalisation de la classe <Application> (fichier Application.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "Application.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void  Application::ReadArguments(int argc,char * argv[])
{
    //Variables utilisées    
    bool executionPossible=true;

    // Verification si nombre des arguments suffisent
    if (argc<2)
    {
        cerr<<"ERROR : not enough arguments"<< endl;
    }
    else
    {
        // Verification si option -e presente
        if(cmdOptionExists(argv, argv+argc-1, "-e"))
        {
            e=true;
        }

        // Verification si option -t presente
        if(cmdOptionExists(argv, argv+argc-1, "-t"))
        {
            char * rawhour=getCmdOption(argv, argv + argc-1, "-t");
            try
            {
                hour=stoi(string(rawhour),nullptr);
            }
            catch (const exception & e)
            {
                cerr<< "ERROR : hour not specified"<< endl;
                executionPossible=false;
            }
            if ((hour>=0)&&(hour<=24))
            {
                t=true;
            }
            else
            {
                cerr<<"ERROR : no valid hour argument"<<endl;
                executionPossible=false;
            }
        }

        // Verification si -g presente
        if(cmdOptionExists(argv, argv+argc-1, "-g"))
        {                   
            char * arg = getCmdOption(argv, argv + argc-1, "-g");
            if (arg!=0)
            {
                string file=arg;
                if ((file.compare("-t")==0)||(file.compare("-g")==0)||(file.compare("-e")==0))
                {
                    cerr<<"ERROR : no .dot file provided"<<endl; 
                    executionPossible=false;
                }else
                {
                    int index=file.find(".dot");
                    if (index==string::npos)
                    {
                    cerr<<"ERROR : file provided for graph does not have a .dot extension"<<endl; 
                    executionPossible=false;
                    }
                    else
                    {
                    g=true;
                    fileDot=file;

                }
                }
                
            }
            else 
            {
                cerr<<"ERROR : no .dot file provided"<<endl; 
                executionPossible=false;
            }
        }

        fileLog=argv[argc-1];

        // Verification de file .log
        int index=fileLog.find(".log");
        if (index==string::npos)
        {
            cerr<<"ERROR : the file provided does not have a .log extension"<<endl; 
            executionPossible=false;
        }
        if (executionPossible)
        {
            LogStream ls(fileLog);
            if (!ls.good())
            {
                cerr<<"ERROR : fichier .log introuvable"<<endl;
            }else if (ls.peek()==EOF)
            {
                cerr<<"ERROR : fichier .log vide"<<endl;
            }else 
            {            
                int logCounter=0;
                while (ls.peek()!=EOF)
                {
                    Log l=ls.NextLine();
                    if (  ( (e) && (verifyExtension(l.GetExtension()) ) ) ||
                        ((t)&&(l.GetHour()!=hour)) )
                    {}
                    else
                    {                
                        pr.AjouterLog(l);
                        logCounter++;
                    }            
                } 
                if (logCounter!=0)
                {
                    if (g) 
                    {
                        pr.CreateGraph(fileDot);
                    }
                    pr.CreateTop();
                    pr.AfficherTop();       
                }
                else
                {
                    cout<<"rien a afficher"<<endl;
                }
                
            }
        }


        
    }       
    
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Application::Application(const Application & unApplication)
// Algorithme :
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Application>" << endl;
#endif
} //----- Fin de Application (constructeur de copie)

Application::Application()
// Algorithme :
{
    e=false;
    t=false;
    g=false;
#ifdef MAP
	cout << "Appel au constructeur de <Application>" << endl;
#endif
} //----- Fin de Application

Application::~Application()
// Algorithme :
{
#ifdef MAP
	cout << "Appel au destructeur de <Application>" << endl;
#endif
} //----- Fin de ~Application

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
char*  Application::getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool Application::cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

bool Application::verifyExtension(string ext)
{
    return (ext==".png")||(ext==".gif")||(ext==".ico")||(ext==".jpg")||(ext==".bmp")||(ext==".css")||(ext==".js")||(ext==".jpeg");
}
