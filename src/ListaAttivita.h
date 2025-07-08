#ifndef LISTAATTIVITA_H
#define LISTAATTIVITA_H

#include <vector>
#include "Attivita.h"
#include "Subject.h"

class ListaAttivita : public Subject {
private:
    std::vector<Attivita> elenco;

public:
    void aggiungiAttivita(const Attivita& attivita);
    void mostraAttivita() const;
    void completaAttivita(int indice);
    int getNumeroAttivita() const;
    Attivita getAttivita(int indice) const;

    void rimuoviAttivita(int indice);
    void ordinaPerStato();
};

#endif // LISTAATTIVITA_H
