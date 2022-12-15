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

    void modifyContact(Contact c1, Contact c2);

    int getNbContacts();

    Contact getContact(int i);

    string getHistoriqueModifs();

    GestionContact *rechercheNom(string name);

    GestionContact *rechercheEntreprise(string entreprise);

    GestionContact *rechercheDateCreation(tm date);

    GestionContact *rechercheIntervalleDate(tm date_debut, tm date_fin);

    friend ostream &operator<<(ostream &os, const GestionContact &contact);
};


#endif //PROJET_CDAA_GESTIONCONTACT_H
