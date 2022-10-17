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

    cout << "id " << c->getPrenom() << " : " << mktime(c->getDateCreation()) << endl;
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

    cout << "id " << c2->getPrenom() << " : " << mktime(c2->getDateCreation()) << endl;
    gc.addContact(*c2);

    cout << gc << "Nb contacts : " << gc.getNbContacts() << endl;
    gc.removeContact(*c);
    cout << gc << "Nb contacts : " << gc.getNbContacts() << endl;

    cout << gc.getHistoriqueModifs() << endl;

    free(c);
    free(c2);

    cout << gc << endl;
    cout << gc.getContact().getNom() << endl;
    return 0;
}
