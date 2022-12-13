//
// Created by yaon on 29/10/22.
//

#include <iostream>
#include "MainWindow.h"

/**
 * Constructeur de la classe MainWindow permettant d'afficher la fenêtre principale.
 * @param parent
 * QMainWindow dans laquelle réaliser l'affichage.
 */
MainWindow::MainWindow(QMainWindow *parent) {
    this->parent = parent;
    this->ui.setupUi(this->parent);
    this->contactList = new ContactList(this->ui.contactListWidget);
    this->tasksList = new TasksList(this->ui.taskTab);
    this->contactInfo = new ContactInfo(this->ui.contactInfoWidget);
    this->contactCreator = new ContactCreator(this->ui.newContactWidget);

    this->ui.newContactWidget->hide();
    this->contactInfo->hide();

    QObject::connect(contactList, SIGNAL(showContactInfo(Contact)), this, SLOT(showContact(Contact)));
    QObject::connect(this->contactList, SIGNAL(createButtonClicked()), this, SLOT(showNewContact()));
    QObject::connect(this->contactCreator, SIGNAL(validateContact(Contact)), this->contactList,
                     SLOT(addNewContact(Contact)));
    QObject::connect(this->contactCreator, SIGNAL(validateContact(Contact)), this,
                     SLOT(addNewContact(Contact)));
    QObject::connect(this->contactInfo, SIGNAL(interactionDeleted(Interaction)), this,
                     SLOT(onInteractionDelete(Interaction)));
    QObject::connect(this->contactInfo, SIGNAL(interactionAdded(Contact)), this, SLOT(onInteractionAdded(Contact)));
    QObject::connect(this->contactList, SIGNAL(contactModified(Contact, Contact)), this,
                     SLOT(onContactUpdate(Contact, Contact)));
    QObject::connect(this->contactList, SIGNAL(contactDeleted(Contact)), this, SLOT(onContactDeletion(Contact)));
}

/**
 * Fonction permettant d'afficher MainWindow en affichant le parent auquel la classe est rattachée.
 */
void MainWindow::show() {
    this->parent->show();
}

/**
 * Slot affichant le widget ContactCreator contenu dans la MainWindow et cachant le widget ContactInfo contenu dans la MainWindow lorsqu'il reçoit un signal.
 */
void MainWindow::showNewContact() {
    this->contactCreator->reset();
    this->contactCreator->show();
    this->contactInfo->setContact(*new Contact());
    this->contactInfo->hide();
}

/**
 * Slot affichant le widget ContactInfo, avec les informations du Contact passé en paramètre du signal reçu, contenu dans la MainWindow et cachant le widget ContactCreator contenu dans la MainWindow.
 * @param contact
 * Le Contact dont on souhaite afficher les informations.
 */
void MainWindow::showContact(Contact contact) {
    this->contactCreator->hide();
    if (contact != contactInfo->getContact())contactInfo->setContact(contact);
    else {
        contactInfo->setContact(*new Contact());
        contactInfo->hide();
    }
}

/**
 * Slot supprimant les Tache liée à une Interaction lors de la suppression d'une Interaction.
 * @param interaction
 * L'Interaction supprimée.
 */
void MainWindow::onInteractionDelete(Interaction interaction) {
    Contact contact = this->contactInfo->getContact();
    contact.getInteractions()->removeInteraction(interaction);
    this->contactList->getContactList()->modifyContact(this->contactInfo->getContact(), contact);
    this->contactInfo->setContact(contact);
    this->tasksList->removeByInteraction(interaction);
    this->contactList->refreshContactList(this->contactList->getContactList());
    this->interfaceBaseDeDonnee->removeInteraction(contact, interaction);
    this->interfaceBaseDeDonnee->removeTache(contact, interaction);
}

/**
 * Slot mettant à jour dans la base de données les infos d'un Contact.
 * @param c1
 * Le Contact à update.
 * @param c2
 * Les nouvelles infos du Contact.
 */
void MainWindow::onContactUpdate(Contact c1, Contact c2) {
    this->interfaceBaseDeDonnee->updateContact(c1, c2);
    if (this->contactInfo->getContact() == c1) {
        this->contactInfo->setContact(c2);
    }
}

/**
 * Slot ajoutant un Contact à la base de données.
 * @param contact
 * Le Contact à ajouter.
 */
void MainWindow::addNewContact(Contact contact) {
    this->interfaceBaseDeDonnee->insertContact(contact);
}

/**
 * Slot supprimant un Contact de la base de données.
 * @param c
 * Le Contact à supprimer.
 */
void MainWindow::onContactDeletion(Contact c) {
    this->interfaceBaseDeDonnee->removeContact(c);
}

/**
 * Slot rafraîchissant l'affichage des infos du Contact lors de l'ajout d'une intéraction.
 * @param c
 * Le Contact dont l'affichage doit être rafraîchit.
 */
void MainWindow::onInteractionAdded(Contact c) {
    //TODO parser l'intéraction (dernière intéraction de la liste d'intéractions du contact)
    cout << "Interaction à parser :" << endl << c.getInteractions()->getInteraction(c.getInteractions()->getNbInteraction()-1) << endl;
    this->contactList->getContactList()->modifyContact(c, c);
    this->contactList->refreshContactList(this->contactList->getContactList());
    this->interfaceBaseDeDonnee->ajoutInteraction(c, c.getInteractions()->getInteraction(c.getInteractions()->getNbInteraction()-1));
}
