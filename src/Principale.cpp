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

void Principale::GetTop10 ( pair<int,string> p)
// Algorithme :
//
{
	Top10::iterator debut;
	debut=top10.begin();
	if (top10.size()<10)
	{ 
		top10.insert(p);
	}
	else 
	{
		if (debut->first < p.first)
		{
			top10.erase(debut);
			top10.insert(p);
		}
	}
} //----- Fin de GetTop10

void Principale::Afficher (  ) 
// Algorithme :
//
{
	MapCibles::iterator debut,fin;
	debut=infos.begin();
	fin=infos.end();
	while(debut!=fin)
	{
		string cible=debut->first;
		int count=debut->second.first;
		GetTop10(make_pair(count,cible));
		debut++;
	}
	Top10::reverse_iterator debutTop,finTop;
	debutTop=top10.rbegin();
	finTop=top10.rend();
	while(debutTop!=finTop)
	{
		cout<<debutTop->second<<" "<<debutTop->first<<endl;
		debutTop++;
	}

} //----- Fin de Afficher

void Principale::CreateGraph(const string file) const
// Algorithme :
//
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

void Principale::AjouterLog (const Log &  l )
// Algorithme :
//
{
	string cible=l.GetCible();
	int index=cible.find_first_of('?');
	cible=cible.substr(0,index);
	
	string referer=l.GetReferer();
	if (referer.substr(0,31)=="http://intranet-if.insa-lyon.fr")
	{
		referer=referer.substr(31,string::npos);
	}else if (referer!="-")
	{
		index=referer.find_first_of('/',7);
		referer=referer.substr(0,index);
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

