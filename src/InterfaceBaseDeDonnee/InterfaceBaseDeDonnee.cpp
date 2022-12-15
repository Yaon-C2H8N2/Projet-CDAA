//
// Created by yaon on 06/12/22.
//

#include <iostream>
#include "InterfaceBaseDeDonnee.h"

/**
 * Constructeur de la classe.
 */
InterfaceBaseDeDonnee::InterfaceBaseDeDonnee() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath() + "/data/data.sqlite");
}

/**
 * Charge les contacts stockés dans la base de données dans la classe GestionContact passée en paramètre.
 * @param gestionContact
 * Un pointeur vers l'instance de GestionContact où on souhaite charger les contacts.
 */
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

/**
 * Charge les intéractions des contacts dans la classe GestionContact passée en paramètre.
 * @param gestionContact
 * Liste des contacts dont on souhaite charger les intéractions.
 */
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

/**
 * Charge les tâches des contacts dans la classe GestionTache passée en paramètre.
 * @param gestionTache
 * Classe dans laquelle on souhaite charger les tâches.
 * @param gestionContact
 * Liste des contacts liés aux tâches.
 */
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

/**
 * Met à jour un contact passé en paramètre avec l'autre contact passé en paramètre.
 * @param old_contact
 * Le Contact à mettre à jour.
 * @param new_contact
 * Le Contact contenant les nouvelles informations.
 */
void InterfaceBaseDeDonnee::updateContact(Contact old_contact, Contact new_contact) {
    QSqlQuery query(db);
    db.open();
    query.prepare(
            "UPDATE contacts SET nom = :newNom, prenom = :newPrenom, mail = :newMail, entreprise = :newEntreprise, cheminPhoto = :newCheminPhoto, tel = :newTel WHERE nom = :oldNom AND prenom = :oldPrenom AND mail = :oldMail AND entreprise = :oldEntreprise AND cheminPhoto = :oldCheminPhoto AND tel = :oldTel");
    query.bindValue(":newNom", QString::fromStdString(new_contact.getNom()));
    query.bindValue(":newPrenom", QString::fromStdString(new_contact.getPrenom()));
    query.bindValue(":newMail", QString::fromStdString(new_contact.getMail()));
    query.bindValue(":newEntreprise", QString::fromStdString(new_contact.getEntreprise()));
    query.bindValue(":newCheminPhoto", QString::fromStdString(new_contact.getCheminPhoto()));
    query.bindValue(":newTel", QString::fromStdString(new_contact.getTel()));
    query.bindValue(":oldNom", QString::fromStdString(old_contact.getNom()));
    query.bindValue(":oldPrenom", QString::fromStdString(old_contact.getPrenom()));
    query.bindValue(":oldMail", QString::fromStdString(old_contact.getMail()));
    query.bindValue(":oldEntreprise", QString::fromStdString(old_contact.getEntreprise()));
    query.bindValue(":oldCheminPhoto", QString::fromStdString(old_contact.getCheminPhoto()));
    query.bindValue(":oldTel", QString::fromStdString(old_contact.getTel()));
    query.exec();
    db.close();
}

/**
 * Fonction insérant un nouveau contact dans la base de donnée.
 * @param contact
 * Le Contact que l'on souhaite ajouter à la base de données.
 */
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
    query.exec();
    db.close();
}

/**
 * Supprime un contact de la base de données.
 * @param contact
 * Le Contact que l'on souhaite supprimer.
 */
void InterfaceBaseDeDonnee::removeContact(Contact contact) {
    //suppression des intéractions du contact
    for (int i = 0; i < contact.getInteractions()->getNbInteraction(); i++) {
        removeInteraction(contact, contact.getInteractions()->getInteraction(i));
    }
    QSqlQuery query(db);
    db.open();
    query.prepare(
            "DELETE FROM contacts WHERE nom = :nom AND prenom = :prenom AND mail = :mail AND entreprise = :entreprise AND cheminPhoto = :cheminPhoto AND tel = :tel");
    query.bindValue(":nom", QString::fromStdString(contact.getNom()));
    query.bindValue(":prenom", QString::fromStdString(contact.getPrenom()));
    query.bindValue(":mail", QString::fromStdString(contact.getMail()));
    query.bindValue(":entreprise", QString::fromStdString(contact.getEntreprise()));
    query.bindValue(":cheminPhoto", QString::fromStdString(contact.getCheminPhoto()));
    query.bindValue(":tel", QString::fromStdString(contact.getTel()));
    tm date = contact.getDateCreation();
    query.bindValue(":dateCreation", QDateTime::fromSecsSinceEpoch(mktime(&date)));
    query.exec();
    db.close();
}

/**
 * Fonction insérant une nouvelle interaction dans la base de donnée.
 * @param contact
 * Le Contact auquel on souhaite ajouter l'interaction.
 * @param interaction
 * L'Interaction que l'on souhaite ajouter à la base de données.
 */
void InterfaceBaseDeDonnee::ajoutInteraction(Contact contact, Interaction interaction) {
    QSqlQuery query(db);
    db.open();
    //récupération id contact
    query.prepare(
            "SELECT id FROM contacts WHERE nom = :nom AND prenom = :prenom AND mail = :mail AND entreprise = :entreprise AND cheminPhoto = :cheminPhoto AND tel = :tel");
    query.bindValue(":nom", QString::fromStdString(contact.getNom()));
    query.bindValue(":prenom", QString::fromStdString(contact.getPrenom()));
    query.bindValue(":mail", QString::fromStdString(contact.getMail()));
    query.bindValue(":entreprise", QString::fromStdString(contact.getEntreprise()));
    query.bindValue(":cheminPhoto", QString::fromStdString(contact.getCheminPhoto()));
    query.bindValue(":tel", QString::fromStdString(contact.getTel()));
    query.exec();
    query.first();
    int idContact = query.value(0).toInt();
    query.clear();
    query.prepare(
            "INSERT INTO interactions VALUES (((SELECT count(idContact) FROM interactions WHERE idContact=:idContact)+1), :idContact, :contenu, :date)");
    query.bindValue(":idContact", idContact);
    query.bindValue(":contenu", QString::fromStdString(interaction.getContenu()));
    tm date = *interaction.getDateInteraction();
    query.bindValue(":date", QDateTime::fromSecsSinceEpoch(mktime(&date)));
    query.exec();
    db.close();
}

/**
 * Supprime une Interaction de la base de données.
 * @param contact
 * Le Contact dont l'Interaction à supprimer est lié.
 * @param interaction
 * L'Interaction que l'on souhaite supprimer de la base de données.
 */
void InterfaceBaseDeDonnee::removeInteraction(Contact contact, Interaction interaction) {
    removeTache(contact, interaction);
    QSqlQuery query(db);
    db.open();
    //récupération id contact
    query.prepare(
            "SELECT id FROM contacts WHERE nom = :nom AND prenom = :prenom AND mail = :mail AND entreprise = :entreprise AND cheminPhoto = :cheminPhoto AND tel = :tel");
    query.bindValue(":nom", QString::fromStdString(contact.getNom()));
    query.bindValue(":prenom", QString::fromStdString(contact.getPrenom()));
    query.bindValue(":mail", QString::fromStdString(contact.getMail()));
    query.bindValue(":entreprise", QString::fromStdString(contact.getEntreprise()));
    query.bindValue(":cheminPhoto", QString::fromStdString(contact.getCheminPhoto()));
    query.bindValue(":tel", QString::fromStdString(contact.getTel()));
    query.exec();
    query.first();
    int idContact = query.value(0).toInt();
    query.clear();
    query.prepare(
            "delete from interactions where idContact = :idContact AND contenu = :contenu AND dateInteraction = :date");
    query.bindValue(":idContact", idContact);
    query.bindValue(":contenu", QString::fromStdString(interaction.getContenu()));
    tm date = *interaction.getDateInteraction();
    query.bindValue(":date", QDateTime::fromSecsSinceEpoch(mktime(&date)));
    query.exec();
    db.close();
}

/**
 * Fonction insérant une nouvelle tâche dans la base de donnée.
 * @param contact
 * Le Contact auquel l'Interaction liée à la Tache est associé.
 * @param interaction
 * L'Interaction liée à la Tache que l'on souhaite ajouter à la base de données.
 * @param tache
 * La Tache que l'on souhaite ajouter à la base de données.
 */
void InterfaceBaseDeDonnee::insertionTache(Contact contact, Interaction interaction, Tache tache) {
    QSqlQuery query(db);
    db.open();
    //récupération id contact
    query.prepare(
            "SELECT id FROM contacts WHERE nom = :nom AND prenom = :prenom AND mail = :mail AND entreprise = :entreprise AND cheminPhoto = :cheminPhoto AND tel = :tel");
    query.bindValue(":nom", QString::fromStdString(contact.getNom()));
    query.bindValue(":prenom", QString::fromStdString(contact.getPrenom()));
    query.bindValue(":mail", QString::fromStdString(contact.getMail()));
    query.bindValue(":entreprise", QString::fromStdString(contact.getEntreprise()));
    query.bindValue(":cheminPhoto", QString::fromStdString(contact.getCheminPhoto()));
    query.bindValue(":tel", QString::fromStdString(contact.getTel()));
    query.exec();
    query.first();
    int idContact = query.value(0).toInt();
    query.clear();
    //récupération id interaction
    query.prepare(
            "select id from interactions where idContact = :idContact AND contenu = :contenu");
    query.bindValue(":idContact", idContact);
    query.bindValue(":contenu", QString::fromStdString(interaction.getContenu()));
    query.exec();
    query.first();
    int idInteraction = query.value(0).toInt();
    query.clear();
    //insertion tache
    query.prepare("insert into taches values (null, :idInteraction, :idContact, :contenu, :dateTache)");
    query.bindValue(":idInteraction", idInteraction);
    query.bindValue(":idContact", idContact);
    query.bindValue(":contenu", QString::fromStdString(tache.getContenu()));
    tm date = tache.getDateTache();
    query.bindValue(":dateTache", QDateTime::fromSecsSinceEpoch(mktime(&date)));
    query.exec();
}

/**
 * Supprime une Tache de la base de données.
 * @param contact
 * Le Contact dont l'Intéraction liée à la Tache à supprimer est lié.
 * @param interaction
 * L'Interaction dont la Tache à supprimer est lié.
 */
void InterfaceBaseDeDonnee::removeTache(Contact contact, Interaction interaction) {
    QSqlQuery query(db);
    db.open();
    //récupération id contact
    query.prepare(
            "SELECT id FROM contacts WHERE nom = :nom AND prenom = :prenom AND mail = :mail AND entreprise = :entreprise AND cheminPhoto = :cheminPhoto AND tel = :tel");
    query.bindValue(":nom", QString::fromStdString(contact.getNom()));
    query.bindValue(":prenom", QString::fromStdString(contact.getPrenom()));
    query.bindValue(":mail", QString::fromStdString(contact.getMail()));
    query.bindValue(":entreprise", QString::fromStdString(contact.getEntreprise()));
    query.bindValue(":cheminPhoto", QString::fromStdString(contact.getCheminPhoto()));
    query.bindValue(":tel", QString::fromStdString(contact.getTel()));
    query.exec();
    query.first();
    int idContact = query.value(0).toInt();
    query.clear();
    //récupération id interaction
    query.prepare(
            "select id from interactions where idContact = :idContact AND contenu = :contenu");
    query.bindValue(":idContact", idContact);
    query.bindValue(":contenu", QString::fromStdString(interaction.getContenu()));
    query.exec();
    query.first();
    int idInteraction = query.value(0).toInt();
    query.clear();
    query.prepare("delete from taches where idInteraction = :idInteraction AND idContact = :idContact");
    query.bindValue(":idInteraction", idInteraction);
    query.bindValue(":idContact", idContact);
    query.exec();
    db.close();
}