//
// Created by yaon on 12/10/22.
//

#ifndef PROJET_CDAA_GESTIONCONTACT_H
#define PROJET_CDAA_GESTIONCONTACT_H

#include <ostream>
#include "../Contact/Contact.h"

using namespace std;

class GestionContact {
private:
    list<Contact> listeContacts;
    list<string> historiqueModifs;

    void logModif(string contenu);

public:
    void addContact(Contact &c);

    void removeContact(Contact &c);

    void modifContact(Contact &c);

    int getNbContacts();

    list<Contact *> getContact(string name);

    string getHistoriqueModifs();

    friend ostream &operator<<(ostream &os, const GestionContact &contact);
};


#endif //PROJET_CDAA_GESTIONCONTACT_H
