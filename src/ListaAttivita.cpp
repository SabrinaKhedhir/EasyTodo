#include "ListaAttivita.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <algorithm>

void ListaAttivita::aggiungiAttivita(const Attivita& attivita) {
    elenco.push_back(attivita);
    notifica("Attività aggiunta: " + attivita.getDescrizione());
}

void ListaAttivita::mostraAttivita() const {
    for (size_t i = 0; i < elenco.size(); ++i) {
        const Attivita& att = elenco[i];
        std::time_t data = att.getDataCreazione();
        std::tm* tm_info = std::localtime(&data);

        std::ostringstream oss;
        oss << std::put_time(tm_info, "%d/%m/%Y %H:%M");

        std::cout << i << ". " << att.getDescrizione()
           << " [" << (att.isCompletata() ? "Completata" : "Da fare") << "]"
           << " - creata il " << oss.str()
           << " - da fare il " << att.getDataDaFareStringa()
           << "\n";

    }
}

void ListaAttivita::completaAttivita(int indice) {
    if (indice >= 0 && indice < elenco.size()) {
        elenco[indice].completa();
        notifica("Attività completata: " + elenco[indice].getDescrizione());  // ✅ Observer
    }
}

int ListaAttivita::getNumeroAttivita() const {
    return elenco.size();
}

Attivita ListaAttivita::getAttivita(int indice) const {
    return elenco[indice];
}

void ListaAttivita::rimuoviAttivita(int indice) {
    if (indice >= 0 && indice < elenco.size()) {
        std::string desc = elenco[indice].getDescrizione();
        elenco.erase(elenco.begin() + indice);
        notifica("Attività rimossa: " + desc);
    }
}

void ListaAttivita::ordinaPerStato() {
    std::sort(elenco.begin(), elenco.end(), [](const Attivita& a, const Attivita& b) {
        return !a.isCompletata() && b.isCompletata();
    });
}
