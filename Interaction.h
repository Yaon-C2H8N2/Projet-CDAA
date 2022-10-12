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
    tm *dateInteraction;
public:
    Interaction();

    ~Interaction();

    void setContenu(string contenu);

    string getContenu();

    string dateToString() const;

    friend ostream &operator<<(ostream &os, const Interaction &interaction);
};


#endif //PROJET_CDAA_INTERACTION_H
