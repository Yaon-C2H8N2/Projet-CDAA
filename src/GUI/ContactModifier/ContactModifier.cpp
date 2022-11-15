//
// Created by yaon on 15/11/22.
//

#include "ContactModifier.h"

ContactModifier::ContactModifier(QDialog *parent) {
    this->parent = parent;
    this->ui.setupUi(this);
    QObject::connect(this->ui.buttonBox, SIGNAL(accepted()), this, SLOT(validateChanges()));
}

void ContactModifier::setContact(Contact contact) {
    this->contact = contact;
    this->ui.firstNameEdit->setText(QString::fromStdString(contact.getPrenom()));
    this->ui.lastNameEdit->setText(QString::fromStdString(contact.getNom()));
    this->ui.mailEdit->setText(QString::fromStdString(contact.getMail()));
    this->ui.phoneNumberEdit->setText(QString::fromStdString(contact.getTel()));
    this->ui.companyNameEdit->setText(QString::fromStdString(contact.getEntreprise()));
    //@todo chemin photo avec le pushButton
}

Contact ContactModifier::getContact() {
    return this->contact;
}

void ContactModifier::validateChanges() {
    this->contact.setPrenom(this->ui.firstNameEdit->text().toStdString());
    this->contact.setNom(this->ui.lastNameEdit->text().toStdString());
    this->contact.setMail(this->ui.mailEdit->text().toStdString());
    this->contact.setTel(this->ui.phoneNumberEdit->text().toStdString());
    this->contact.setEntreprise(this->ui.companyNameEdit->text().toStdString());
    //@todo chemin photo avec le pushButton
}
