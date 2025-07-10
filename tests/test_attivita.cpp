#include "gtest/gtest.h"
#include "../src/Attivita.h"

TEST(AttivitaTest, DescrizioneIniziale) {
    Attivita a("Fare esercizi", "10/07/2025 15:00");
    EXPECT_EQ(a.getDescrizione(), "Fare esercizi");
}

TEST(AttivitaTest, StatoIniziale) {
    Attivita a("Studiare", "10/07/2025 16:00");
    EXPECT_FALSE(a.isCompletata());
}

TEST(AttivitaTest, Completamento) {
    Attivita a("Compilare progetto", "10/07/2025 17:00");
    a.completa();
    EXPECT_TRUE(a.isCompletata());

}

TEST(AttivitaTest, CambiaDescrizione) {
    Attivita a("Vecchia descrizione", "10/07/2025 18:00");
    a.setDescrizione("Nuova descrizione");
    EXPECT_EQ(a.getDescrizione(), "Nuova descrizione");
}
