//
// Created by yaon on 30/10/22.
//

#include "ContactList.h"
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
    auto children = ui.scrollArea->widget()->findChildren<QPushButton *>();
    for (auto i: children) {
        ui.scrollArea->widget()->layout()->removeWidget(i);
        delete i;
    }

    for (int i = 0; i < gestionContact->getNbContacts(); i++) {
        QPushButton *qPushButton = new QPushButton(ui.scrollArea->widget());
        qPushButton->setObjectName("contactButton");
        qPushButton->setText(QString::fromStdString(
                gestionContact->getContact(i).getPrenom() + " " + gestionContact->getContact(i).getNom()));
        ui.scrollArea->widget()->layout()->addWidget(qPushButton);
    }
}

void ContactList::searchInList(QString content) {
    emit refreshContactList(this->gestionContact->rechercheNom(content.toStdString()));
}