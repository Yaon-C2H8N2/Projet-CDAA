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

    GestionContact *getContactList();

    void show();

signals:

    void refreshContactList(GestionContact *);

    void showContactInfo(Contact);

    void createButtonClicked();

    void contactModified(Contact, Contact);

private slots:

    void showContactList(GestionContact *);

    void searchInList(QString);

    void contactClicked(Contact);

    void createContact();

    void addNewContact(Contact);

    void deleteContact(Contact);

    void modifyContact(Contact);
};


#endif //PROJET_CDAA_CONTACTLIST_H
