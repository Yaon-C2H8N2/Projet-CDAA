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

    void reset();

    void show();

    void hide();

signals:
    void validateContact(Contact);
private slots:
    void validateFields();
    void validateButtonClicked();
    void cancelButtonClicked();
    void onPicturePushButtonClicked();
};


#endif //PROJET_CDAA_CONTACTCREATOR_H
