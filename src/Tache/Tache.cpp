//
// Created by yaon on 18/10/22.
//

#include "Tache.h"

void Tache::setNomTache(string nomTache) {
    this->nomTache = nomTache;
}

string Tache::getNomTache() {
    return this->nomTache;
}

void Tache::setContenu(string contenu) {
    this->contenu = contenu;
}

string Tache::getContenu() {
    return this->contenu;
}

void Tache::setDateTache(tm dateTache) {
    this->dateTache = dateTache;
}

tm Tache::getDateTache() {
    return this->dateTache;
}

bool Tache::operator==(Tache rhs) {
    return nomTache == rhs.nomTache &&
           contenu == rhs.contenu &&
           mktime(&dateTache) == mktime(&rhs.dateTache);
}

bool Tache::operator!=(Tache rhs) {
    return !(rhs == *this);
}
