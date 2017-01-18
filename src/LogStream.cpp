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

 Log  LogStream::NextLine ( )
// Algorithme :
//
{
	 string ip;
	 string userLogName;
	 string userName;
	 string rawdate;
	 string method;
	 string resource;
	 string version;
	 string rawcode;
	 string rawsize;
	 
	 int code;
	 int size;
	 string referer;
	 string client;

	 std::getline(*this,ip,' ');
	 std::getline(*this,userLogName,' ');
	 std::getline(*this,userName,' ');
	 std::getline(*this,rawdate,']');
	 string temp;
	 std::getline(*this,temp,' ');
	 std::getline(*this,method,' ');
	 method=method.substr(1,method.size()-1);
	 std::getline(*this,resource,' ');
	 std::getline(*this,version,' ');
	 version=version.substr(0,version.size()-1);
	 std::getline(*this,rawcode,' ');
	 std::getline(*this,rawsize,' ');
	 std::getline(*this,referer,' ');
	 referer=referer.substr(1,referer.size()-2);
	 std::getline(*this,temp,'"');
	 std::getline(*this,client,'"');
	 client=client.substr(1,client.size()-1);
	 
	 struct TimeStamp date;
	 date.date=rawdate.substr(1,11);
	 date.hour=stoi(rawdate.substr(14,2));
	 date.min=stoi(rawdate.substr(17,2));
	 date.sec=stoi(rawdate.substr(20,2));
	 date.GMT=stoi(rawdate.substr(24,4));
	 struct Request request(method,resource,version);
	 code=stoi(rawcode,nullptr);
	 size=stoi(rawsize,nullptr);

	 return Log(ip,userLogName,userName,date,request,code,size,referer,client);



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

