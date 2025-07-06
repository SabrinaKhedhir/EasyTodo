#include "gtest/gtest.h"
#include "../src/Attivita.h"

TEST(AttivitaTest, DescrizioneIniziale) {
    Attivita a("Fare esercizi");
    EXPECT_EQ(a.getDescrizione(), "Fare esercizi");
}

TEST(AttivitaTest, StatoIniziale) {
    Attivita a("Studiare");
    EXPECT_FALSE(a.isCompletata());
}

TEST(AttivitaTest, Completamento) {
    Attivita a("Compilare progetto");
    a.completa();
    EXPECT_TRUE(a.isCompletata());
}

TEST(AttivitaTest, CambiaDescrizione) {
    Attivita a("Vecchia descrizione");
    a.setDescrizione("Nuova descrizione");
    EXPECT_EQ(a.getDescrizione(), "Nuova descrizione");
}