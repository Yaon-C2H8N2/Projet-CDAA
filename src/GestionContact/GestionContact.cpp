//
// Created by yaon on 12/10/22.
//

#include "GestionContact.h"

using namespace std;

void GestionContact::logModif(string contenu) {
    time_t t = time(0);
    int day = localtime(&t)->tm_mday;
    int month = 1 + localtime(&t)->tm_mon;
    int year = 1900 + localtime(&t)->tm_year;
    string res = contenu + " le " + to_string(day) + "/" + to_string(month) + "/" +
                 to_string(year);
    this->historiqueModifs.push_back(res);
}

void GestionContact::addContact(Contact &c) {
    this->listeContacts.push_back(c);
    logModif("ajout " + c.getNom() + " " + c.getPrenom());
}

void GestionContact::removeContact(Contact &c) {
    this->listeContacts.remove(c);
    logModif("suppression " + c.getNom() + " " + c.getPrenom());
}

int GestionContact::getNbContacts() {
    return this->listeContacts.size();
}

string GestionContact::getHistoriqueModifs() {
    string res = "";
    for (auto i: this->historiqueModifs) {
        res += i + "\n";
    }
    return res;
}

ostream &operator<<(ostream &os, const GestionContact &contact) {
    int cpt = 0;
    for (auto i: contact.listeContacts) {
        os << "Contact n°" << cpt << " : " << i.getPrenom() << " " << i.getNom() << endl;
        cpt++;
    }
    return os;
}
