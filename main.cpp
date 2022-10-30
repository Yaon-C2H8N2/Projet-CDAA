#include <QApplication>
#include <iostream>
#include "src/Contact/Contact.h"
#include "src/Interaction/Interaction.h"
#include "src/GestionContact/GestionContact.h"
#include "src/GestionTache/GestionTache.h"
#include "src/GUI/MainWindow/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication *app = new QApplication(argc, argv);
    MainWindow *mainWindow = new MainWindow(new QMainWindow(nullptr));
    GestionContact *gestionContact = new GestionContact();

    for (int i = 0; i < 50; i++) {
        Contact *c = new Contact();
        c->setNom("DummyName" + to_string(i));
        c->setPrenom("DummyFirstName" + to_string(i));
        c->setMail("DummyMail" + to_string(i));
        c->setEntreprise("DummyCompany" + to_string(i));
        c->setCheminPhoto("./Dummy/Folder/profilePicture" + to_string(i) + ".jpg");
        c->setTel("DummyPhone" + to_string(i));
        time_t t = time(nullptr);
        t += i * 24 * 3600;
        tm date = *localtime(&t);
        c->setDateCreation(date);
        gestionContact->addContact(*c);
        delete c;
    }

    mainWindow->contactList->setContactList(gestionContact);
    mainWindow->show();

    return app->exec();
}
