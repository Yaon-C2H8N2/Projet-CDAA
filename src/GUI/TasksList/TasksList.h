//
// Created by yaon on 30/10/22.
//

#ifndef PROJET_CDAA_TASKSLIST_H
#define PROJET_CDAA_TASKSLIST_H

#include <QObject>
#include "ui_TasksList.h"

class TasksList : public QObject{
Q_OBJECT
private:
    QWidget *parent;
public:
    Ui::TasksList ui;

    TasksList(QWidget *parent);

    void show();
};


#endif //PROJET_CDAA_TASKSLIST_H
