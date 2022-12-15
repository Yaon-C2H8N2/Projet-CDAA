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
    string pictureFilePath;
    QDialog *parent;
public:
    Ui::Dialog ui;

    ContactModifier(QDialog *parent);

    void setContact(Contact contact);

    Contact getContact();

public slots:

    void validateChanges();

    void onPicturePushButtonClicked();
};


#endif //PROJET_CDAA_CONTACTMODIFIER_H
