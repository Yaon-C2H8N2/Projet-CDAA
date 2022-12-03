//
// Created by yaon on 18/10/22.
//

#ifndef PROJET_CDAA_TACHE_H
#define PROJET_CDAA_TACHE_H

#include <string>
#include <ostream>
#include "../Interaction/Interaction.h"

using namespace std;

class Tache {
private:
    string contenu;
    tm dateTache;
    Interaction interaction;
public:
    void setContenu(string contenu);

    string getContenu();

    void setDateTache(tm dateTache);

    tm getDateTache();

    void setInteraction(Interaction interaction);

    Interaction getInteraction();

    friend ostream &operator<<(ostream &os, const Tache &tache);

    bool operator==(Tache rhs);

    bool operator!=(Tache rhs);
};


#endif //PROJET_CDAA_TACHE_H
