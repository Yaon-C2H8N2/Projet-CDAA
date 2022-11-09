//
// Created by yaon on 30/10/22.
//

#include <QMenu>
#include "ContactButton.h"

ContactButton::ContactButton(QWidget *parent, Contact contact) : QPushButton() {
    this->contact = contact;
    this->parent = parent;
    this->setObjectName("contactButton");
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setText(QString::fromStdString(
            this->contact.getPrenom() + " " + this->contact.getNom()));
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
                     this, SLOT(ShowContextMenu(const QPoint &)));
}

void ContactButton::buttonClicked() {
    emit clicked(this->contact);
}

void ContactButton::ShowContextMenu(const QPoint &pos) {
    QMenu contextMenu(tr("Context menu"), this);
    QAction action1("Modifier", this);
    QObject::connect(&action1, SIGNAL(triggered()), this, SLOT(modifcationRequested()));
    QAction action2("Supprimer", this);
    QObject::connect(&action2, SIGNAL(triggered()), this, SLOT(deletionRequested()));

    contextMenu.addAction(&action1);
    contextMenu.addAction(&action2);
    contextMenu.exec(this->mapToGlobal(pos));
}

void ContactButton::modifcationRequested() { emit modifyContact(this->contact); }

void ContactButton::deletionRequested() { emit deleteContact(this->contact); }