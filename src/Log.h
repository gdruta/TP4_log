/*************************************************************************
 Log  -  description
 -------------------
 début                : 9 janv. 2017
 copyright            : (C) 2017 par gdruta
 *************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ------
#if ! defined ( LOG_H_ )
#define LOG_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <time.h>
using namespace std
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
struct Request{
	string method;
	string cible;
	string extension;
	string version;
	Request(string m="",string c="",string e="",string v=""):
		method(m),cible(c),extension(e),version(v){}
};
//------------------------------------------------------------------------ 
// Rôle de la classe <Log>
//
//
//------------------------------------------------------------------------ 

class Log {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
	Log & operator =(const Log & unLog);
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Log(const Log & unLog);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Log(string i,string uLN,string uN,struct tm d,struct Request r,int cd,int s,string ref,string c);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Log();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string ip;
string userLogName;
string userName;
struct tm date;
struct Request request;
int code;
int size;
string referer;
string client;

};

//--------------------------- Autres définitions dépendantes de <Log>

#endif // LOG_H_

