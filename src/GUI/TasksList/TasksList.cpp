//
// Created by yaon on 30/10/22.
//

#include "TasksList.h"

TasksList::TasksList(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(this->parent);
}

void TasksList::show() {
    this->parent->show();
}