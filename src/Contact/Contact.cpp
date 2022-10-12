//
// Created by yaon on 12/10/22.
//

#include "Contact.h"

using namespace std;

Contact::Contact() {
    time_t t = time(0);
    dateCreation = localtime(&t);
}

Contact::~Contact() {
}

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

void Contact::setTel(list<int> tel) {
    this->tel = tel;
}

list<int> Contact::getTel() {
    return this->tel;
}

string Contact::telToString() const {
    string res = "";
    int cpt = 0;
    for (auto i: tel) {
        if (cpt == 2) {
            res += " ";
            cpt = 0;
        }
        res += to_string(i);
        cpt++;
    }
    return res;
}

void Contact::addInteraction(Interaction i) {
    this->listeInteractions.push_back(i);
}

string Contact::listInteractionToString() const {
    string res = "";
    int cpt = 0;
    for (auto i: this->listeInteractions) {
        cpt++;
        res += "\n========== Interaction n°" + to_string(cpt) + " ==========\n";
        res += "Contenu : " + i.getContenu() + "\n";
        res += "Date interaction : " + i.dateToString() + "\n";
    }
    return res;
}

ostream &operator<<(ostream &os, const Contact &contact) {
    os << "nom: " << contact.nom << "\nprenom: " << contact.prenom << "\nentreprise: " << contact.entreprise
       << "\nmail: "
       << contact.mail << "\ntel: " << contact.telToString() << "\nInteractions :\n"
       << contact.listInteractionToString();
    return os;
}
