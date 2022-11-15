//
// Created by yaon on 15/11/22.
//

#ifndef PROJET_CDAA_CONTACTMODIFIER_H
#define PROJET_CDAA_CONTACTMODIFIER_H

#include <QObject>
#include <QDialog>
#include "ui_ContactModifier.h"
#include "../../Contact/Contact.h"

class ContactModifier : public QDialog {
Q_OBJECT
private:
    Contact contact;
    QDialog *parent;
public:
    Ui::Dialog ui;

    ContactModifier(QDialog *parent);

    void setContact(Contact contact);

    Contact getContact();

public slots:

    void validateChanges();
};


#endif //PROJET_CDAA_CONTACTMODIFIER_H
