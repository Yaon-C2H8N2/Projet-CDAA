//
// Created by yaon on 18/10/22.
//

#include "GestionTache.h"

/**
 * Ajoute à la liste une copie de l'instance de Tache passée en paramètre.
 * @param t
 * Une Tache à ajouter à la liste.
 */
void GestionTache::addTache(Tache t) {
    this->listeTache.push_back(t);
}

/**
 * Supprime toute instance de la tache passée en paramètre.
 * @param t
 * Une Tache à supprimer de la liste.
 */
void GestionTache::removeTache(Tache t) {
    this->listeTache.remove(t);
}

/**
 * Retourne le nombre d'instance de Tache enregistrée dans la liste.
 * @return
 * Un int décrivant le nombre de Tache dans la liste.
 */
int GestionTache::getNbTache() {
    return this->listeTache.size();
}

/**
 * Retourne la Tache à un indice spécifique dans la liste
 * @param i
 * Indice de la Tache à renvoyer.
 * @return
 * Une copie de l'instance Tache dans la liste.
 */
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
    } else {} //throw exception (à voir comment ça marche, je connais pas encore)
    return res;
}

/**
 * Retourne la GestionTache contenant toutes les Tache ayant pour Interaction liée l'Interaction passée en paramètre.
 * @param interaction
 * L'Interaction liée aux Tache recherchées.
 * @return
 * Un pointeur vers une instance de GestionTache.
 */
GestionTache *GestionTache::getTache(Interaction interaction) {
    GestionTache *res = new GestionTache();
    for (auto i: this->listeTache) {
        if (i.getInteraction() == interaction) {
            res->addTache(i);
        }
    }
    return res;
}

/**
 * Redéfinition de l'opérateur d'affichage de GestionTache.
 * @param os
 * Flux de sortie dans lequel on souhaite réaliser l'affichage.
 * @param tache
 * Une instance de GestionTache.
 * @return
 * Le flux de sortie modifié.
 */
ostream &operator<<(ostream &os, const GestionTache &tache) {
    int cpt = 0;
    for (auto i: tache.listeTache) {
        os << "=== Tache n°" << cpt << " ===" << endl;
        os << i << endl;
        cpt++;
    }
    return os;
}

void GestionTache::removeTache(Interaction interaction) {
    GestionTache taches = *this->getTache(interaction);
    for (int i=0; i<taches.getNbTache(); i++) {
        this->removeTache(taches.getTache(i));
    }
}
