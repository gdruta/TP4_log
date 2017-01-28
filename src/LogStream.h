/*************************************************************************
 LogStream  -  description
 -------------------
 début                : 9 janv. 2017
 copyright            : (C) 2017 par gdruta
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
// classe qui herite de ifstream
// utilise pour ouvrir le fichier .log et lire dessus 
//------------------------------------------------------------------------ 

class LogStream:public ifstream{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	Log  NextLine ( );
	// Permet de lire une ligne d'un fichier .log et retourne un Log créé a partir du log apache
	// Mode d'emploi :
	// Contrat : pas

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

	LogStream(string nomfichier="");
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
};

//--------------------------- Autres définitions dépendantes de <LogStream>

#endif // LOGSTREAM_H_

