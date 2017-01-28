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
# include <unordered_set>
using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef map<string,int> MapReferers;
typedef map<string,pair<int,MapReferers>> MapCibles;
typedef unordered_set<string> SetResources;
typedef multimap <int,string> Top10;
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
	void InsertTop10 (pair<int,string> p);
	// Verifie si une resource est valable pour le top10 et 
	// permet de l'inserer dans la multimap de top10
	// Mode d'emploi :
	// pair p: int nombre des acces a la resources
	// pair p: string nom de la resource
	// Contrat : pas

	void Afficher () ;
	// Permet d'afficher le top 10 de resources
	// Mode d'emploi :
	//
	// Contrat : pas

	void AjouterLog (const Log &  l);
	// Permet d'ajouter la cible et le refereur a la structure de donnee
	// Mode d'emploi :
	// l: Log lu et traité d'un fichier .log
	// Contrat : pas

	void CreateGraph(const string s) const;
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
SetResources resources;
Top10 top10;
};

//--------------------------- Autres définitions dépendantes de <Principale>

#endif // PRINCIPALE_H_

