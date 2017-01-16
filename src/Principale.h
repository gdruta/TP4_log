/*************************************************************************
 Principale  -  description
 -------------------
 début                : 16 janv. 2017
 copyright            : (C) 2017 par epetit
 *************************************************************************/

//---------- Interface de la classe <Principale> (fichier Principale.h) ------
#if ! defined ( PRINCIPALE_H_ )
#define PRINCIPALE_H_

//--------------------------------------------------- Interfaces utilisées
# include "Log.h"
# include <utility>
# include <map>
using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef map<string,int> MapReferers;
typedef map<string,pair<int,MapReferers>> MapCibles;
//------------------------------------------------------------------------ 
// Rôle de la classe <Principale>
//
//
//------------------------------------------------------------------------ 

class Principale {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	void Afficher ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void AjouterLog ( Log  l);
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
	Principale & operator =(const Principale & unPrincipale);
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Principale(const Principale & unPrincipale);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Principale();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Principale();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
MapCibles infos;
};

//--------------------------- Autres définitions dépendantes de <Principale>

#endif // PRINCIPALE_H_

