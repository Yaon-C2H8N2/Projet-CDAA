//
// Created by yaon on 15/12/22.
//

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <iostream>
#include "InterfaceJSON.h"
#include "../InterfaceBaseDeDonnee/InterfaceBaseDeDonnee.h"

/**
 * Exporte les contacts dans un fichier JSON
 * @param gestionContact
 * L'instance de GestionContact que l'on souhaite exporter
 * @param path
 * Le chemin du fichier dans lequel on souhaite exporter
 */
void InterfaceJSON::exportInJson(GestionContact *gestionContact, QString path) {
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QJsonDocument doc;
    QJsonObject obj;
    QJsonArray contacts;
    for (int i = 0; i < gestionContact->getNbContacts(); i++) {
        QJsonObject contact;
        contact["nom"] = QString::fromStdString(gestionContact->getContact(i).getNom());
        contact["prenom"] = QString::fromStdString(gestionContact->getContact(i).getPrenom());
        contact["entreprise"] = QString::fromStdString(gestionContact->getContact(i).getEntreprise());
        contact["mail"] = QString::fromStdString(gestionContact->getContact(i).getMail());
        contact["tel"] = QString::fromStdString(gestionContact->getContact(i).getTel());
        contact["dateCreation"] =
                QString::fromStdString(to_string(gestionContact->getContact(i).getDateCreation().tm_mday)) + "/" +
                QString::fromStdString(to_string(gestionContact->getContact(i).getDateCreation().tm_mon + 1)) + "/" +
                QString::fromStdString(to_string(gestionContact->getContact(i).getDateCreation().tm_year + 1900));
        contacts.append(contact);
    }
    obj["contacts"] = contacts;
    doc.setObject(obj);
    file.write(doc.toJson());
    file.close();
}

/**
 * Importe les contacts d'un fichier JSON
 * @param gestionContact
 * L'instance de GestionContact dans laquelle on souhaite importer les contacts
 * @param path
 * Le chemin du fichier à importer
 * @param interfaceBaseDeDonnee
 * L'instance de InterfaceBaseDeDonnee dans laquelle on souhaite sauvegarder les contacts importés
 */
void InterfaceJSON::importFromJson(GestionContact *gestionContact, QString path,
                                   InterfaceBaseDeDonnee *interfaceBaseDeDonnee) {
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonObject obj = doc.object();
    QJsonArray contacts = obj["contacts"].toArray();
    for (int i = 0; i < contacts.size(); i++) {
        QJsonObject contact = contacts[i].toObject();
        Contact c;
        c.setNom(contact["nom"].toString().toStdString());
        c.setPrenom(contact["prenom"].toString().toStdString());
        c.setEntreprise(contact["entreprise"].toString().toStdString());
        c.setMail(contact["mail"].toString().toStdString());
        c.setTel(contact["tel"].toString().toStdString());
        c.setCheminPhoto((QApplication::applicationDirPath() +
                          "/data/photo/default.png").toStdString());
        QString date = contact["dateCreation"].toString();
        QDateTime qDateCreation = QDateTime::fromString(date, "dd/MM/yyyy");
        time_t t = qDateCreation.toSecsSinceEpoch();
        tm dateCreation = *localtime(&t);
        c.setDateCreation(dateCreation);
        gestionContact->addContact(c);
        interfaceBaseDeDonnee->insertContact(c);
    }
    file.close();
}