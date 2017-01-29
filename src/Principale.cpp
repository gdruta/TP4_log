/*************************************************************************
 Principale  -  description
 -------------------
 début                : 16 janv. 2017
 copyright            : (C) 2017 par  gdruta & epetit
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

void Principale::InsertTop ( pair<int,string> p)
// Algorithme :
{
	Top::iterator debut;
	debut=top.begin();
	if (top.size()<MAX_IN_TOP)
	{ 
		top.insert(p);
	}
	else 
	{
		if (debut->first < p.first)
		{
			top.erase(debut);
			top.insert(p);
		}
	}
} //----- Fin de InsertTop

void Principale::CreateTop()
{
	MapCibles::iterator debut,fin;
	debut=infos.begin();
	fin=infos.end();
	while(debut!=fin)
	{
		string cible=debut->first;
		int count=debut->second.first;
		InsertTop(make_pair(count,cible));
		debut++;
	}
}//----- Fin de CreateTop

void Principale::AfficherTop (  ) const
// Algorithme :
{	
	Top::const_reverse_iterator debutTop,finTop;
	debutTop=top.rbegin();
	finTop=top.rend();
	while(debutTop!=finTop)
	{
		cout<<debutTop->second<<" ("<<debutTop->first<<" hits)"<<endl;
		debutTop++;
	}
} //----- Fin de AfficherTop

void Principale::CreateGraph(const string file) const
// Algorithme :
{
	ofstream os(file);
	if (os.good())
	{
		cout<<"dot-file "<<file<<" generated"<<endl;
		os<<"digraph {"<<endl;
		MapResources::const_iterator debut,fin;
		debut=resources.begin();
		fin=resources.end();
		while(debut!=fin)
		{
			os<<"node"<<debut->second<<" [label=\""<<debut->first<<"\"];"<<endl;
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
				os<<"node"<<resources.at(debutReferer->first)<<" -> node"<<resources.at(debutCible->first)<<" [label=\"";
				os<<debutReferer->second<<"\"];"<<endl;
				debutReferer++;
			}
			debutCible++;			
		}
		os<<"}"<<endl;
	}
	else
	{
		
	}
	os.close();
}

void Principale::AjouterLog (const Log &  l )
// Algorithme :
{
	// trouver la cible en format simple
	string cible=l.GetCible();
	int index=cible.find_first_of('?');
	cible=cible.substr(0,index);
	index=cible.find_first_of(';');
	cible=cible.substr(0,index);
	
	string referer=l.GetReferer();
	if (referer.substr(0,31)==DOMAIN_NAME)
	{
		referer=referer.substr(31,string::npos);
	}else if (referer!="-")
	{
		index=referer.find_first_of('/',7);
		referer=referer.substr(0,index);
	}

	resources.insert(make_pair(cible,resources.size()+1));
	resources.insert(make_pair(referer,resources.size()+1));

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
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Principale>" << endl;
#endif
} //----- Fin de Principale (constructeur de copie)

Principale::Principale()
// Algorithme :
{
#ifdef MAP
	cout << "Appel au constructeur de <Principale>" << endl;
#endif
} //----- Fin de Principale

Principale::~Principale()
// Algorithme :
{
#ifdef MAP
	cout << "Appel au destructeur de <Principale>" << endl;
#endif
} //----- Fin de ~Principale

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

