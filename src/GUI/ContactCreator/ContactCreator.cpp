//
// Created by yaon on 31/10/22.
//

#include <iostream>
#include "ContactCreator.h"

ContactCreator::ContactCreator(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(parent);
    auto children = this->parent->findChildren<QLineEdit *>();
    for (auto i: children) {
        QObject::connect(i,SIGNAL(textChanged(const QString &)),this,SLOT(validateFields()));
    }
}

void ContactCreator::setContact(Contact contact) {
    this->contact = contact;
    //@todo peupler les champs de l'UI avec les infos du contact
}

void ContactCreator::show() {
    this->parent->show();
}

void ContactCreator::hide() {
    this->parent->hide();
}

//@todo revoir le concept
void ContactCreator::validateFields() {
    auto children = this->parent->findChildren<QLineEdit *>();
    bool notEmpty = true;
    for (auto i: children) {
        if(i->text()=="")notEmpty = false;
    }
    this->ui.pushButton_3->setEnabled(notEmpty);
}
