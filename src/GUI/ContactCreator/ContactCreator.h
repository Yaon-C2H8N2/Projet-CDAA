//
// Created by yaon on 31/10/22.
//

#ifndef PROJET_CDAA_CONTACTCREATOR_H
#define PROJET_CDAA_CONTACTCREATOR_H


#include <QObject>
#include "ui_ContactCreator.h"
#include "../../Contact/Contact.h"

class ContactCreator : public QObject {
Q_OBJECT
private:
    QWidget *parent;
    Contact contact;
public:
    Ui::ContactCreator ui;

    ContactCreator(QWidget *parent);

    void setContact(Contact contact);

    void show();

    void hide();

signals:

private slots:
    void validateFields();
};


#endif //PROJET_CDAA_CONTACTCREATOR_H
