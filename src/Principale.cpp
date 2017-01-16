/*************************************************************************
 Principale  -  description
 -------------------
 début                : 16 janv. 2017
 copyright            : (C) 2017 par epetit
 *************************************************************************/

//---------- Réalisation de la classe <Principale> (fichier Principale.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Principale.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Principale::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Principale::Afficher (  )
// Algorithme :
//
{
	MapCibles::iterator debut,fin;
	debut=infos.begin();
	fin=infos.end();
	while(debut!=fin)
	{
		cout<<debut->first<<" "<<debut->second.first<<endl;
		debut++;
	}
} //----- Fin de Afficher

void Principale::AjouterLog ( Log  l )
// Algorithme :
//
{
	string cible=l.GetCible();
	if (cible.substr(0,31)=="http://intranet-if.insa-lyon.fr")
	{
		cible=cible.substr(32,string::npos);
	}
	string referer=l.GetReferer();
	MapReferers referers;
	referers.insert(make_pair(referer,1));
	pair<MapCibles::iterator,bool> ret= infos.insert(make_pair(cible,make_pair(1,referers)));
	if (!ret.second)
	{
		ret.first->second.first++;
		pair<MapReferers::iterator,bool> ret2=ret.first->second.second.insert(make_pair(referer,1));
		if (!ret2.second)
		{
			ret2.first->second++;
		}
	}
} //----- Fin de AjouterLog

//------------------------------------------------- Surcharge d'opérateurs
Principale & Principale::operator =(const Principale & unPrincipale)
// Algorithme :
//
		{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Principale::Principale(const Principale & unPrincipale)
// Algorithme :
//
		{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Principale>" << endl;
#endif
} //----- Fin de Principale (constructeur de copie)

Principale::Principale()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Principale>" << endl;
#endif
} //----- Fin de Principale

Principale::~Principale()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Principale>" << endl;
#endif
} //----- Fin de ~Principale

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

