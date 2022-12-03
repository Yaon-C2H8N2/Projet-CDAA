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
    GestionTache *gestionTache = new GestionTache();

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
        for (int j = 0; j < 2; j++) {
            Interaction *inter = new Interaction();
            t += 10 * 24 * 3600; //interaction 10 jours après la précédente
            date = *localtime(&t);
            inter->setDateInteraction(date);
            inter->setContenu(
                    "Interaction n°" + to_string(j) + "\n@todo test test test @date " + to_string(date.tm_mday) + "/" +
                    to_string(1 + date.tm_mon) + "/" + to_string(1900 + date.tm_year));
            c->getInteractions()->addInteraction(*inter);
        }
        gestionContact->addContact(*c);
        delete c;
    }

    mainWindow->contactList->setContactList(gestionContact);
    mainWindow->show();

    return app->exec();
}
