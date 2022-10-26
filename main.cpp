#include <QApplication>
#include <iostream>
#include "src/Contact/Contact.h"
#include "src/Interaction/Interaction.h"
#include "src/GestionContact/GestionContact.h"
#include "src/GestionTache/GestionTache.h"

int main(int argc, char *argv[]) {
    /*
     * Création des structures de données nécessaires
     */
    GestionContact *listeContact = new GestionContact();
    GestionTache *listeTaches = new GestionTache();

    //création des contacts de test
    for (int i = 0; i < 5; i++) {
        //création du contact
        Contact *c = new Contact();
        c->setPrenom("PrénomTest" + to_string(i + 1));
        c->setNom("NomTest" + to_string(i + 1));
        c->setEntreprise("EntrepriseTest" + to_string(i + 1));
        c->setTel("00 00 00 00 0" + to_string(i + 1));
        c->setMail("mailTest" + to_string(i + 1) + "@domaine.extension");
        c->setCheminPhoto("dummyPicture" + to_string(i + 1) + ".png");
        time_t t = time(nullptr);
        tm dateCreation = *localtime(&t);
        c->setDateCreation(dateCreation);

        //création des intéractions
        Interaction *interaction = new Interaction();
        t = time(nullptr);
        dateCreation = *localtime(&t);
        interaction->setDateInteraction(dateCreation);
        interaction->setContenu(
                "ContenuTest" + to_string(i + 1) + " @todo testTodo" + to_string(i + 1) + " @date 0" +
                to_string(i + 1) + "/01/23");
        c->getInteractions()->addInteraction(*interaction);

        //création des taches
        Tache *tache = new Tache();
        tache->setContenu("ContenuTest" + to_string(i + 1));
        t = time(nullptr);
        t += (1);
        dateCreation = *localtime(&t);
        tache->setDateTache(dateCreation);

        listeContact->addContact(*c);
        listeTaches->addTache(*tache);
    }

    Contact testModif = listeContact->getContact(4);
    testModif.setNom("NomModif");
    listeContact->modifyContact(listeContact->getContact(4), testModif);
    listeContact->removeContact(listeContact->getContact(0));

    cout << "==========================================================================================" << endl;
    cout << "=================================== Liste des contacts ===================================" << endl;
    cout << "==========================================================================================" << endl;
    cout << *listeContact << endl;
    cout << "================= Historique modifications =================" << endl;
    cout << listeContact->getHistoriqueModifs() << endl;
    cout << "==========================================================================================" << endl;
    cout << "==================================== Liste des taches ====================================" << endl;
    cout << "==========================================================================================" << endl;
    cout << *listeTaches << endl;
    cout << listeContact->rechercheNom("NomM");

    delete listeContact;
    delete listeTaches;
    return 0;
}
