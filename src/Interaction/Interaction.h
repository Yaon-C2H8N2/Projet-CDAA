//
// Created by yaon on 12/10/22.
//

#ifndef PROJET_CDAA_INTERACTION_H
#define PROJET_CDAA_INTERACTION_H


#include <string>
#include <ostream>

using namespace std;

class Interaction {
private:
    string contenu;
    tm dateInteraction;

    string dateToString() const;

public:
    void setContenu(string contenu);

    string getContenu();

    void setDateInteraction(tm dateInteraction);

    tm *getDateInteraction();

    bool operator==(Interaction rhs);

    bool operator!=(Interaction rhs);

    friend ostream &operator<<(ostream &os, const Interaction &interaction);
};


#endif //PROJET_CDAA_INTERACTION_H
