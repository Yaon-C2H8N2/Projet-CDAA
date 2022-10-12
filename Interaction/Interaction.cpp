//
// Created by yaon on 12/10/22.
//

#include <ctime>
#include "Interaction.h"

using namespace std;

Interaction::Interaction() {
    time_t t = time(0);
    dateInteraction = localtime(&t);
}

Interaction::~Interaction() {
}

void Interaction::setContenu(string contenu) {
    this->contenu = contenu;
}

string Interaction::getContenu() {
    return this->contenu;
}

string Interaction::dateToString() const {
    string res = "";
    res += to_string(this->dateInteraction->tm_mday);
    res += "/";
    res += to_string(1 + this->dateInteraction->tm_mon);
    res += "/";
    res += to_string(1900 + this->dateInteraction->tm_year);
    return res;
}

ostream &operator<<(ostream &os, const Interaction &interaction) {
    os << "contenu: " << interaction.contenu << "\ndateInteraction: " << interaction.dateToString();
    return os;
}
