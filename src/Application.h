/*************************************************************************
 Application  -  description
 -------------------
 début                : 16 janv. 2017
 copyright            : (C) 2017 par gdruta & epetit
 *************************************************************************/

//---------- Interface de la classe <Application> (fichier Application.h) ------
#if ! defined ( APPLICATION_H_ )
#define APPLICATION_H_

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include "Principale.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Application>
// Executer l'application en dependance des options fournies
// 
//------------------------------------------------------------------------ 

class Application {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void  ReadArguments(int argc,char * argv[]);
    //methode qui lit les arguments et qui execute les 
    //methode fournit par les classes LogStream et Principale
    //Mode d'emploi :
    //argc : size of argv
    //argv : tableaux avec arguments

    
	
//------------------------------------------------- Surcharge d'opérateurs
	Application & operator =(const Application & unApplication);
	// Mode d'emploi :
	// Contrat :

//-------------------------------------------- Constructeurs - destructeur
	Application(const Application & unApplication);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Application();
	// constructeur de la clase	
    // Mode d'emploi :
	// Contrat :
	//

	virtual ~Application();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
    bool verifyExtension(const string ext);
    // verifie si l'extension est image,css ou js
    // Mode d'emploi :
    // ext extension à verifir

    char* getCmdOption(char ** begin, char ** end, const std::string & option);
    // retourne le parapetre d'une option

    bool cmdOptionExists(char** begin, char** end, const std::string& option);
    // verifie si une option est demandée par l'utilisateur

//----------------------------------------------------- Attributs protégés
    // bool pour les 3 options du  programme
    bool e;
    bool t;
    bool g;
    string fileLog;
    string fileDot;
    int hour=0;
    Principale pr; 
};

//--------------------------- Autres définitions dépendantes de <Application>

#endif // Applicatiob_H_

