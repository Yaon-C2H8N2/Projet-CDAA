//
// Created by yaon on 18/10/22.
//

#include "Tache.h"

/**
 * Définit le nom de la Tache.
 * @param nomTache
 * Un nom sous forme de std::string.
 */
void Tache::setNomTache(string nomTache) {
    this->nomTache = nomTache;
}

/**
 * Retourne le nom de cette instance de Tache.
 * @return
 * Le nom de cette instance de Tache sous forme de std::string.
 */
string Tache::getNomTache() {
    return this->nomTache;
}

/**
 * Définit le contenu de cette instnace de Tache.
 * @param contenu
 * Un contenu sous forme de std::string.
 */
void Tache::setContenu(string contenu) {
    this->contenu = contenu;
}

/**
 * Retourne le contenu de cette instance de Tache.
 * @return
 * Le contenu de cette instance de Tache sous forme de std::string.
 */
string Tache::getContenu() {
    return this->contenu;
}

/**
 * Définit la date à laquelle la Tache doit être réalisée.
 * @param dateTache
 * Une structure tm dont la copie sera définie comme date à laquelle la Tache doit être réalisée. Une copie est nécessaire car localtime() retournera toujours le même pointeur.
 */
void Tache::setDateTache(tm dateTache) {
    this->dateTache = dateTache;
}

/**
 * Retourne la date à laquelle la Tache doit être réalisée.
 * @return
 * Un pointeur vers une structure tm symbolisant la date à laquelle la Tache doit être réalisée.
 */
tm Tache::getDateTache() {
    return this->dateTache;
}

/**
 * Redéfinition de l'opérateur d'égalité afin de comparer les tâches entre elles.
 * @param rhs
 * Une instance de Tache avec laquelle comparer l'instance actuelle.
 * @return
 * bool : True si les deux instances de Tache sont égales. sinon false.
 */
bool Tache::operator==(Tache rhs) {
    return nomTache == rhs.nomTache &&
           contenu == rhs.contenu &&
           mktime(&dateTache) == mktime(&rhs.dateTache);
}

/**
 * Redéfinition de l'opérateur d'inégalité afin de comparer les tâches entre elles.
 * @param rhs
 * Une instance de Tache avec laquelle comparer l'instance actuelle.
 * @return
 * bool : True si les deux instances de Tache sont inégales. sinon false.
 */
bool Tache::operator!=(Tache rhs) {
    return !(rhs == *this);
}