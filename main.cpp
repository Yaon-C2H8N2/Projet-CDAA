#include <QApplication>
#include <iostream>
#include "src/Contact/Contact.h"
#include "src/Interaction/Interaction.h"
#include "src/GestionContact/GestionContact.h"

int main(int argc, char *argv[]) {
    Contact c;
    c.setNom("Dusoleil");
    c.setPrenom("Yoan");
    c.setMail("y.dusoleil@outlook.com");
    c.setEntreprise("none");
    c.setTel({0, 6, 7, 6, 5, 7, 7, 8, 3, 6});

    auto *i = new Interaction();
    i->setContenu("@todo rappel @date 12/10/2023");
    c.addInteraction(*i);
    free(i);

    i = new Interaction();
    i->setContenu("discussion afin de fixer un rendez-vous");
    c.addInteraction(*i);
    free(i);

    Contact c2;
    c2.setNom("Gallois");
    c2.setPrenom("Mélissandre");
    c2.setMail("chocoMéli21@gmail.com");
    c2.setEntreprise("none");
    c2.setTel({0, 7, 8, 3, 7, 0, 2, 1, 9, 7});

    GestionContact gc;
    gc.addContact(c);
    gc.addContact(c2);

    cout << gc << "Nb contacts : " << gc.getNbContacts() << endl;

    gc.removeContact(c);

    cout << gc << "Nb contacts : " << gc.getNbContacts() << endl;

    cout << gc.getHistoriqueModifs() << endl;

    return 0;
}
