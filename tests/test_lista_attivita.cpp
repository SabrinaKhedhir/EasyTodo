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

TEST(ListaAttivitaTest, RimuoviAttivitaValida) {
    ListaAttivita lista;
    lista.aggiungiAttivita(Attivita("Attività 1"));
    lista.aggiungiAttivita(Attivita("Attività 2"));
    lista.rimuoviAttivita(0);

    EXPECT_EQ(lista.getNumeroAttivita(), 1);
    EXPECT_EQ(lista.getAttivita(0).getDescrizione(), "Attività 2");
}

TEST(ListaAttivitaTest, RimuoviAttivitaIndiceNonValido) {
    ListaAttivita lista;
    lista.aggiungiAttivita(Attivita("Unica attività"));
    lista.rimuoviAttivita(5);  // indice non valido

    EXPECT_EQ(lista.getNumeroAttivita(), 1);
    EXPECT_EQ(lista.getAttivita(0).getDescrizione(), "Unica attività");
}

TEST(ListaAttivitaTest, OrdinaPerStato) {
    ListaAttivita lista;
    Attivita a1("Non completata");
    Attivita a2("Completata");
    a2.completa();

    lista.aggiungiAttivita(a2);  // Aggiunta prima la completata
    lista.aggiungiAttivita(a1);  // Poi la non completata

    lista.ordinaPerStato();  // Deve invertire l'ordine

    EXPECT_EQ(lista.getAttivita(0).getDescrizione(), "Non completata");
    EXPECT_FALSE(lista.getAttivita(0).isCompletata());

    EXPECT_EQ(lista.getAttivita(1).getDescrizione(), "Completata");
    EXPECT_TRUE(lista.getAttivita(1).isCompletata());
}
