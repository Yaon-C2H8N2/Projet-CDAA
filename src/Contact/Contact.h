//
// Created by yaon on 12/10/22.
//

#ifndef PROJET_CDAA_CONTACT_H
#define PROJET_CDAA_CONTACT_H


#include <string>
#include <list>
#include <ostream>
#include "../Interaction/Interaction.h"

using namespace std;

class Contact {
private:
    string nom, prenom, entreprise, mail, tel;
    list<Interaction> listeInteractions;
    tm dateCreation;
public:
    void setPrenom(string prenom);

    string getPrenom();

    void setNom(string nom);

    string getNom();

    void setEntreprise(string entreprise);

    string getEntreprise();

    void setMail(string mail);

    string getMail();

    void setTel(string tel);

    string getTel();

    void setDateCreation(tm dateCreation);

    tm getDateCreation();

    void addInteraction(Interaction i);

    int getNbInteraction();

    Interaction getInteraction();

    bool operator==(Contact rhs);

    bool operator!=(Contact rhs);

    friend ostream &operator<<(ostream &os, const Contact &contact);
};


#endif //PROJET_CDAA_CONTACT_H
