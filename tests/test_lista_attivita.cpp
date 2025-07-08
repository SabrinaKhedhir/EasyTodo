#include "gtest/gtest.h"
#include "../src/ListaAttivita.h"

TEST(ListaAttivitaTest, AggiuntaAttivita) {
    ListaAttivita lista;
    Attivita att("Test attività", std::time(nullptr), std::time(nullptr));
    lista.aggiungiAttivita(att);

    ASSERT_EQ(lista.getNumeroAttivita(), 1);
    EXPECT_EQ(lista.getAttivita(0).getDescrizione(), "Test attività");
}

TEST(ListaAttivitaTest, RimuoviAttivita) {
    ListaAttivita lista;
    Attivita att("Test", std::time(nullptr), std::time(nullptr));
    lista.aggiungiAttivita(att);
    lista.rimuoviAttivita(0);
    ASSERT_EQ(lista.getNumeroAttivita(), 0);
}
