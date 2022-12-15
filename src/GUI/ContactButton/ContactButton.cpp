//
// Created by yaon on 30/10/22.
//

#include <QMenu>
#include "ContactButton.h"

/**
 * Constructeur de la classe ContactButton permettant d'associer un QPushButton et un Contact.
 * @param parent
 * QWidget parent de l'instance créée.
 * @param contact
 * Le Contact à associer au ContactButton.
 */
ContactButton::ContactButton(QWidget *parent, Contact contact) : QPushButton() {
    this->contact = contact;
    this->parent = parent;
    this->setObjectName("contactButton");
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setText(QString::fromStdString(
            this->contact.getPrenom() + " " + this->contact.getNom()));
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->setToolTip("Clic Droit pour modifier ou supprimer le contact");
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
                     this, SLOT(ShowContextMenu(const QPoint &)));
}

/**
 * Slot émettant un signal clicked(Contact) lorsqu'il reçoit un signal. Le Contact émit est le Contact associé au ContactButton
 */
void ContactButton::buttonClicked() {
    emit clicked(this->contact);
}

/**
 * Slot faisant apparaître un menu contextuel "custom" lorsqu'il reçoit un signal.
 * @param pos
 * La position où faire apparaître le menu contextuel.
 */
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

/**
 * Slot émettant un signal modifyContact(Contact) lorsqu'il reçoit un signal. Le Contact émit est le Contact associé au ContactButton.
 */
void ContactButton::modifcationRequested() { emit modifyContact(this->contact); }

/**
 * Slot émettant un signal deleteContact(Contact) lorsqu'il reçoit un signal. Le Contact émit est le Contact associé au ContactButton.
 */
void ContactButton::deletionRequested() { emit deleteContact(this->contact); }