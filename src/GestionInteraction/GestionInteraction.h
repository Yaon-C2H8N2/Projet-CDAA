//
// Created by yaon on 18/10/22.
//

#ifndef PROJET_CDAA_GESTIONINTERACTION_H
#define PROJET_CDAA_GESTIONINTERACTION_H


#include "../Interaction/Interaction.h"

class GestionInteraction {
private:
    list<Interaction> listeInteraction;
public:
    void addInteraction(Interaction i);

    void removeInteraction(Interaction i);

    int getNbInteraction();

    Interaction getInteraction(int i);
};


#endif //PROJET_CDAA_GESTIONINTERACTION_H
