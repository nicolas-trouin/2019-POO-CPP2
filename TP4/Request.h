/*************************************************************************
                           Request  -  description
                             -------------------
    début                : 15/01/2020
    copyright            : (C) 2020 par Nicolas TROUIN & Ghali ElAlaoui ElAbdellaoui
    e-mail               : nicolas.trouin@insa-lyon.fr & ghali.el-allaoui-el-abdellaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Request> (fichier Request.h) ----------------
#if ! defined ( REQUEST_H )
#define REQUEST_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>

#include "Catalog.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Request>
//
//
//------------------------------------------------------------------------

class Request
{
//----------------------------------------------------------------- PUBLIC

    friend class Catalog;

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void FixReferer();
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void FixTarget();
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    //Contrat :
    //

    std::string GetExtension();
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    //Contrat :
    //

    int GetHour();
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    //Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    //Request & operator = ( const Request & unRequest );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend std::istream & operator >> (std::istream & in, Request & request);
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend std::ostream & operator << (std::ostream & out, const Request & request);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Request (const Request & req );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Request ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Request ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    std::string ipAdress;
    std::string userLogName;
    std::string authenticatedUser;
    std::string date;
    std::string time;
    std::string timeZone;
    std::string httpMethod;
    std::string target;
    std::string protocol;
    unsigned returnCode;
    unsigned data;
    std::string referer;
    std::string userAgent;
};

//-------------------------------- Autres définitions dépendantes de <Request>

#endif // REQUEST_H

