//
// Created by yaon on 29/10/22.
//

#ifndef PROJET_CDAA_MAINWINDOW_H
#define PROJET_CDAA_MAINWINDOW_H


#include <QObject>
#include <QMainWindow>
#include "ui_MainWindow.h"
#include "../ContactList/ContactList.h"
#include "../TasksList/TasksList.h"
#include "../ContactInfo/ContactInfo.h"
#include "../ContactCreator/ContactCreator.h"
#include "../../InterfaceBaseDeDonnee/InterfaceBaseDeDonnee.h"

class MainWindow : public QObject {
Q_OBJECT
private:
    QMainWindow *parent;
public:
    ContactList *contactList;
    TasksList *tasksList;
    ContactInfo *contactInfo;
    ContactCreator *contactCreator;
    InterfaceBaseDeDonnee *interfaceBaseDeDonnee;
    Ui::MainWindow ui;

    MainWindow(QMainWindow *parent);

    void show();

private slots:

    void showNewContact();

    void showContact(Contact);

    void onInteractionDelete(Interaction);

    void onContactUpdate(Contact, Contact);
};


#endif //PROJET_CDAA_MAINWINDOW_H
