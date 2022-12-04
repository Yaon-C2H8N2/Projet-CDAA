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

    //chargement des contacts
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

    //chargement des intéractions
    query.exec("select idContact, contenu, dateInteraction from interactions");
    while (query.next()) {
        Contact c = gestionContact->getContact(query.value(0).toInt() - 1);
        Interaction i;
        i.setContenu(query.value(1).toString().toStdString());
        time_t t = query.value(2).toDateTime().toSecsSinceEpoch();
        tm date = *localtime(&t);
        i.setDateInteraction(date);
        c.getInteractions()->addInteraction(i);
        gestionContact->modifyContact(gestionContact->getContact(query.value(0).toInt() - 1), c);
    }

    //chargement des tâches
    query.exec(
            "select idInteraction, idContact, taches.contenu, dateTache from taches");
    while (query.next()) {
        Interaction interaction = gestionContact->getContact(
                query.value(1).toInt() - 1).getInteractions()->getInteraction(query.value(0).toInt() - 1);
        Tache tache;
        tache.setInteraction(interaction);
        tache.setContenu(query.value(2).toString().toStdString());
        time_t t = query.value(3).toDateTime().toSecsSinceEpoch();
        tm date = *localtime(&t);
        tache.setDateTache(date);
        gestionTache->addTache(tache);
    }

    db.close();

    mainWindow->contactList->setContactList(gestionContact);
    mainWindow->show();

    return app->exec();
}
