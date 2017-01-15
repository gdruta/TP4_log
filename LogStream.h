/*************************************************************************
 LogStream  -  description
 -------------------
 début                : 9 janv. 2017
 copyright            : (C) 2017 par epetit
 *************************************************************************/

//---------- Interface de la classe <LogStream> (fichier LogStream.h) ------
#if ! defined ( LOGSTREAM_H_ )
#define LOGSTREAM_H_

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include "Log.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <LogStream>
//
//
//------------------------------------------------------------------------ 

class LogStream:public ifstream{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Log NextLine ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
	LogStream & operator =(const LogStream & unLogStream);
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	LogStream(const LogStream & unLogStream);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	LogStream(bool e1,bool t1,int h,string nomfichier);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~LogStream();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
bool e;
bool t;
int heure;
};

//--------------------------- Autres définitions dépendantes de <LogStream>

#endif // LOGSTREAM_H_

