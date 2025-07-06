#include "gtest/gtest.h"
#include "../src/ListaAttivita.h"

TEST(ListaAttivitaTest, AggiuntaAttivita) {
    ListaAttivita lista;
    lista.aggiungiAttivita(Attivita("Studiare"));
    EXPECT_EQ(lista.getNumeroAttivita(), 1);
    EXPECT_EQ(lista.getAttivita(0).getDescrizione(), "Studiare");
}

TEST(ListaAttivitaTest, CompletaAttivitaValida) {
    ListaAttivita lista;
    lista.aggiungiAttivita(Attivita("Fare la spesa"));
    lista.completaAttivita(0);
    EXPECT_TRUE(lista.getAttivita(0).isCompletata());
}

TEST(ListaAttivitaTest, CompletaAttivitaIndiceNonValido) {
    ListaAttivita lista;
    lista.aggiungiAttivita(Attivita("Andare in palestra"));
    lista.completaAttivita(1); // indice fuori limite
    EXPECT_FALSE(lista.getAttivita(0).isCompletata()); // deve rimanere non completata
}