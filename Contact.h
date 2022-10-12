//
// Created by yaon on 12/10/22.
//

#ifndef PROJET_CDAA_CONTACT_H
#define PROJET_CDAA_CONTACT_H


#include <string>
#include <list>

class Contact {
private:
    std::string nom, prenom, entreprise, mail;
    std::list<int> tel;
    //tm* dateCreation;
    //std::list<Interaction> listeInteractions;
public:
    Contact();

    ~Contact();

    const std::string &getNom() const;

    void setNom(const std::string &nom);

    const std::string &getPrenom() const;

    void setPrenom(const std::string &prenom);

    const std::string &getEntreprise() const;

    void setEntreprise(const std::string &entreprise);

    const std::string &getMail() const;

    void setMail(const std::string &mail);
};


#endif //PROJET_CDAA_CONTACT_H
