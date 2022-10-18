#include <QApplication>
#include <iostream>
#include "src/Contact/Contact.h"
#include "src/Interaction/Interaction.h"
#include "src/GestionContact/GestionContact.h"

int main(int argc, char *argv[]) {
    GestionContact gc;
    Contact *c = new Contact();
    c->setNom("Dusoleil");
    c->setPrenom("Yoan");
    c->setMail("y.dusoleil@outlook.com");
    c->setEntreprise("none");
    c->setTel("06 76 57 78 36");
    time_t t = time(0);
    tm date = *localtime(&t);
    c->setDateCreation(date);

    auto *i = new Interaction();
    i->setContenu("@todo rappel @date 12/10/2023");
    t = time(0);
    date = *localtime(&t);
    i->setDateInteraction(date);
    c->addInteraction(*i);
    free(i);

    i = new Interaction();
    i->setContenu("discussion afin de fixer un rendez-vous");
    t = time(0);
    date = *localtime(&t);
    i->setDateInteraction(date);
    c->addInteraction(*i);
    free(i);

    tm dateC = c->getDateCreation();
    gc.addContact(*c);
    sleep(2);

    Contact *c2 = new Contact();
    c2->setNom("Gallois");
    c2->setPrenom("Mélissandre");
    c2->setMail("chocoMéli21@gmail.com");
    c2->setEntreprise("none");
    c2->setTel("07 83 70 21 97");
    t = time(0);
    date = *localtime(&t);
    c2->setDateCreation(date);

    tm dateC2 = c2->getDateCreation();
    gc.addContact(*c2);

    for (int k = 0; k < gc.getNbContacts(); k++) {
        cout << "Contact n°" << k << endl;
        cout << gc.getContact(k);
    }

    for (int k = 0; k < gc.getNbContacts(); k++) {
        cout << "Interactions de " << gc.getContact(k).getPrenom() << " " << gc.getContact(k).getNom() << " :" << endl;
        for (int l = 0; l < gc.getContact(k).getNbInteraction(); l++) {
            cout << gc.getContact(k).getInteraction(l) << endl;
        }
    }
    return 0;
}
