//
// Created by yaon on 14/11/22.
//

#include <iostream>
#include "InteractionViewer.h"

InteractionViewer::InteractionViewer(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(parent);
    //connect du bouton
    QObject::connect(this->ui.deleteButton, SIGNAL(clicked(bool)), this, SLOT(this->onInteractionDelete()));
}

void InteractionViewer::setInteraction(Interaction interaction) {
    this->interaction = interaction;
    this->ui.textEdit->setText(QString::fromStdString(interaction.getContenu()));
    this->ui.dateLabel->setText(
            QString::fromStdString("Intéraction du " + to_string(interaction.getDateInteraction()->tm_mday) + "/" +
                                   to_string(interaction.getDateInteraction()->tm_mon + 1) + "/" +
                                   to_string(interaction.getDateInteraction()->tm_year + 1900)));
}

void InteractionViewer::show() {
    this->parent->show();
}

void InteractionViewer::onInteractionDelete() {
    cout << "slot called" << endl;
    exit(0);
    //emit interactionDeleted(this->interaction);
}
