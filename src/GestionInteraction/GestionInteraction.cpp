#include "GestionInteraction.h"

/**
 * Ajoute à la liste une copie de l'instance Interaction passée en paramètre.
 * @param i
 * Une Interaction est ajoutée à la liste.
 */
void GestionInteraction::addInteraction(Interaction i) {
    this->listeInteractions.push_back(i);
}

/**
 * Supprime toute instance de l'inetraction passée en paramètre.
 * @param i
 * Une Interaction est supprimée de la liste.
 */
void GestionInteraction::removeInteraction(Interaction i) {
    this->listeInteractions.remove(i);
}

/**
 * Retourne le nombre d'instance d'Interaction enregistrée dans la liste.
 * @return
 * Un int décrivant le nombre d'Interaction dans la liste.
 */
int GestionInteraction::getNbInteraction() {
    return this->listeInteractions.size();
}

