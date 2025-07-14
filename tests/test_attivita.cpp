#include "gtest/gtest.h"
#include "../src/Attivita.h"

TEST(AttivitaTest, DescrizioneIniziale) {
    Attivita a("Fare esercizi", "10/07/2025 10:00");
    EXPECT_EQ(a.getDescrizione(), "Fare esercizi");
}

TEST(AttivitaTest, StatoIniziale) {
    Attivita a("Studiare", "11/07/2025 09:00");
    EXPECT_FALSE(a.isCompletata());
}

TEST(AttivitaTest, Completamento) {
    Attivita a("Compilare progetto", "11/07/2025 14:00");
    a.completa();
    EXPECT_TRUE(a.isCompletata());
}

TEST(AttivitaTest, CambiaDescrizione) {
    Attivita a("Vecchia descrizione", "12/07/2025 08:00");
    a.setDescrizione("Nuova descrizione");
    EXPECT_EQ(a.getDescrizione(), "Nuova descrizione");
}
