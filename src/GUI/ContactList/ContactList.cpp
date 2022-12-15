//
// Created by yaon on 30/10/22.
//

#include "ContactList.h"
#include "ui_ContactDeleteDialog.h"
#include "../ContactButton/ContactButton.h"
#include "../ContactModifier/ContactModifier.h"
#include <iostream>

/**
 * Constructeur de la classe ContactList permettant d'afficher tout le contenu de GestionContact.
 * @param parent
 * QWidget parent de l'instance créée.
 */
ContactList::ContactList(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(this->parent);
    QObject::connect(this, SIGNAL(refreshContactList(GestionContact * )),
                     SLOT(showContactList(GestionContact * )));
    QObject::connect(this->ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(createContact()));
    QObject::connect(this->ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChange()));
    QObject::connect(this->ui.dateEdit, SIGNAL(dateChanged(const QDate &)), this, SLOT(searchInListByDate()));
    QObject::connect(this->ui.dateEdit_2, SIGNAL(dateChanged(const QDate &)), this, SLOT(searchInListByDate()));
    this->ui.dateEdit->hide();
    this->ui.dateEdit_2->hide();
    this->ui.dateEdit->setDate(QDate::currentDate());
    this->ui.dateEdit_2->setMinimumDate(this->ui.dateEdit->date());
    QObject::connect(this->ui.lineEdit, SIGNAL(textChanged(
                                                       const QString &)), this, SLOT(searchInListByText(QString)));
}

/**
 * Définit l'instance de GestionContact à stocker dans ContactList et déclenche son affichage.
 * @param gestionContact
 */
void ContactList::setContactList(GestionContact *gestionContact) {
    this->gestionContact = gestionContact;
    emit refreshContactList(this->gestionContact);
}

/**
 * Fonction retournant un pointeur vers l'instance de GestionContact contenue dans la classe.
 * @return
 * Un pointeur de GestionContact.
 */
GestionContact *ContactList::getContactList() {
    return this->gestionContact;
}

/**
 * Fonction permettant d'afficher ContactList en affichant le parent auquel la classe est rattachée.
 */
void ContactList::show() {
    this->parent->show();
}

/**
 * Slot affichant le contenu de la classe GestionContact passée en paramètre du signal reçu.
 * @param gestionContact
 * L'instance de GestionContact que l'on souhaite afficher.
 */
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

/**
 * Slot émettant un signal refreshContactList(GestionContact) avec une liste restreinte au résultat de la recherche passé en paramètre du signal reçu.
 * @param content
 * Contenu de la recherche.
 */
void ContactList::searchInListByText(QString content) {
    if (this->ui.comboBox->currentIndex() == 0) {
        emit refreshContactList(this->gestionContact->rechercheNom(content.toStdString()));
    } else if (this->ui.comboBox->currentIndex() == 1) {
        emit refreshContactList(this->gestionContact->rechercheEntreprise(content.toStdString()));
    }
}

void ContactList::searchInListByDate() {
    this->ui.dateEdit_2->setMinimumDate(this->ui.dateEdit->date());
    if(this->ui.comboBox->currentIndex() == 2){
        tm date_debut, date_fin;
        time_t t = this->ui.dateEdit->dateTime().toSecsSinceEpoch();
        date_debut = *localtime(&t);
        t = this->ui.dateEdit_2->dateTime().toSecsSinceEpoch();
        date_fin = *localtime(&t);
        emit refreshContactList(this->gestionContact->rechercheIntervalleDate(date_debut, date_fin));
    }
}

void ContactList::onComboBoxChange() {
    if(this->ui.comboBox->currentIndex() == 2){
        this->ui.lineEdit->hide();
        this->ui.dateEdit->show();
        this->ui.dateEdit_2->show();
    }else{
        this->ui.lineEdit->show();
        this->ui.dateEdit->hide();
        this->ui.dateEdit_2->hide();
    }
    this->ui.lineEdit->setText("");
    emit refreshContactList(this->gestionContact);
}

/**
 * Slot émettant un signal showContactInfo(Contact) avec pour paramètre le Contact passé en paramètre du signal reçu.
 * @param contact
 * Le Contact à passer dans le signal.
 */
void ContactList::contactClicked(Contact contact) {
    emit showContactInfo(contact);
}

/**
 * Slot ajoutant le contact passé en paramètre du signal reçu à la liste des Contact dans GestionContact et émettant un signal refreshContactList(GestionContact) pour afficher la liste actualisée.
 * @param c
 * Le Contact à ajouter à la liste.
 */
void ContactList::addNewContact(Contact c) {
    this->gestionContact->addContact(c);
    emit refreshContactList(this->gestionContact);
}

/**
 * Slot supprimant le contact passé en paramètre du signal reçu de la liste des Contact dans GestionContact et émettant un signal refreshContactList(GestionContact) pour afficher la liste actualisée.
 * @param c
 * Le Contact à supprimer de la liste.
 */
void ContactList::deleteContact(Contact c) {
    Ui::ContactDeleteDialog *dialogUi = new Ui::ContactDeleteDialog();
    QDialog *dialog = new QDialog(nullptr);
    dialogUi->setupUi(dialog);
    if (dialog->exec()) {
        this->gestionContact->removeContact(c);
        emit refreshContactList(this->gestionContact);
        emit contactDeleted(c);
    }
    dialog->close();
    delete dialogUi;
}

/**
 * Slot déclenchant la procédure de modification du Contact passé en paramètre du signal reçu et émettant un signal refreshContactList(GestionContact) pour afficher la liste actualisée.
 * @param c
 * Le Contact à modifier.
 */
void ContactList::modifyContact(Contact c) {
    ContactModifier *modifier = new ContactModifier(nullptr);
    modifier->setContact(c);
    if (modifier->exec()) {
        this->gestionContact->modifyContact(c, modifier->getContact());
    }
    emit refreshContactList(this->gestionContact);
    emit contactModified(c, modifier->getContact());
    modifier->close();
}

/**
 * Slot émettant un signal lorsque le bouton d'ajout de contact est déclenché.
 */
void ContactList::createContact() {
    emit createButtonClicked();
}