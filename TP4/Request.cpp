/*************************************************************************
                           Request  -  description
                             -------------------
    début                : 15/01/2020
    copyright            : (C) 2020 par Nicolas TROUIN & Ghali ElAlaoui ElAbdellaoui
    e-mail               : nicolas.trouin@insa-lyon.fr & ghali.el-allaoui-el-abdellaoui@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Request> (fichier Request.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Request.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Request::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*
Request & Request::operator = ( const Request & unRequest )
// Algorithme :
//
{
} //----- Fin de operator =
*/

istream & operator >>(istream & in, Request & request)
{
    string buffer;

    std::getline(in, request.ipAdress, ' ');
    std::getline(in, request.userLogName, ' ');
    std::getline(in, request.authenticatedUser, ' ');
    std::getline(in, buffer, '[');
    std::getline(in, request.date, ':');
    std::getline(in, request.time, ' ');
    std::getline(in, request.timeZone, ']');
    std::getline(in, buffer, '"');
    std::getline(in, request.httpMethod, ' ');
    std::getline(in, request.target, ' ');
    std::getline(in, request.protocol, '"');
    std::getline(in, buffer, ' ');
    in >> request.returnCode;
    getline(in, buffer, ' ');
    std::getline(in, buffer, '"');
    if(buffer[0] != '-')
    {
        request.data = atoi(buffer.c_str());
    }else
    {
        request.data = '-';
    }
    std::getline(in, request.referer, '"');
    std::getline(in, buffer, '"');
    std::getline(in, request.userAgent, '"');

    return in;
}

void Request::FixTarget()
{
    size_t found = target.find_last_of('?');
    target = target.substr(0, found);
    target.insert(0, "https://intranet-if.insa-lyon.fr");
}

void Request::FixReferer()
{
    size_t found = referer.find_last_of('?');
    referer = referer.substr(0, found);
}

string Request::GetExtension()
{
    size_t pos = target.find_last_of('.');
    return target.substr(pos);
}

int Request::GetHour()
{
    return atoi(time.substr(0, 2).c_str());
}

ostream & operator << (ostream & out, const Request & request)
{
    out << "FOR TESTING PURPOSE ONLY" << endl;
    out << request.ipAdress << " ; " << request.userLogName << " ; " << request.authenticatedUser << " ; " << request.date << " ; " << request.time << " ; " << request.timeZone << " ; " << request.httpMethod << " ; " << request.target << " ; " << request.protocol << " ; " << request.returnCode << " ; " << request.data << " ; " << request.referer << " ; " << request.userAgent;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur

Request::Request ( const Request & req )
    :ipAdress(req.ipAdress), userLogName(req.userLogName), authenticatedUser(req.authenticatedUser),
      date(req.date), time(req.time), timeZone(req.timeZone), httpMethod(req.httpMethod),
      target(req.target), protocol(req.protocol), returnCode(req.returnCode), data(req.data),
      referer(req.referer), userAgent(req.userAgent)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Request>" << endl;
#endif
} //----- Fin de Request (constructeur de copie)


Request::Request ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Request>" << endl;
#endif
} //----- Fin de Request


Request::~Request ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Request>" << endl;
#endif
} //----- Fin de ~Request


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
