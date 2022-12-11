//
// Created by yaon on 30/10/22.
//

#ifndef PROJET_CDAA_TASKSLIST_H
#define PROJET_CDAA_TASKSLIST_H

#include <QObject>
#include "ui_TasksList.h"
#include "../../GestionTache/GestionTache.h"

class TasksList : public QObject {
Q_OBJECT
private:
    QWidget *parent;
    GestionTache *gestionTache;
public:
    Ui::TasksList ui;

    TasksList(QWidget *parent);

    void setTasksList(GestionTache *tasksList);

    GestionTache *getTasksList();

    void show();

signals:

    void refreshTaskList(GestionTache *);

public slots:

    void showTasksList(GestionTache *);

    void removeByInteraction(Interaction);

    void miseAJourDepart(QDate);

    void BoutonValider();

    void BoutonReinit();
};


#endif //PROJET_CDAA_TASKSLIST_H
