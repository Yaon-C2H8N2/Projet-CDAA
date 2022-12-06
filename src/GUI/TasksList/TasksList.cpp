//
// Created by yaon on 30/10/22.
//

#include <QLabel>
#include <iostream>
#include "TasksList.h"

TasksList::TasksList(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(this->parent);
}

void TasksList::show() {
    this->parent->show();
}

void TasksList::setTasksList(GestionTache *gestionTache) {
    this->gestionTache = gestionTache;
    //todo tri dans l'ordre croissant des tâches
    emit refreshTaskList();
}

void TasksList::showTasksList(){
    for(int i=0;i<this->gestionTache->getNbTache();i++){
        //todo affichage du contenu et du jour de la tache (à voir si il faut pas faire une classe dédiée à ça)
    }
}

GestionTache *TasksList::getTasksList() {
    return this->gestionTache;
    emit refreshTaskList();
}

void TasksList::removeByInteraction(Interaction interaction) {
    cout << interaction << endl;
    this->gestionTache->removeTache(interaction);
}

