//
// Created by yaon on 30/10/22.
//

#include "ContactInfo.h"

ContactInfo::ContactInfo(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(parent);
}

void ContactInfo::setContact(Contact contact) {
    this->contact = contact;
    this->ui.nameLabel->setText(QString::fromStdString(contact.getPrenom() + " " + contact.getNom()));
    this->ui.companyNameLabel->setText(QString::fromStdString(contact.getEntreprise()));
    this->ui.phoneNumberLabel->setText(QString::fromStdString(contact.getTel()));
    this->ui.mailAddressLabel->setText(QString::fromStdString(contact.getMail()));
    this->ui.photoLabel->setText(QString::fromStdString(contact.getCheminPhoto()));
    this->ui.creationDateLabel->setText(QString::fromStdString(
            to_string(contact.getDateCreation().tm_mday) + "/" + to_string(contact.getDateCreation().tm_mon + 1) + "/" +
            to_string(contact.getDateCreation().tm_year + 1900)));
    this->show();
}

void ContactInfo::show() {
    this->parent->show();
}

void ContactInfo::hide() {
    this->parent->hide();
}
