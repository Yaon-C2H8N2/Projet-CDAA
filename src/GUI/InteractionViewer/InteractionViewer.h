#ifndef PROJET_CDAA_INTERACTIONVIEWER_H
#define PROJET_CDAA_INTERACTIONVIEWER_H


#include "../../Interaction/Interaction.h"
#include "ui_InteractionViewer.h"
#include <QObject>
#include <QWidget>

class InteractionViewer : public QWidget {
Q_OBJECT
private:
    Interaction interaction;
public:
    Ui::InteractionViewer ui;

    InteractionViewer(QWidget *parent);

    void setInteraction(Interaction interaction);

signals:
    void interactionDeleted(Interaction);

public slots:

    void onDeleteButtonPressed();
};


#endif //PROJET_CDAA_INTERACTIONVIEWER_H
