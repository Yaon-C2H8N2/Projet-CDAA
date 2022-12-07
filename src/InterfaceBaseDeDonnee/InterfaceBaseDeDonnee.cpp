//
// Created by yaon on 06/12/22.
//

#include <iostream>
#include "InterfaceBaseDeDonnee.h"

InterfaceBaseDeDonnee::InterfaceBaseDeDonnee() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/yaon/Documents/Projet-CDAA/data/data.sqlite");
}

void InterfaceBaseDeDonnee::getContacts(GestionContact *gestionContact) {
    QSqlQuery query(db);
    db.open();
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
}

void InterfaceBaseDeDonnee::getInteractions(GestionContact *gestionContact) {
    QSqlQuery query(db);
    db.open();
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
    db.close();
}

void InterfaceBaseDeDonnee::getTaches(GestionTache *gestionTache, GestionContact *gestionContact) {
    QSqlQuery query(db);
    db.open();
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
}



void InterfaceBaseDeDonnee::updateContact(Contact old_contact, Contact new_contact) {
    QSqlQuery query(db);
    db.open();
    query.prepare("UPDATE contacts SET nom = :newNom, prenom = :newPrenom WHERE nom = :oldNom AND prenom = :oldPrenom");
    query.bindValue(":newNom", QString::fromStdString(new_contact.getNom()));
    query.bindValue(":newPrenom", QString::fromStdString(new_contact.getPrenom()));
    query.bindValue(":oldNom", QString::fromStdString(old_contact.getNom()));
    query.bindValue(":oldPrenom", QString::fromStdString(old_contact.getPrenom()));
    cout << "update " << old_contact.getNom() << " " << old_contact.getPrenom() << " to " << query.boundValue(0).toString().toStdString() << " " << query.boundValue(1).toString().toStdString() << endl;
    query.exec();
    db.close();
}

void InterfaceBaseDeDonnee::insertContact(Contact contact) {
    QSqlQuery query(db);
    db.open();
    query.prepare("INSERT INTO contacts VALUES (null,:nom,:prenom,:mail,:entreprise,:cheminPhoto,:tel,:dateCreation)");
    query.bindValue(":nom", QString::fromStdString(contact.getNom()));
    query.bindValue(":prenom", QString::fromStdString(contact.getPrenom()));
    query.bindValue(":mail", QString::fromStdString(contact.getMail()));
    query.bindValue(":entreprise", QString::fromStdString(contact.getEntreprise()));
    query.bindValue(":cheminPhoto", QString::fromStdString(contact.getCheminPhoto()));
    query.bindValue(":tel", QString::fromStdString(contact.getTel()));
    tm date = contact.getDateCreation();
    query.bindValue(":dateCreation", QDateTime::fromSecsSinceEpoch(mktime(&date)));
    for(auto i:query.boundValues()){
        cout << i.toString().toStdString() << endl;
    }
    query.exec();
    db.close();
}
