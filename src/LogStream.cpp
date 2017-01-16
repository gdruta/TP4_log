/*************************************************************************
 LogStream  -  description
 -------------------
 début                : 9 janv. 2017
 copyright            : (C) 2017 par gdruta
 *************************************************************************/

//---------- Réalisation de la classe <LogStream> (fichier LogStream.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogStream.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogStream::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

 Log LogStream::NextLine ( )
// Algorithme :
//
{
	 string ip;
	 string userLogName;
	 string userName;
	 string rawdate;
	 string gmt;
	 string method;
	 string resource;
	 string version;
	 struct tm date;
	 struct Request request;
	 int code;
	 int size;
	 string referer;
	 string client;

	 std::getline(*this,ip,' ');
	 std::getline(*this,userLogName,' ');
	 std::getline(*this,userName,' ');
	 std::getline(*this,rawdate,' ');
	 std::getline(*this,gmt,' ');
	 std::getline(*this,method,' ');
	 std::getline(*this,resource,' ');
	 std::getline(*this,version,' ');

} //----- Fin de NextLine

//------------------------------------------------- Surcharge d'opérateurs
LogStream & LogStream::operator =(const LogStream & unLogStream)
// Algorithme :
//
		{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
LogStream::LogStream(const LogStream & unLogStream)
// Algorithme :
//
		{
#ifdef MAP
	cout << "Appel au constructeur de copie de <LogStream>" << endl;
#endif
} //----- Fin de LogStream (constructeur de copie)

LogStream::LogStream(bool e1=false,bool t1=false,int h=0,string nomfichier=""):
		e(e1),t(t1),heure(h),ifstream(nomfichier.c_str())
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <LogStream>" << endl;
#endif
} //----- Fin de LogStream

LogStream::~LogStream()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <LogStream>" << endl;
#endif
} //----- Fin de ~LogStream

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

