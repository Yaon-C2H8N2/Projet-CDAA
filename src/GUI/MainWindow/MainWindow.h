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

class MainWindow : public QObject {
Q_OBJECT
private:
    QMainWindow *parent;
public:
    ContactList *contactList;
    TasksList *tasksList;
    Ui::MainWindow ui;

    MainWindow(QMainWindow *parent);

    void show();
};


#endif //PROJET_CDAA_MAINWINDOW_H
