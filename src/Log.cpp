/*************************************************************************
 Log  -  description
 -------------------
 début                : 9 janv. 2017
 copyright            : (C) 2017 par gdruta
 *************************************************************************/

//---------- Réalisation de la classe <Log> (fichier Log.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Log.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Log::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Log::GetCible (  ) const
// Algorithme :
//
{
	return request.cible;
} //----- Fin de GetCible

string Log::GetReferer (  ) const
// Algorithme :
//
{
	return referer;
} //----- Fin de GetReferer

string Log::GetExtension (  ) const
// Algorithme :
//
{
	return request.extension;
} //----- Fin de GetReferer

int Log::GetHour (  ) const
// Algorithme :
//
{
	return date.hour;
} //----- Fin de GetReferer


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Log::Log(const Log & unLog)
// Algorithme :
//
		{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Log>" << endl;
#endif
} //----- Fin de Log (constructeur de copie)

Log::Log(string i,string uLN,string uN,struct TimeStamp d,struct Request r,int cd,string s,string ref,string c):
		ip(i), userLogName(uLN), userName(uN), date(d), request(r), code(cd), size(s), referer(ref), client(c)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Log>" << endl;
#endif
} //----- Fin de Log

Log::~Log()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Log>" << endl;
#endif
} //----- Fin de ~Log

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

