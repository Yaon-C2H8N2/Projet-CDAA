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
    for (auto j = this->listeContacts.rbegin(); j != this->listeContacts.rend(); j++) {
        if (*j == c1) {
            j->setNom(c2.getNom());
            j->setPrenom(c2.getPrenom());
            j->setTel(c2.getTel());
            j->setMail(c2.getMail());
            j->setEntreprise(c2.getEntreprise());
            j->setCheminPhoto(c2.getCheminPhoto());
            j->setDateCreation(c2.getDateCreation());
            for (int i = 0; i < j->getInteractions()->getNbInteraction(); i++) {
                j->getInteractions()->removeInteraction(j->getInteractions()->getInteraction(i));
            }
            for (int i = 0; i < c2.getInteractions()->getNbInteraction(); i++) {
                j->getInteractions()->addInteraction(c2.getInteractions()->getInteraction(i));
            }
            break;
        }
    }
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
 * Retourne un pointeur vers une instance de GestionContact qui contient les contacts comportant la recherche dans leur nom ou leur prénom.
 * @param name
 * Le nom à rechercher.
 * @return
 * Un pointeur vers une instance de GestionContact contenant les contacts recherchés.
 */
GestionContact *GestionContact::rechercheNom(string name) {
    GestionContact *res = new GestionContact();
    for (auto i: this->listeContacts) {
        if (i.getNom().find(name) != std::string::npos || i.getPrenom().find(name) != std::string::npos) {
            res->addContact(i);
        }
    }
    return res;
}

/**
 * Retourne un pointeur vers une instance de GestionContact qui contient les contacts comportant la recherche dans leur entreprise.
 * @param entreprise
 * L'entreprise à rechercher.
 * @return
 * Un pointeur vers une instance de GestionContact contenant les contacts recherchés.
 */
GestionContact *GestionContact::rechercheEntreprise(string entreprise) {
    GestionContact *res = new GestionContact();
    for (auto i: this->listeContacts) {
        if (i.getEntreprise().find(entreprise) != std::string::npos) {
            res->addContact(i);
        }
    }
    return res;
}

/**
 * Retourne un pointeur vers une instance de GestionContact qui contient les contacts créé à la date recherchée.
 * @param date
 * La date cherchée
 * @return
 * Un pointeur vers une instance de GestionContact contenant les contacts recherchés.
 */
GestionContact *GestionContact::rechercheDateCreation(tm date) {
    GestionContact *res = new GestionContact();
    for (auto i: this->listeContacts) {
        tm dateContact = i.getDateCreation();
        if (mktime(&dateContact) == mktime(&date)) {
            res->addContact(i);
        }
    }
    return res;
}

/**
 * Retourne un pointeur vers une instance de GestionContact qui contient les contacts ayant été créés dans une intervalle de dates données.
 * @param date_debut
 * La date de début de l'intervalle
 * @param date_fin
 * La de fin de l'intervalle
 * @return
 * Un pointeur vers une instance de GestionContact contenant les contacts recherchés.
 */
GestionContact *GestionContact::rechercheIntervalleDate(tm date_debut, tm date_fin) {
    GestionContact *res = new GestionContact();
    for (auto i: this->listeContacts) {
        tm dateContact = i.getDateCreation();
        if (mktime(&dateContact) >= mktime(&date_debut) && mktime(&dateContact) <= mktime(&date_fin)) {
            res->addContact(i);
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
