//
// Created by yaon on 30/10/22.
//

#include "ContactList.h"
#include "../ContactButton/ContactButton.h"
#include <iostream>

ContactList::ContactList(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(this->parent);
    QObject::connect(this, SIGNAL(refreshContactList(GestionContact * )),
                     SLOT(showContactList(GestionContact * )));
    QObject::connect(this->ui.lineEdit, SIGNAL(textChanged(
                                                       const QString &)), this, SLOT(searchInList(QString)));
}

void ContactList::setContactList(GestionContact *gestionContact) {
    this->gestionContact = gestionContact;
    emit refreshContactList(this->gestionContact);
}

void ContactList::show() {
    this->parent->show();
}

void ContactList::showContactList(GestionContact *gestionContact) {
    auto children = ui.scrollArea->widget()->findChildren<ContactButton *>();
    for (auto i: children) {
        ui.scrollArea->widget()->layout()->removeWidget(i);
        i->close();
    }

    for (int i = 0; i < gestionContact->getNbContacts(); i++) {
        ContactButton *contactButton = new ContactButton(ui.scrollArea->widget(), gestionContact->getContact(i));
        QObject::connect(contactButton, SIGNAL(clicked(Contact)), this, SLOT(contactClicked(Contact)));
        QObject::connect(contactButton, SIGNAL(modifyContact(Contact)), this, SLOT(modifyContact(Contact)));
        QObject::connect(contactButton, SIGNAL(deleteContact(Contact)), this, SLOT(deleteContact(Contact)));
        ui.scrollArea->widget()->layout()->addWidget(contactButton);
    }
}

void ContactList::searchInList(QString content) {
    emit refreshContactList(this->gestionContact->rechercheNom(content.toStdString()));
}

void ContactList::contactClicked(Contact contact) {
    emit showContactInfo(contact);
}

void ContactList::addNewContact(Contact c) {
    this->gestionContact->addContact(c);
    emit refreshContactList(this->gestionContact);
}

void ContactList::deleteContact(Contact c) {
    //@todo dialog de confirmation
    this->gestionContact->removeContact(c);
    emit refreshContactList(this->gestionContact);
}

void ContactList::modifyContact(Contact c) {
    cout << "Modification requested for " << c.getNom() << endl;
    //@todo dialog ou fenêtre de modification de contact
}
