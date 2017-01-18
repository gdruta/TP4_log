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
#include <fstream>

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

void Principale::CreateGraph(const string file) const
{
	ofstream os(file);
	if (os.good())
	{
		os<<"digraph {"<<endl;
		SetResources::const_iterator debut,fin;
		debut=resources.begin();
		fin=resources.end();
		while(debut!=fin)
		{
			os<<"node"<<resources.bucket(*debut)<<" [label=\""<<*debut<<"\"];"<<endl;
			debut++;
		}
		MapCibles::const_iterator debutCible,finCilbe;
		debutCible=infos.begin();
		finCilbe=infos.end();
		MapReferers::const_iterator debutReferer,finReferer;
		while(debutCible!=finCilbe)
		{
			debutReferer=debutCible->second.second.begin();
			finReferer=debutCible->second.second.end();
			while(debutReferer!=finReferer)
			{
				os<<"node"<<resources.bucket(debutCible->first)<<" -> node"<<resources.bucket(debutReferer->first)<<" [label=\"";
				os<<debutReferer->second<<"\"];"<<endl;
				debutReferer++;
			}
			debutCible++;			
		}
		os<<"}"<<endl;
	}
	os.close();
}

void Principale::AjouterLog ( Log  l )
// Algorithme :
//
{
	string cible=l.GetCible();
	
	string referer=l.GetReferer();
	if (referer.substr(0,31)=="http://intranet-if.insa-lyon.fr")
	{
		referer=referer.substr(31,string::npos);
	}

	resources.insert(cible);
	resources.insert(referer);

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

