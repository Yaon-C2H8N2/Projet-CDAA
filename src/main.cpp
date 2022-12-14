#include <QApplication>
#include <iostream>
#include "Contact/Contact.h"
#include "Interaction/Interaction.h"
#include "GestionContact/GestionContact.h"
#include "GestionTache/GestionTache.h"
#include "GUI/MainWindow/MainWindow.h"
#include "InterfaceBaseDeDonnee/InterfaceBaseDeDonnee.h"

int main(int argc, char *argv[]) {
    QApplication *app = new QApplication(argc, argv);
    MainWindow *mainWindow = new MainWindow(new QMainWindow(nullptr));
    GestionContact *gestionContact = new GestionContact();
    GestionTache *gestionTache = new GestionTache();
    InterfaceBaseDeDonnee *interfaceBaseDeDonnee = new InterfaceBaseDeDonnee();

    interfaceBaseDeDonnee->getContacts(gestionContact);
    interfaceBaseDeDonnee->getInteractions(gestionContact);
    interfaceBaseDeDonnee->getTaches(gestionTache, gestionContact);

    mainWindow->contactList->setContactList(gestionContact);
    mainWindow->tasksList->setTasksList(gestionTache);
    mainWindow->interfaceBaseDeDonnee = interfaceBaseDeDonnee;
    mainWindow->show();

    return app->exec();
}
