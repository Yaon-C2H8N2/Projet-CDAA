//
// Created by yaon on 18/10/22.
//

#ifndef PROJET_CDAA_TACHE_H
#define PROJET_CDAA_TACHE_H

#include <string>

using namespace std;

class Tache {
private:
    string nomTache, contenu;
    tm dateTache;
public:
    void setNomTache(string nomTache);

    string getNomTache();

    void setContenu(string contenu);

    string getContenu();

    void setDateTache(tm dateTache);

    tm getDateTache();

    bool operator==(Tache rhs);

    bool operator!=(Tache rhs);
};


#endif //PROJET_CDAA_TACHE_H
