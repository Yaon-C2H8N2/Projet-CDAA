//
// Created by yaon on 31/10/22.
//

#include <iostream>
#include "ContactCreator.h"

ContactCreator::ContactCreator(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(parent);
    auto children = this->parent->findChildren<QLineEdit *>();
    for (auto i: children) {
        QObject::connect(i,SIGNAL(textChanged(const QString &)),this,SLOT(validateFields()));
    }
    QObject::connect(this->ui.validatePushButton, SIGNAL(clicked()), this, SLOT(validateButtonClicked()));
    QObject::connect(this->ui.cancelPushButton, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));
}

void ContactCreator::setContact(Contact contact) {
    this->contact = contact;
    this->ui.firstNameLineEdit->setText(QString::fromStdString(this->contact.getPrenom()));
    this->ui.lastNameLineEdit->setText(QString::fromStdString(this->contact.getNom()));
    this->ui.companyNameLineEdit->setText(QString::fromStdString(this->contact.getEntreprise()));
    this->ui.phoneNumberLineEdit->setText(QString::fromStdString(this->contact.getTel()));
    this->ui.mailAddressLineEdit->setText(QString::fromStdString(this->contact.getMail()));
}

void ContactCreator::show() {
    this->parent->show();
}

void ContactCreator::hide() {
    this->parent->hide();
}

//@todo revoir le concept
void ContactCreator::validateFields() {
    auto children = this->parent->findChildren<QLineEdit *>();
    bool notEmpty = true;
    for (auto i: children) {
        if(i->text()=="")notEmpty = false;
    }
    this->ui.validatePushButton->setEnabled(notEmpty);
}

void ContactCreator::validateButtonClicked() {
    this->contact.setNom(this->ui.lastNameLineEdit->text().toStdString());
    this->contact.setPrenom(this->ui.firstNameLineEdit->text().toStdString());
    this->contact.setEntreprise(this->ui.companyNameLineEdit->text().toStdString());
    this->contact.setTel(this->ui.phoneNumberLineEdit->text().toStdString());
    this->contact.setMail(this->ui.mailAddressLineEdit->text().toStdString());
    time_t t = time(nullptr);
    tm date = *localtime(&t);
    this->contact.setDateCreation(date);
    //@todo chemin photo
    emit validateContact(this->contact);
    this->hide();
}

void ContactCreator::cancelButtonClicked() {
    this->setContact(*new Contact());
    this->hide();
}