//
// Created by yaon on 12/10/22.
//

#ifndef PROJET_CDAA_GESTIONCONTACT_H
#define PROJET_CDAA_GESTIONCONTACT_H

#include "../Contact/Contact.h"

using namespace std;

class GestionContact {
private:
    list<Contact> listeContacts;
    list<string> historiqueModifs;
public:
    void addContact(Contact c);

    void removeContact(Contact c);

    string getHistoriqueModifs();
};


#endif //PROJET_CDAA_GESTIONCONTACT_H
