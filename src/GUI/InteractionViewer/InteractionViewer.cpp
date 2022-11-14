//
// Created by yaon on 14/11/22.
//

#include "InteractionViewer.h"

InteractionViewer::InteractionViewer(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(parent);
}

void InteractionViewer::setInteraction(Interaction interaction) {
    this->interaction = interaction;
    this->ui.textEdit->setText(QString::fromStdString(interaction.getContenu()));
    this->ui.dateLabel->setText(QString::fromStdString(to_string(interaction.getDateInteraction()->tm_mday) + "/" +
                                                       to_string(interaction.getDateInteraction()->tm_mon) + "/" +
                                                       to_string(interaction.getDateInteraction()->tm_year)));
}

Interaction InteractionViewer::getInteraction() {
    return this->interaction;
}

void InteractionViewer::show() {
    this->parent->show();
}

void InteractionViewer::hide() {
    this->parent->hide();
}
