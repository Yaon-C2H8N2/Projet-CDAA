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
    list<string> historiqueModifs;
    list<Contact> listeContacts;

    void logModif(string contenu);

public:
    void addContact(Contact c);

    void removeContact(Contact c);

    void modifyContact(Contact c);

    int getNbContacts();

    Contact getContact(int i);

    string getHistoriqueModifs();

    friend ostream &operator<<(ostream &os, const GestionContact &contact);
};


#endif //PROJET_CDAA_GESTIONCONTACT_H
