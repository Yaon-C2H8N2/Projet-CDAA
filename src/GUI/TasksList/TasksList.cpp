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
    this->ui.fromDateEdit->setDate(QDate::currentDate());
    this->ui.fromDateEdit->setMinimumDate(QDate::currentDate());
    this->ui.toDateEdit->setMinimumDate(this->ui.fromDateEdit->date());
    QObject::connect(this, SIGNAL(refreshTaskList(GestionTache *)), this, SLOT(showTasksList(GestionTache *)));
    QObject::connect(this->ui.fromDateEdit, SIGNAL(dateChanged(const QDate &)), this, SLOT(miseAJourDepart(QDate)));
    QObject::connect(this->ui.validateButton, SIGNAL(clicked(bool)), this, SLOT(BoutonValider()));
    QObject::connect(this->ui.reinitButton, SIGNAL(clicked(bool)), this, SLOT(BoutonReinit()));
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
    emit refreshTaskList(this->gestionTache);
}

/**
 * Affiche les Tache dans l'UI.
 */
void TasksList::showTasksList(GestionTache *gestionTache) {
    auto children = ui.tasksScrollArea->widget()->findChildren<QLabel *>();
    for (auto i: children) {
        this->ui.tasksScrollArea->widget()->layout()->removeWidget(i);
        i->close();
    }
    for (int i = 0; i < gestionTache->getNbTache(); i++) {
        QString contenu;

        QString dateString = "";
        time_t t = time(nullptr);
        tm today = *localtime(&t);
        if(gestionTache->getTache(i).getDateTache().tm_year == today.tm_year && gestionTache->getTache(i).getDateTache().tm_mday == today.tm_mday && gestionTache->getTache(i).getDateTache().tm_mon == today.tm_mon){
            dateString = "Aujourd'hui";
        }else{
            dateString += QString::fromStdString(to_string(gestionTache->getTache(i).getDateTache().tm_mday));
            dateString += "/";
            dateString += QString::fromStdString(to_string(gestionTache->getTache(i).getDateTache().tm_mon + 1));
            dateString += "/";
            dateString += QString::fromStdString(to_string(gestionTache->getTache(i).getDateTache().tm_year + 1900));
        }
        contenu += "<p>";
        contenu += "<u style=\"color:Blue;\">";
        contenu += dateString + "</u><br/>";

        string tache = gestionTache->getTache(i).getContenu();
        contenu += QString(tache.c_str()) + "</p>";
        ui.verticalLayout_2->addWidget(new QLabel(contenu));
        contenu = "";
    }
}

/**
 * Retourne la liste des Tache contenu par la classe.
 * @return
 * Un pointeur vers une instance de GestionTache.
 */
GestionTache *TasksList::getTasksList() {
    return this->gestionTache;
}

/**
 * Supprime toutes les Tache liée à l'Interaction passée en paramètre.
 * @param interaction
 * L'Interaction dont on supprime les Tache liées.
 */
void TasksList::removeByInteraction(Interaction interaction) {
    //this->gestionTache->removeTache(interaction);
    emit refreshTaskList(this->gestionTache);
}

void TasksList::miseAJourDepart(QDate date) {
    this->ui.toDateEdit->setMinimumDate(date);
}

void TasksList::BoutonValider() {
    GestionTache temp;
    for(int i=0;i<this->gestionTache->getNbTache();i++){
        QDate fromDate = this->ui.fromDateEdit->date();
        QDate toDate = this->ui.toDateEdit->date();
        QDate taskDate(this->gestionTache->getTache(i).getDateTache().tm_year+1900,this->gestionTache->getTache(i).getDateTache().tm_mon+1,this->gestionTache->getTache(i).getDateTache().tm_mday);
        if(fromDate <= taskDate && taskDate <= toDate){
            temp.addTache(this->gestionTache->getTache(i));
        }
    }
    emit refreshTaskList(&temp);
}

void TasksList::BoutonReinit() {
    emit refreshTaskList(this->gestionTache);
}