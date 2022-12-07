//
// Created by yaon on 14/11/22.
//

#ifndef PROJET_CDAA_INTERACTIONVIEWER_H
#define PROJET_CDAA_INTERACTIONVIEWER_H

#include <QWidget>
#include <QObject>
#include "../../Interaction/Interaction.h"
#include "ui_InteractionViewer.h"

class InteractionViewer : public QObject {
Q_OBJECT
private:
    QWidget *parent;
    Interaction interaction;
public:
    Ui::InteractionViewer ui;

    InteractionViewer(QWidget *parent);

    void setInteraction(Interaction interaction);

    void show();

signals:

    void interactionDeleted(Interaction);

public slots:

    void onInteractionDelete();
};


#endif //PROJET_CDAA_INTERACTIONVIEWER_H
