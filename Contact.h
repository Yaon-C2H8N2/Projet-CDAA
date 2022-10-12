//
// Created by yaon on 12/10/22.
//

#ifndef PROJET_CDAA_CONTACT_H
#define PROJET_CDAA_CONTACT_H


#include <string>
#include <list>
#include <ostream>

class Contact {
private:
    std::string nom, prenom, entreprise, mail;
    std::list<int> tel;
    //tm* dateCreation;
    //std::list<Interaction> listeInteractions;
public:
    void setPrenom(std::string prenom);
    std::string getPrenom();

    void setNom(std::string nom);
    std::string getNom();

    void setEntreprise(std::string entreprise);
    std::string getEntreprise();

    void setMail(std::string mail);
    std::string getMail();

    friend std::ostream &operator<<(std::ostream &os, const Contact &contact);

    void setTel(std::list<int> tel);
    std::list<int> getTel();
    std::string telToString() const;
};


#endif //PROJET_CDAA_CONTACT_H
