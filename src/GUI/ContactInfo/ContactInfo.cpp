#include <QMenu>
#include <QWidget>
#include <iostream>
#include <QDialog>
#include "ContactInfo.h"
#include "../InteractionViewer/InteractionViewer.h"
#include "ui_InteractionCreator.h"

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
    QObject::connect(this->ui.scrollArea, SIGNAL(customContextMenuRequested(const QPoint &)),
                     this, SLOT(ShowContextMenu(const QPoint &)));
    QObject::connect(this, SIGNAL(refreshContactInfo()), this, SLOT(onRefreshContactInfo()));
}

/**
 * Définit la valeur du Contact stocké dans l'instance de ContactInfo.
 * @param contact
 * Le Contact à définir si on souhaite peupler les champs de ContactInfo avec les informations de ce Contact.
 */
void ContactInfo::setContact(Contact contact) {
    this->contact = contact;
    emit refreshContactInfo();
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
    QObject::connect(&action1, SIGNAL(triggered(bool)), this, SLOT(onInteractionCreatorRequest()));
    contextMenu.exec(this->ui.scrollArea->mapToGlobal(pos));
}

/**
 * Slot faisant remonter un signal signalisant la suppression d'une Interaction.
 * @param interaction
 * L'Interaction supprimée.
 */
void ContactInfo::onInteractionDelete(Interaction interaction) {
    emit interactionDeleted(interaction);
}

/**
 * Slot appelé lorsque l'on souhaite rafraîchir les informations du Contact affiché dans le GUI
 */
void ContactInfo::onRefreshContactInfo() {
    this->ui.nameLabel->setText(QString::fromStdString(contact.getPrenom() + " " + contact.getNom()));
    this->ui.companyNameLabel->setText(QString::fromStdString(contact.getEntreprise()));
    this->ui.phoneNumberLabel->setText(QString::fromStdString(contact.getTel()));
    this->ui.mailAddressLabel->setText(QString::fromStdString(contact.getMail()));
    QIcon icon(QString::fromStdString(contact.getCheminPhoto()));
    this->ui.photoButton->setIcon(icon);
    this->ui.photoButton->setIconSize(QSize(150, 150));
    this->ui.creationDateLabel->setText(QString::fromStdString(
            to_string(contact.getDateCreation().tm_mday) + "/" + to_string(contact.getDateCreation().tm_mon + 1) + "/" +
            to_string(contact.getDateCreation().tm_year + 1900)));
    auto children = ui.scrollArea->widget()->findChildren<QWidget *>();
    for (auto i: children) {
        ui.scrollArea->widget()->layout()->removeWidget(i);
        i->close();
    }
    for (int i = 0; i < this->contact.getInteractions()->getNbInteraction(); i++) {
        InteractionViewer *interactionViewer = new InteractionViewer(this->ui.scrollAreaWidgetContents);
        this->ui.scrollAreaWidgetContents->layout()->addWidget(interactionViewer);
        interactionViewer->setInteraction(this->contact.getInteractions()->getInteraction(i));
        QObject::connect(interactionViewer, SIGNAL(interactionDeleted(Interaction)), this,
                         SLOT(onInteractionDelete(Interaction)));
    }
    this->show();
}

/**
 * Slot affichant la fenêtre de dialogue permettant de créer une nouvelle Interaction.
 */
void ContactInfo::onInteractionCreatorRequest() {
    Ui::InteractionCreator *dialogUi = new Ui::InteractionCreator();
    QDialog *dialog = new QDialog(nullptr);
    dialogUi->setupUi(dialog);
    dialogUi->titleLabel->setText(QString::fromStdString(
            "Ajout d'intéraction avec " + this->contact.getPrenom() + " " + this->contact.getNom()));
    if (dialog->exec()) {
        Interaction interaction;
        interaction.setContenu(dialogUi->textEdit->toPlainText().toStdString());
        time_t t = time(nullptr);
        tm date = *localtime(&t);
        interaction.setDateInteraction(date);
        this->contact.getInteractions()->addInteraction(interaction);
        emit refreshContactInfo();
        emit interactionAdded(this->contact);
    }
    dialog->close();
    delete dialogUi;
}
