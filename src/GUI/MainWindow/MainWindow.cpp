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