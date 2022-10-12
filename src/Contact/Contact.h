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
    string nom, prenom, entreprise, mail;
    list<int> tel;
    tm *dateCreation;
    list<Interaction> listeInteractions;

    string telToString() const;

public:
    Contact();

    ~Contact();

    void setPrenom(string prenom);

    string getPrenom();

    void setNom(string nom);

    string getNom();

    void setEntreprise(string entreprise);

    string getEntreprise();

    void setMail(string mail);

    string getMail();

    void setTel(list<int> tel);

    list<int> getTel();

    void addInteraction(Interaction i);

    string listInteractionToString() const;

    friend ostream &operator<<(ostream &os, const Contact &contact);

    bool operator==(const Contact &rhs) const;

    bool operator!=(const Contact &rhs) const;
};


#endif //PROJET_CDAA_CONTACT_H
