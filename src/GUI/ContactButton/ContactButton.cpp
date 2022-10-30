//
// Created by yaon on 30/10/22.
//

#include "ContactButton.h"

ContactButton::ContactButton(QWidget *parent, Contact contact){
    this->contact = contact;
    this->parent = parent;
    this->qPushButton = new QPushButton(this->parent);
    qPushButton->setObjectName("contactButton");
    qPushButton->setText(QString::fromStdString(
            this->contact.getPrenom() + " " + this->contact.getNom()));
    QObject::connect(this->qPushButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

void ContactButton::buttonClicked() {
    emit clicked(this->contact);
}