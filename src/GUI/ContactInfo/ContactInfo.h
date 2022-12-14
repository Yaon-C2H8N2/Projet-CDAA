#ifndef PROJET_CDAA_CONTACTINFO_H
#define PROJET_CDAA_CONTACTINFO_H


#include <QObject>
#include "ui_ContactInfo.h"
#include "../../Contact/Contact.h"

class ContactInfo : public QObject {
Q_OBJECT
private:
    QWidget *parent;
    Contact contact;
public:
    Ui::ContactInfo ui;

    ContactInfo(QWidget *parent);

    void setContact(Contact contact);

    Contact getContact();

    void show();

    void hide();

signals:

    void interactionDeleted(Interaction);

    void interactionAdded(Contact);

    void refreshContactInfo();

public slots:

    void onRefreshContactInfo();

    void ShowContextMenu(const QPoint &);

    void onInteractionDelete(Interaction);

    void onInteractionCreatorRequest();
};


#endif //PROJET_CDAA_CONTACTINFO_H
