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
	 string size;
	 string referer;
	 string client;

	 std::getline(*this,ip,' ');
	 std::getline(*this,userLogName,' ');
	 std::getline(*this,userName,' ');
	 std::getline(*this,rawdate,']');

	 string temp; //variable pour le caracteres inutile
	 std::getline(*this,temp,' ');
	 
	 std::getline(*this,method,' ');
	 method=method.substr(1,method.size()-1);

	 std::getline(*this,resource,' ');
	 // Find extension of resource
	 int index=resource.find_first_of('?');
	 string extension=resource.substr(0,index);
	 
	 index=extension.find_first_of('.');
	 if (index==string::npos)
	 {
		 extension="";
	 }
	 else
	 {
	 	extension=extension.substr(index,string::npos);
	 }



	 std::getline(*this,version,'"');

	 std::getline(*this,temp,' ');
	 std::getline(*this,rawcode,' ');
	 std::getline(*this,size,' ');
	 std::getline(*this,referer,' ');
	 referer=referer.substr(1,referer.size()-2);
	 std::getline(*this,temp,'"');
	 std::getline(*this,client);
	 client=client.substr(1,client.size()-2);
	 
	 // creation structure timestamp(date,heure)
	 struct TimeStamp date;
	 date.date=rawdate.substr(1,11);
	 date.hour=stoi(rawdate.substr(13,2));
	 date.min=stoi(rawdate.substr(16,2));
	 date.sec=stoi(rawdate.substr(19,2));
	 date.GMT=stoi(rawdate.substr(23,4));

	 // creation structure Request
	 struct Request request(method,resource,extension,version);

	 //code to int
	 code=stoi(rawcode,nullptr);
 
	 return Log(ip,userLogName,userName,date,request,code,size,referer,client);



} //----- Fin de NextLine

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
LogStream::LogStream(const LogStream & unLogStream)
// Algorithme :
//
		{
#ifdef MAP
	cout << "Appel au constructeur de copie de <LogStream>" << endl;
#endif
} //----- Fin de LogStream (constructeur de copie)

LogStream::LogStream(string nomfichier):
		ifstream(nomfichier.c_str())
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

