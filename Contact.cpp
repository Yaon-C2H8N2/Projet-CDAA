//
// Created by yaon on 12/10/22.
//

#include "Contact.h"

const std::string &Contact::getNom() const {
    return nom;
}

void Contact::setNom(const std::string &nom) {
    Contact::nom = nom;
}

const std::string &Contact::getPrenom() const {
    return prenom;
}

void Contact::setPrenom(const std::string &prenom) {
    Contact::prenom = prenom;
}

const std::string &Contact::getEntreprise() const {
    return entreprise;
}

void Contact::setEntreprise(const std::string &entreprise) {
    Contact::entreprise = entreprise;
}

const std::string &Contact::getMail() const {
    return mail;
}

void Contact::setMail(const std::string &mail) {
    Contact::mail = mail;
}

Contact::Contact() {
    //init dateCreation
}

Contact::~Contact() {
    //free dateCreation
    //clear listInteraction
}
