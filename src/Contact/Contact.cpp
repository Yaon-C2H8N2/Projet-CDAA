//
// Created by yaon on 12/10/22.
//

#include "Contact.h"

using namespace std;

/**
 * Définit le prenom pour cette instance de Contact.
 * @param prenom
 * Un prénom sous forme de std::string.
 */
void Contact::setPrenom(string prenom) {
    this->prenom = prenom;
}

/**
 * Retourne le prenom pour cette instance de Contact.
 * @return
 * Le prénom de cette instance de Contact sous forme de std::string.
 */
string Contact::getPrenom() {
    return this->prenom;
}

/**
 * Définit le nom pour cette instance de Contact.
 * @param nom
 * Un nom sous forme de std::string.
 */
void Contact::setNom(string nom) {
    this->nom = nom;
}

/**
 * Retourne le nom pour cette instance de Contact.
 * @return
 * Le nom de cette instance de Contact sous forme de std::string.
 */
string Contact::getNom() {
    return this->nom;
}

/**
 * Définit l'entreprise du contact pour cette instance de Contact.
 * @param entreprise
 * Le nom d'une entreprise sous forme de std::string.
 */
void Contact::setEntreprise(string entreprise) {
    this->entreprise = entreprise;
}

/**
 * Retourne le nom de l'entreprise spécifiée dans cette instance de Contact.
 * @return
 * Le nom de l'entreprise du contact sous forme de std::string.
 */
string Contact::getEntreprise() {
    return this->entreprise;
}

/**
 * Définit le mail du contact pour cette instance de Contact.
 * @param mail
 * Une adresse mail valide sous forme de std::string.
 */
void Contact::setMail(string mail) {
    this->mail = mail;
}

/**
 * Retourne l'adresse mail spécifiée dans cette instance de Contact.
 * @return
 * L'addresse mail du contact sous forme de std::string.
 */
string Contact::getMail() {
    return this->mail;
}

/**
 * Définit le numéro de téléphone du contact pour cette instance de Contact.
 * @param tel
 * Un numéro de téléphone sous forme de std::string.
 */
void Contact::setTel(string tel) {
    this->tel = tel;
}

/**
 * Retourne le numéro de tel dans cette instance de Contact.
 * @return
 * Un numéro de téléphone sous forme de std::string.
 */
string Contact::getTel() {
    return this->tel;
}

/**
 * Définit le chemin de la photo du contact.
 * @param cheminPhoto
 * Un chemin relatif ou absolu vers la photo du contact.
 */
void Contact::setCheminPhoto(string cheminPhoto) {
    this->cheminPhoto = cheminPhoto;
}

/**
 * Retourne le chemin de la photo du contact.
 * @return
 * Un chemin relatif ou absolu vers la photo du contact.
 */
string Contact::getCheminPhoto() {
    return this->cheminPhoto;
}

/**
 * Définit la date de création du contact.
 * @param dateCreation
 * Une structure tm dont la copie sera définie comme date de création du contact. Une copie est nécessaire car
 * localtime() retournera toujours le même pointeur.
 */
void Contact::setDateCreation(tm dateCreation) {
    this->dateCreation = dateCreation;
}

/**
 * Retourne la date de création du contact. Ne dépend pas de la création de l'instance de Contact.
 * @return
 * Un pointeur vers une structure tm symbolisant une date.
 */
tm Contact::getDateCreation() {
    return this->dateCreation;
}

/**
 * Redéfinition de l'opérateur d'affichage de Contact.
 * @param os
 * Flux de sortie dans lequel on souhaite réaliser l'affichage.
 * @param contact
 * Une instance de Contact.
 * @return
 * Le flux de sortie modifié.
 */
ostream &operator<<(ostream &os, const Contact &contact) {
    os << "nom: " << contact.nom << "\nprenom: " << contact.prenom << "\nentreprise: " << contact.entreprise
       << "\nmail: "
       << contact.mail << "\ntel: " << contact.tel << "\ncheminPhoto: " << contact.cheminPhoto << "\nInteractions :\n"
       << contact.interactions;
    int cpt = 0;
    return os;
}

/**
 * Redéfinition de l'opérateur == afin de tester l'égalité entre 2 instances de Contact.
 * @param rhs
 * Une instance de Contact avec laquelle comparer l'instance actuelle.
 * @return
 * bool : True si les contacts sont égaux, sinon false.
 */
bool Contact::operator==(Contact rhs) {
    return mktime(&this->dateCreation) == mktime(&rhs.dateCreation) && this->prenom == rhs.prenom &&
           this->nom == rhs.nom && this->entreprise == rhs.entreprise && this->tel == rhs.tel && this->mail == rhs.mail;
}

/**
 * Rédéfinition de l'opérateur != afin de tester l'inégalité entre 2 instances de Contact.
 * @param rhs
 * Une instance de Contact avec laquelle comparer l'instance actuelle.
 * @return
 * bool : True si les contacts sont inégaux, sinon false.
 */
bool Contact::operator!=(Contact rhs) {
    return !(rhs == *this);
}

/**
 * Retourne la liste des Interaction du Contact.
 * @return
 * Un pointeur vers la classe GestionInteraction représentant la liste des Interaction du Contact.
 */
GestionInteraction *Contact::getInteractions() {
    return &this->interactions;
}
