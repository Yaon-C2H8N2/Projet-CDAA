//
// Created by yaon on 12/10/22.
//

#include "Contact.h"

using namespace std;

void Contact::setPrenom(string prenom) {
    this->prenom = prenom;
}

string Contact::getPrenom() {
    return this->prenom;
}

void Contact::setNom(string nom) {
    this->nom = nom;
}

string Contact::getNom() {
    return this->nom;
}

void Contact::setEntreprise(string entreprise) {
    this->entreprise = entreprise;
}

string Contact::getEntreprise() {
    return this->entreprise;
}

void Contact::setMail(string mail) {
    this->mail = mail;
}

string Contact::getMail() {
    return this->mail;
}

void Contact::setTel(string tel) {
    this->tel = tel;
}

string Contact::getTel() {
    return this->tel;
}

void Contact::setDateCreation(tm dateCreation) {
    this->dateCreation = dateCreation;
}

tm *Contact::getDateCreation() {
    return &this->dateCreation;
}

void Contact::addInteraction(Interaction i) {
    this->listeInteractions.push_back(i);
}

ostream &operator<<(ostream &os, const Contact &contact) {
    os << "nom: " << contact.nom << "\nprenom: " << contact.prenom << "\nentreprise: " << contact.entreprise
       << "\nmail: "
       << contact.mail << "\ntel: " << contact.tel << "\nInteractions :\n";
    int cpt = 0;
    for (auto i: contact.listeInteractions) {
        cpt++;
        os << "========== Interaction n°" + to_string(cpt) + " ==========\n";
        os << i << endl;
    }
    return os;
}

bool Contact::operator==(Contact rhs) {
    return mktime(&this->dateCreation) == mktime(&rhs.dateCreation);
}

bool Contact::operator!=(Contact rhs) {
    return !(rhs == *this);
}
