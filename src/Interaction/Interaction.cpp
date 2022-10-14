//
// Created by yaon on 12/10/22.
//

#include <ctime>
#include "Interaction.h"

using namespace std;

string Interaction::dateToString() const {
    string res = "";
    res += to_string(this->dateInteraction.tm_mday);
    res += "/";
    res += to_string(1 + this->dateInteraction.tm_mon);
    res += "/";
    res += to_string(1900 + this->dateInteraction.tm_year);
    return res;
}

/**
 * Définit le contenu de l'intéraction.
 * @param contenu
 * Le contenu au format std::string.
 */
void Interaction::setContenu(string contenu) {
    this->contenu = contenu;
}

/**
 * Retourne le contenu de l'intéraction.
 * @return
 * Le contenu au format std::string.
 */
string Interaction::getContenu() {
    return this->contenu;
}

/**
 * Définit la date de l'intéraction.
 * @param dateInteraction
 * Une structure tm qui sera copiée pour définir la date de l'intéraction.
 */
void Interaction::setDateInteraction(tm dateInteraction) {
    this->dateInteraction = dateInteraction;
}

/**
 * Retourne un pointeur vers la date de l'intéraction.
 * @return
 * Un pointeur de structure tm pour accéder à la date de l'intéraction.
 */
tm *Interaction::getDateInteraction() {
    return &this->dateInteraction;
}

/**
 * Redéfinition de l'opérateur d'affichage de Interaction.
 * @param os
 * Flux de sortie dans lequel on souhaite réaliser l'affichage.
 * @param interaction
 * Une instance de Interaction.
 * @return
 * Le flux de sortie modifié.
 */
ostream &operator<<(ostream &os, const Interaction &interaction) {
    os << "contenu: " << interaction.contenu << "\ndateInteraction: " << interaction.dateToString() << endl;
    return os;
}
