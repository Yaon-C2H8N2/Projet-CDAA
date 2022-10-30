//
// Created by yaon on 30/10/22.
//

#ifndef PROJET_CDAA_CONTACTBUTTON_H
#define PROJET_CDAA_CONTACTBUTTON_H


#include <QPushButton>
#include "../../Contact/Contact.h"

class ContactButton : public QObject{
Q_OBJECT
private:
    QWidget *parent;
    Contact contact;
public:
    ContactButton(QWidget *parent, Contact contact);
    QPushButton *qPushButton;
signals:
    void clicked(Contact);
private slots:
    void buttonClicked();
};


#endif //PROJET_CDAA_CONTACTBUTTON_H
