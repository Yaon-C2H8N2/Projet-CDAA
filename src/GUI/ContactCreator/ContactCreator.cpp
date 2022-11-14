//
// Created by yaon on 31/10/22.
//

#include <iostream>
#include "ContactCreator.h"

/**
 * Constructeur de la classe ContactCreator permettant de créer un nouveau contact.
 * @param parent
 * QWidget parent de l'instance créée.
 */
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

/**
 * Définit la valeur du Contact stocké dans l'instance de ContactCreator.
 * @param contact
 * Le Contact à définir si on souhaite peupler les champs du ContactCreator avec les informations de ce Contact.
 */
void ContactCreator::setContact(Contact contact) {
    this->contact = contact;
    this->ui.firstNameLineEdit->setText(QString::fromStdString(this->contact.getPrenom()));
    this->ui.lastNameLineEdit->setText(QString::fromStdString(this->contact.getNom()));
    this->ui.companyNameLineEdit->setText(QString::fromStdString(this->contact.getEntreprise()));
    this->ui.phoneNumberLineEdit->setText(QString::fromStdString(this->contact.getTel()));
    this->ui.mailAddressLineEdit->setText(QString::fromStdString(this->contact.getMail()));
}

/**
 * Fonction permettant d'afficher le ContactCreator en affichant le parent auquel il est rattaché.
 */
void ContactCreator::show() {
    this->parent->show();
}

/**
 * Fonction permettant de cacher le ContactCreator en cachant le parent auquel il est rattaché.
 */
void ContactCreator::hide() {
    this->parent->hide();
}

//@todo revoir le concept
/**
 * Slot vérifiant si tous les QLineEdit ne sont pas vides lorsqu'il reçoit un signal. Active ou non le bouton de validation en fonction du résultat.
 */
void ContactCreator::validateFields() {
    auto children = this->parent->findChildren<QLineEdit *>();
    bool notEmpty = true;
    for (auto i: children) {
        if(i->text()=="")notEmpty = false;
    }
    this->ui.validatePushButton->setEnabled(notEmpty);
}

/**
 * Slot qui peuple les informations du Contact stocké en interne et émettant un signal validateContact(Contact) avec ce Contact lorsqu'il reçoit un signal.
 */
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

/**
 * Slot qui réinitialise les informations du Contact stocké en interne et cache le ContactCreator lorsqu'il reçoit un signal.
 */
void ContactCreator::cancelButtonClicked() {
    this->setContact(*new Contact());
    this->hide();
}