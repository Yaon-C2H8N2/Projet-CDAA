//
// Created by yaon on 30/10/22.
//

#include <QMenu>
#include <QWidget>
#include <iostream>
#include <QDialog>
#include "ContactInfo.h"
#include "../InteractionViewer/InteractionViewer.h"

/**
 * Constructeur de la classe ContactInfo permettant d'afficher les informations relatives à un Contact.
 * @param parent
 * QWidget parent de l'instance créée.
 */
ContactInfo::ContactInfo(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(parent);
    this->ui.scrollAreaWidgetContents->setLayout(new QVBoxLayout(ui.scrollAreaWidgetContents));
    this->ui.scrollArea->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this->ui.scrollArea, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(ShowContextMenu(const QPoint &)));
}

/**
 * Définit la valeur du Contact stocké dans l'instance de ContactInfo.
 * @param contact
 * Le Contact à définir si on souhaite peupler les champs de ContactInfo avec les informations de ce Contact.
 */
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
    //@todo supprimer les anciennes interactions affichées si il y en a
    for (int i = 0; i < this->contact.getInteractions()->getNbInteraction(); i++) {
        QWidget *widget = new QWidget(this->ui.scrollAreaWidgetContents);
        InteractionViewer interactionViewer(widget);
        interactionViewer.setInteraction(this->contact.getInteractions()->getInteraction(i));
        this->ui.scrollAreaWidgetContents->layout()->addWidget(widget);
        widget->show();
    }
    this->show();
}

/**
 * Retourne le Contact stocké au sein de ContactInfo.
 * @return
 * Une instance de Contact.
 */
Contact ContactInfo::getContact() {
    return this->contact;
}

/**
 * Fonction permettant d'afficher ContactInfo en affichant le parent auquel la classe est rattachée.
 */
void ContactInfo::show() {
    this->parent->show();
}

/**
 * Fonction permettant d'afficher ContactInfo en affichant le parent auquel la classe est rattachée.
 */
void ContactInfo::hide() {
    this->parent->hide();
}

/**
 * Slot faisant apparaître un menu contextuel "custom" lorsqu'il reçoit un signal.
 * @param pos
 * La position où faire apparaître le menu contextuel.
 */
void ContactInfo::ShowContextMenu(const QPoint &pos) {
    QMenu contextMenu(tr("Context menu"), this->ui.scrollArea);
    QAction action1("Ajouter interaction", this->ui.scrollArea);

    contextMenu.addAction(&action1);
    contextMenu.exec(this->ui.scrollArea->mapToGlobal(pos));
}
