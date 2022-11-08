//
// Created by yaon on 30/10/22.
//

#include <QMenu>
#include <QWidget>
#include <iostream>
#include <QDialog>
#include "ContactInfo.h"

ContactInfo::ContactInfo(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(parent);
    this->ui.scrollArea->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this->ui.scrollArea, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(ShowContextMenu(const QPoint &)));
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

Contact ContactInfo::getContact() {
    return this->contact;
}

void ContactInfo::show() {
    this->parent->show();
}

void ContactInfo::hide() {
    this->parent->hide();
}

void ContactInfo::ShowContextMenu(const QPoint &pos) {
    QMenu contextMenu(tr("Context menu"), this->ui.scrollArea);
    QAction action1("Ajouter interaction", this->ui.scrollArea);

    contextMenu.addAction(&action1);
    contextMenu.exec(this->ui.scrollArea->mapToGlobal(pos));
}
