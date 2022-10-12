#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "Contact/Contact.h"
#include "Interaction/Interaction.h"

int main(int argc, char *argv[]) {
    Contact c;
    c.setNom("Dusoleil");
    c.setPrenom("Yoan");
    c.setMail("y.dusoleil@outlook.com");
    c.setEntreprise("Dassault Nuclear");
    c.setTel({0, 6, 7, 6, 5, 7, 7, 8, 3, 6});

    auto *i = new Interaction();
    i->setContenu("@todo rappel @date 12/10/2023");
    c.addInteraction(*i);
    free(i);

    i = new Interaction();
    i->setContenu("discussion afin de fixer un rendez-vous");
    c.addInteraction(*i);
    free(i);

    cout << c << endl;

    return 0;
}
