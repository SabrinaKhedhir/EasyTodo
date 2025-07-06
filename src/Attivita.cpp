#include "Attivita.h"

Attivita::Attivita(const std::string& desc) : descrizione(desc), completata(false) {}

void Attivita::completa() {
    completata = true;
}

bool Attivita::isCompletata() const {
    return completata;
}

std::string Attivita::getDescrizione() const {
    return descrizione;
}

void Attivita::setDescrizione(const std::string& desc) {
    descrizione = desc;
}