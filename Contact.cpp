//
// Created by yaon on 12/10/22.
//

#include "Contact.h"

void Contact::setPrenom(std::string prenom) {
    this->prenom = prenom;
}
std::string Contact::getPrenom() {
    return this->prenom;
}

void Contact::setNom(std::string nom) {
    this->nom = nom;
}
std::string Contact::getNom() {
    return this->nom;
}

void Contact::setEntreprise(std::string entreprise) {
    this->entreprise = entreprise;
}
std::string Contact::getEntreprise() {
    return this->entreprise;
}

void Contact::setMail(std::string mail) {
    this->mail = mail;
}
std::string Contact::getMail() {
    return this->mail;
}

void Contact::setTel(std::list<int> tel){
    this->tel = tel;
}
std::list<int> Contact::getTel(){
    return this->tel;
}
std::string Contact::telToString() const {
    std::string res = "";
    for(auto i:tel){
        res+=std::to_string(i);
    }
    return res;
}

std::ostream &operator<<(std::ostream &os, const Contact &contact) {
    os << "nom: " << contact.nom << "\nprenom: " << contact.prenom << "\nentreprise: " << contact.entreprise << "\nmail: "
       << contact.mail << "\ntel: " << contact.telToString();
    return os;
}
