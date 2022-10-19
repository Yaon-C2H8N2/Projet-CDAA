//
// Created by yaon on 12/10/22.
//

#ifndef PROJET_CDAA_INTERACTION_H
#define PROJET_CDAA_INTERACTION_H


#include <string>
#include <ostream>
#include "../Contact/Contact.h"
#include "../Tache/Tache.h"

using namespace std;

class Interaction {
private:
    string contenu;
    tm dateInteraction;
    Contact contact;

    string dateToString() const;

public:
    void setContenu(string contenu);

    string getContenu();

    //@todo modification de l'intéraction

    Tache *exportTaches();

    void setDateInteraction(tm dateInteraction);

    tm *getDateInteraction();

    void setContact(Contact c);

    Contact *getContact();

    bool operator==(Interaction rhs);

    bool operator!=(Interaction rhs);

    friend ostream &operator<<(ostream &os, const Interaction &interaction);
};


#endif //PROJET_CDAA_INTERACTION_H
