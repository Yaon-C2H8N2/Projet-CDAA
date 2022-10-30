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
    contactInfo->hide();
    QObject::connect(contactList, SIGNAL(showContactInfo(Contact)), this, SLOT(showContact(Contact)));
}

void MainWindow::show() {
    this->parent->show();
}

void MainWindow::showContact(Contact contact) {
    if(contact!=contactInfo->getContact())contactInfo->setContact(contact);
    else contactInfo->hide();
}