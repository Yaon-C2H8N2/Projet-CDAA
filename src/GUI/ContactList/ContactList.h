//
// Created by yaon on 30/10/22.
//

#ifndef PROJET_CDAA_CONTACTLIST_H
#define PROJET_CDAA_CONTACTLIST_H


#include <QObject>
#include "ui_ContactList.h"
#include "../../GestionContact/GestionContact.h"

class ContactList : public QObject {
Q_OBJECT
private:
    QWidget *parent;
    GestionContact *gestionContact;
public:
    Ui::ContactList ui;

    ContactList(QWidget *parent);

    void setContactList(GestionContact *gestionContact);

    void show();

signals:
    void refreshContactList(GestionContact *);
public slots:
    void showContactList(GestionContact *);
    void searchInList(QString);
};


#endif //PROJET_CDAA_CONTACTLIST_H
