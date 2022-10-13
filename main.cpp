#include <QApplication>
#include <iostream>
#include "src/Contact/Contact.h"
#include "src/Interaction/Interaction.h"
#include "src/GestionContact/GestionContact.h"

int main(int argc, char *argv[]) {
    Contact *c = new Contact();
    c->setNom("Dusoleil");
    c->setPrenom("Yoan");
    c->setMail("y.dusoleil@outlook.com");
    c->setEntreprise("none");
    c->setTel("06 76 57 78 36");

    auto *i = new Interaction();
    i->setContenu("@todo rappel @date 12/10/2023");
    c->addInteraction(*i);
    free(i);

    i = new Interaction();
    i->setContenu("discussion afin de fixer un rendez-vous");
    c->addInteraction(*i);
    free(i);

    cout << "id " << c->getPrenom() << " : " << mktime(&c->dateCreation) << endl;

    sleep(2);

    Contact *c2 = new Contact();
    c2->setNom("Gallois");
    c2->setPrenom("Mélissandre");
    c2->setMail("chocoMéli21@gmail.com");
    c2->setEntreprise("none");
    c2->setTel("07 83 70 21 97");

    cout << "id " << c2->getPrenom() << " : " << mktime(&c2->dateCreation) << endl;

    GestionContact gc;
    gc.addContact(c);
    gc.addContact(c2);

    cout << gc << "Nb contacts : " << gc.getNbContacts() << endl;

    cout << gc.getHistoriqueModifs() << endl;

    free(c);
    free(c2);
    return 0;
}
