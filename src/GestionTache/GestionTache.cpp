//
// Created by yaon on 18/10/22.
//

#include "GestionTache.h"

void GestionTache::addTache(Tache t) {
    this->listeTache.push_back(t);
}

void GestionTache::removeTache(Tache t) {
    this->listeTache.remove(t);
}

int GestionTache::getNbTache() {
    return this->listeTache.size();
}

Tache GestionTache::getTache(int i) {
    int cpt = 0;
    Tache res;
    if (i < this->getNbTache()) {
        for (auto j: this->listeTache) {
            if (cpt == i) {
                res = j;
            }
            cpt++;
        }
    } else //throw exception (à voir comment ça marche, je connais pas encore)
        return res;
}
