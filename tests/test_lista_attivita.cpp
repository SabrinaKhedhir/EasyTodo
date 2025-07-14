#include "gtest/gtest.h"
#include "../src/ListaAttivita.h"

TEST(ListaAttivitaTest, AggiuntaAttivita) {
    ListaAttivita lista;
    std::time_t now = std::time(nullptr);
    Attivita att("Test attività", now, now);
    lista.aggiungiAttivita(att);

    ASSERT_EQ(lista.getNumeroAttivita(), 1);
    EXPECT_EQ(lista.getAttivita(0).getDescrizione(), "Test attività");
}

TEST(ListaAttivitaTest, RimuoviAttivita) {
    ListaAttivita lista;
    std::time_t now = std::time(nullptr);
    Attivita att("Test", now, now);
    lista.aggiungiAttivita(att);
    lista.rimuoviAttivita(0);
    ASSERT_EQ(lista.getNumeroAttivita(), 0);
}
