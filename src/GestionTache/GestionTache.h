#ifndef PROJET_CDAA_GESTIONTACHE_H
#define PROJET_CDAA_GESTIONTACHE_H

#include <list>
#include <ostream>
#include "../Tache/Tache.h"

using namespace std;

class GestionTache {
private:
    list<Tache> listeTache;
public:
    void addTache(Tache t);

    void removeTache(Tache t);

    void removeTache(Interaction interaction);

    int getNbTache();

    Tache getTache(int i);

    GestionTache *getTache(Interaction interaction);

    friend ostream &operator<<(ostream &os, const GestionTache &tache);
};


#endif //PROJET_CDAA_GESTIONTACHE_H
