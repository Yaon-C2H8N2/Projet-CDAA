//
// Created by yaon on 12/10/22.
//

#ifndef PROJET_CDAA_INTERACTION_H
#define PROJET_CDAA_INTERACTION_H


#include <string>
#include <ostream>

using namespace std;

class Interaction {
private:
    string contenu;
    tm dateInteraction;
    //@todo lien avec contact

    string dateToString() const;

public:
    void setContenu(string contenu);

    string getContenu();

    //@todo modification de l'intéraction

    //@todo lien interaction/tache

    void setDateInteraction(tm dateInteraction);

    tm *getDateInteraction();

    friend ostream &operator<<(ostream &os, const Interaction &interaction);
};


#endif //PROJET_CDAA_INTERACTION_H
