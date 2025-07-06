#ifndef LISTAATTIVITA_H
#define LISTAATTIVITA_H

#include <vector>
#include "Attivita.h"

class ListaAttivita {
private:
    std::vector<Attivita> elenco;

public:
    void aggiungiAttivita(const Attivita& attivita);
    void mostraAttivita() const;
    void completaAttivita(int indice);
    int getNumeroAttivita() const;
    Attivita getAttivita(int indice) const ;
};

#endif // LISTAATTIVITA_H