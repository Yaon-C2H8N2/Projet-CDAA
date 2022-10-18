//
// Created by yaon on 18/10/22.
//

#ifndef PROJET_CDAA_GESTIONTACHE_H
#define PROJET_CDAA_GESTIONTACHE_H

#include <list>
#include "../Tache/Tache.h"

using namespace std;

class GestionTache {
private:
    list<Tache> listeTache;
public:
    void addTache(Tache t);

    void removeTache(Tache t);

    int getNbTache();

    Tache getTache(int i);
};


#endif //PROJET_CDAA_GESTIONTACHE_H
