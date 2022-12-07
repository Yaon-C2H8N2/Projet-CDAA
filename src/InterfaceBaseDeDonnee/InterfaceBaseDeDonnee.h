//
// Created by yaon on 06/12/22.
//

#ifndef PROJET_CDAA_INTERFACEBASEDEDONNEE_H
#define PROJET_CDAA_INTERFACEBASEDEDONNEE_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDateTime>
#include "../Contact/Contact.h"
#include "../GestionContact/GestionContact.h"
#include "../GestionTache/GestionTache.h"


class InterfaceBaseDeDonnee {
private:
    QSqlDatabase db;

public:
    InterfaceBaseDeDonnee();

    void getContacts(GestionContact *gestionContact);

    void getInteractions(GestionContact *gestionContact);

    void getTaches(GestionTache *gestionTache, GestionContact *gestionContact);

    void updateContact(Contact old_contact, Contact new_contact);

    void writeInteractions(GestionContact *gestionContact);

    void writeTaches(GestionTache *gestionTache);
};


#endif //PROJET_CDAA_INTERFACEBASEDEDONNEE_H
