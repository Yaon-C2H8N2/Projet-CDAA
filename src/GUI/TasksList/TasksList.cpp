//
// Created by yaon on 30/10/22.
//

#include <QLabel>
#include <iostream>
#include "TasksList.h"

/**
 * Constructeur de la classe TaskList
 * @param parent
 * Le Widget dans lequel afficher l'UI.
 */
TasksList::TasksList(QWidget *parent) {
    this->parent = parent;
    this->ui.setupUi(this->parent);
}

/**
 * Affiche l'UI.
 */
void TasksList::show() {
    this->parent->show();
}

/**
 * Définit la liste des Tache à afficher.
 * @param gestionTache
 * Un pointeur vers une instance de GestionTache contenant les Tache à afficher.
 */
void TasksList::setTasksList(GestionTache *gestionTache) {
    this->gestionTache = gestionTache;
    //todo tri dans l'ordre croissant des tâches
    emit refreshTaskList();
}

/**
 * Affiche les Tache dans l'UI.
 */
void TasksList::showTasksList(){
    for(int i=0;i<this->gestionTache->getNbTache();i++){
        //todo affichage du contenu et du jour de la tache (à voir si il faut pas faire une classe dédiée à ça)
    }
}

/**
 * Retourne la liste des Tache contenu par la classe.
 * @return
 * Un pointeur vers une instance de GestionTache.
 */
GestionTache *TasksList::getTasksList() {
    return this->gestionTache;
    emit refreshTaskList();
}

/**
 * Supprime toutes les Tache liée à l'Interaction passée en paramètre.
 * @param interaction
 * L'Interaction dont on supprime les Tache liées.
 */
void TasksList::removeByInteraction(Interaction interaction) {
    cout << interaction << endl;
    //this->gestionTache->removeTache(interaction);
}

