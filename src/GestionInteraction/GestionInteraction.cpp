//
// Created by yaon on 18/10/22.
//

#include "GestionInteraction.h"


/**
 * Ajoute à la liste une copie de l'instance d'Interaction passée en paramètre.
 * @param i
 * Une Interaction à ajouter à la liste.
 */
void GestionInteraction::addInteraction(Interaction i) {
    this->listeInteraction.push_back(i);
}

/**
 * Supprime toute instance de l'intéraction passée en paramètre.
 * @param i
 * Une Interaction à supprimer de la liste.
 */
void GestionInteraction::removeInteraction(Interaction i) {
    this->listeInteraction.remove(i);
}

/**
 * Retourne le nombre d'instance de Interaction enregistrée dans la liste.
 * @return
 * Un int décrivant le nombre d'Interaction dans la liste.
 */
int GestionInteraction::getNbInteraction() {
    return this->listeInteraction.size();
}

/**
 * Retourne l'Interaction à un indice spécifique dans la liste
 * @param i
 * Indice de l'Interaction à renvoyer.
 * @return
 * Une copie de l'instance Interaction dans la liste.
 */
Interaction GestionInteraction::getInteraction(int i) {
    int cpt = 0;
    Interaction res;
    if (i < this->getNbInteraction()) {
        for (auto j: this->listeInteraction) {
            if (cpt == i) {
                res = j;
            }
            cpt++;
        }
    } else //throw exception (à voir comment ça marche, je connais pas encore)
        return res;
}