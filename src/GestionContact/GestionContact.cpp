//
// Created by yaon on 12/10/22.
//

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
 * Retourne le nombre d'instance de Contact enregistrée dans la liste.
 * @return
 * Un int décrivant le nombre de Contact dans la liste.
 */
int GestionContact::getNbContacts() {
    return this->listeContacts.size();
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
        os << "Contact n°" << cpt << " : " << i.getPrenom() << " " << i.getNom() << endl;
        cpt++;
    }
    return os;
}
