//
// Created by yaon on 15/12/22.
//

#ifndef PROJET_CDAA_INTERFACEJSON_H
#define PROJET_CDAA_INTERFACEJSON_H


#include <QString>
#include "../GestionContact/GestionContact.h"
#include "../InterfaceBaseDeDonnee/InterfaceBaseDeDonnee.h"

class InterfaceJSON {
public:
    void exportInJson(GestionContact *gestionContact, QString path);

    void importFromJson(GestionContact *gestionContact, QString path, InterfaceBaseDeDonnee *interfaceBaseDeDonnee);
};


#endif //PROJET_CDAA_INTERFACEJSON_H
