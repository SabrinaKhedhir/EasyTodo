#include <iostream>
#include "ListaAttivita.h"

void ListaAttivita::aggiungiAttivita(const Attivita& attivita) {
    elenco.push_back(attivita);
}

void ListaAttivita::mostraAttivita() const {
    for (size_t i = 0; i < elenco.size(); ++i) {
        std::cout << i << ". " << elenco[i].getDescrizione()
                  << " [" << (elenco[i].isCompletata() ? "Completata" : "Da fare") << "]\n";
    }
}

void ListaAttivita::completaAttivita(int indice) {
    if (indice >= 0 && indice < elenco.size()) {
        elenco[indice].completa();
    }
}

int ListaAttivita::getNumeroAttivita() const {
    return elenco.size();
}

Attivita ListaAttivita::getAttivita(int indice ) const {
    return elenco[indice];
}