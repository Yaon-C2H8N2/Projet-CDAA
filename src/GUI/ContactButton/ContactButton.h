#ifndef PROJET_CDAA_CONTACTBUTTON_H
#define PROJET_CDAA_CONTACTBUTTON_H


#include <QPushButton>
#include "../../Contact/Contact.h"

class ContactButton : public QPushButton {
Q_OBJECT
private:
    QWidget *parent;
    Contact contact;
public:
    ContactButton(QWidget *parent, Contact contact);
signals:

    void clicked(Contact);

    void modifyContact(Contact);

    void deleteContact(Contact);

private slots:

    void buttonClicked();

    void ShowContextMenu(const QPoint &);

    void modifcationRequested();

    void deletionRequested();
};


#endif //PROJET_CDAA_CONTACTBUTTON_H
