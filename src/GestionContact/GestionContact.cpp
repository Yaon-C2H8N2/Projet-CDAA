//
// Created by yaon on 12/10/22.
//

#include "GestionContact.h"
#include "../Contact/Contact.h"

void GestionContact::addContact(Contact c) {
    this->listeContacts.push_back(c);
    time_t t = time(0);
    int day = localtime(&t)->tm_mday;
    int month = 1 + localtime(&t)->tm_mon;
    int year = 1900 + localtime(&t)->tm_year;
    string res = "ajout " + c.getNom() + " " + c.getPrenom() + " le " + to_string(day) + "/" + to_string(month) + "/" +
                 to_string(year);
    this->historiqueModifs.push_back(res);
}