//
// Created by yaon on 29/10/22.
//

#include "MainWindow.h"


MainWindow::MainWindow(QMainWindow *parent) {
    this->parent = parent;
    this->ui.setupUi(this->parent);
    this->contactList = new ContactList(this->ui.contactListWidget);
    this->tasksList = new TasksList(this->ui.calendarTab);
}

void MainWindow::show() {
    this->parent->show();
}