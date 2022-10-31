//
// Created by yaon on 29/10/22.
//

#include <iostream>
#include "MainWindow.h"


MainWindow::MainWindow(QMainWindow *parent) {
    this->parent = parent;
    this->ui.setupUi(this->parent);
    this->contactList = new ContactList(this->ui.contactListWidget);
    this->tasksList = new TasksList(this->ui.calendarTab);
    this->contactInfo = new ContactInfo(this->ui.contactInfoWidget);
    this->contactCreator = new ContactCreator(this->ui.newContactWidget);

    this->ui.newContactWidget->hide();
    this->contactInfo->hide();

    QObject::connect(contactList, SIGNAL(showContactInfo(Contact)), this, SLOT(showContact(Contact)));
    //@todo à remplacer par un signal emit par contactList
    QObject::connect(this->contactList->ui.pushButton, SIGNAL(clicked()), this, SLOT(showNewContact()));
}

void MainWindow::show() {
    this->parent->show();
}

void MainWindow::showNewContact() {
    this->contactCreator->show();
    contactInfo->setContact(*new Contact());
    contactInfo->hide();
}

void MainWindow::showContact(Contact contact) {
    this->contactCreator->hide();
    if (contact != contactInfo->getContact())contactInfo->setContact(contact);
    else {
        contactInfo->setContact(*new Contact());
        contactInfo->hide();
    }
}