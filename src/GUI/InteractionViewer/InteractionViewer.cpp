//
// Created by yaon on 07/12/22.
//

#include <iostream>
#include "InteractionViewer.h"

/**
 * Constructeur de la classe InteractionViewer.
 * @param parent
 * Le Widget parent de la classe.
 */
InteractionViewer::InteractionViewer(QWidget *parent) : QWidget() {
    this->ui.setupUi(this);
}

/**
 * Définit l'Interaction à afficher dans le Widget.
 * @param interaction
 * Une instance d'Interaction dont on souhaite afficher le contenu et la date.
 */
void InteractionViewer::setInteraction(Interaction interaction) {
    this->interaction = interaction;
    this->ui.textEdit->setText(QString::fromStdString(interaction.getContenu()));
    this->ui.textEdit->setReadOnly(true);
    this->ui.dateLabel->setText(QString::fromStdString(
            to_string(interaction.getDateInteraction()->tm_mday) + "/" +
            to_string(interaction.getDateInteraction()->tm_mon + 1) + "/" +
            to_string(interaction.getDateInteraction()->tm_year + 1900)));
    QObject::connect(this->ui.deleteButton, SIGNAL(clicked(bool)), this, SLOT(onDeleteButtonPressed()));
}

/**
 * Slot émettant un signal lorsque le bouton de suppression est déclenché.
 */
void InteractionViewer::onDeleteButtonPressed() {
    emit interactionDeleted(this->interaction);
}