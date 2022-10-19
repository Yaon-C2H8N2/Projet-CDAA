#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

#include <ostream>
#include "../Interaction/Interaction.h"

#include <list>

class GestionInteraction
{
private:
    list<Interaction> listeInteractions;
public:
    void addInteraction(Interaction i);

    void removeInteraction(Interaction i);

    int getNbInteraction();

    Interaction getInteraction(int i);
};

#endif // GESTIONINTERACTION_H
