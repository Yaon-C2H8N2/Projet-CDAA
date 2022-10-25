//
// Created by yaon on 12/10/22.
//

#include <iostream>
#include "GestionContact.h"

using namespace std;

void GestionContact::logModif(string contenu) {
    time_t t = time(nullptr);
    int day = localtime(&t)->tm_mday;
    int month = 1 + localtime(&t)->tm_mon;
    int year = 1900 + localtime(&t)->tm_year;
    int hours = localtime(&t)->tm_hour;
    int mins = localtime(&t)->tm_min;
    int seconds = localtime(&t)->tm_sec;
    string res = contenu + " le " + to_string(day) + "/" + to_string(month) + "/" +
                 to_string(year) + " à " + to_string(hours) + ":" + to_string(mins) + ":" + to_string(seconds);
    this->historiqueModifs.push_back(res);
}

/**
 * Ajoute à la liste une copie de l'instance du contact passé en paramètre.
 * @param c
 * Un Contact à ajouter à la liste.
 */
void GestionContact::addContact(Contact c) {
    this->listeContacts.push_back(c);
    logModif("ajout " + c.getNom() + " " + c.getPrenom());
}

/**
 * Supprime toute instance du contact passé en paramètre.
 * @param c
 * Un Contact à supprimer de la liste.
 */
void GestionContact::removeContact(Contact c) {
    this->listeContacts.remove(c);
    logModif("suppression " + c.getNom() + " " + c.getPrenom());
}

/**
 * Remplace les infos du contact partageant le même identifiant que le contact passé en paramètre.
 * @param c
 * L'instance de Contact contenant les nouvelles informations.
 */
void GestionContact::modifyContact(Contact c1, Contact c2) {
    list<Contact> modifiedContact = {c2};
    auto iterator = listeContacts.begin();
    for (auto j: this->listeContacts) {
        if (j == c1) {
            this->listeContacts.splice(iterator, modifiedContact);
            this->listeContacts.remove(c1);
            break;
        }
        std::advance(iterator, 1);
    }
    logModif("modification de " + c2.getNom() + " " + c2.getPrenom());
}

/**
 * Retourne le nombre d'instance de Contact enregistrée dans la liste.
 * @return
 * Un int décrivant le nombre de Contact dans la liste.
 */
int GestionContact::getNbContacts() {
    return this->listeContacts.size();
}

/**
 * Retourne le Contact à un indice spécifique dans la liste
 * @param i
 * Indice du Contact à renvoyer.
 * @return
 * Une copie de l'instance Contact dans la liste.
 */
Contact GestionContact::getContact(int i) {
    int cpt = 0;
    Contact res;
    if (i < this->getNbContacts()) {
        for (auto j: this->listeContacts) {
            if (cpt == i) {
                res = j;
                break;
            }
            cpt++;
        }
    } else {} //throw exception (à voir comment ça marche, je connais pas encore)
    return res;
}

/**
 * Retourne l'historique des modification sur cette instance de GestionContact. Il contiendra tous les ajouts,
 * modifications et suppression de contact ainsi qu'un horodatage.
 * @return
 * Historique des modifications opérée sur la liste de contact sous forme de std::string.
 */
string GestionContact::getHistoriqueModifs() {
    string res = "";
    for (auto i: this->historiqueModifs) {
        res += i + "\n";
    }
    return res;
}

/**
 * Retourne une instance de GestionContact qui contient les contacts comportant la recherche dans leur nom ou leur prénom.
 * @param name
 * Le nom à rechercher.
 * @return
 * Une instance de GestionContact contenant les contacts recherchés.
 */
GestionContact GestionContact::rechercheNom(string name) {
    GestionContact res;
    for (auto i: this->listeContacts) {
        if(i.getNom().find(name) != std::string::npos || i.getPrenom().find(name) != std::string::npos){
            res.addContact(i);
        }
    }
    return res;
}

/**
 * Retourne une instance de GestionContact qui contient les contacts comportant la recherche dans leur entreprise.
 * @param entreprise
 * L'entreprise à rechercher.
 * @return
 * Une instance de GestionContact contenant les contacts recherchés.
 */
GestionContact GestionContact::rechercheEntreprise(string entreprise) {
    GestionContact res;
    for (auto i: this->listeContacts) {
        if(i.getEntreprise().find(entreprise) != std::string::npos){
            res.addContact(i);
        }
    }
    return res;
}

/**
 * Redéfinition de l'opérateur d'affichage de GestionContact.
 * @param os
 * Flux de sortie dans lequel on souhaite réaliser l'affichage.
 * @param contact
 * Une instance de GestionContact.
 * @return
 * Le flux de sortie modifié.
 */
ostream &operator<<(ostream &os, const GestionContact &contact) {
    int cpt = 0;
    for (auto i: contact.listeContacts) {
        os << "========== Contact n°" << cpt << " ==========" << endl;
        os << i << endl;
        cpt++;
    }
    return os;
}
