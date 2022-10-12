#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "Contact.h"

int main(int argc, char *argv[]) {
    Contact c;

    c.setPrenom("Yaon");
    c.setNom("Dusoleil");
    c.setMail("y.dusoleil@outlook.com");
    c.setEntreprise("Dassault Nuclear");
    c.setTel({0,6,7,6,5,7,7,8,3,6});

    std::cout << c << std::endl;

    return 0;
}
