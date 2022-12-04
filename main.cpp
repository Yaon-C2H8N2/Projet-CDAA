#include <QApplication>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
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

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/yaon/Documents/Projet-CDAA/data/data.sqlite");
    db.open();

    QSqlQuery query(db);
    query.exec("SELECT * FROM contacts");

    while (query.next()) {
        Contact *c = new Contact();
        c->setNom(query.value(1).toString().toStdString());
        c->setPrenom(query.value(2).toString().toStdString());
        c->setMail(query.value(3).toString().toStdString());
        c->setEntreprise(query.value(4).toString().toStdString());
        c->setCheminPhoto(query.value(5).toString().toStdString());
        c->setTel(query.value(6).toString().toStdString());
        time_t t = query.value(7).toDateTime().toSecsSinceEpoch();
        tm date = *localtime(&t);
        c->setDateCreation(date);
        gestionContact->addContact(*c);
    }

    db.close();

    mainWindow->contactList->setContactList(gestionContact);
    mainWindow->show();

    return app->exec();
}
