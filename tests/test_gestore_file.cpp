#include "gtest/gtest.h"
#include "../src/GestoreFile.h"
#include <fstream>
#include <cstdio> // per std::remove

TEST(GestoreFileTest, SalvataggioECaricamento) {
    ListaAttivita lista;
    lista.aggiungiAttivita(Attivita("Comprare il pane"));
    lista.aggiungiAttivita(Attivita("Studiare C++"));
    lista.completaAttivita(1);

    std::string nomeFile = "test_todo.txt";

    // Salva su file
    GestoreFile::salvaSuFile(lista, nomeFile);

    // Carica da file in una nuova lista
    ListaAttivita caricata;
    GestoreFile::caricaDaFile(caricata, nomeFile);

    EXPECT_EQ(caricata.getNumeroAttivita(), 2);
    EXPECT_EQ(caricata.getAttivita(0).getDescrizione(), "Comprare il pane");
    EXPECT_FALSE(caricata.getAttivita(0).isCompletata());
    EXPECT_EQ(caricata.getAttivita(1).getDescrizione(), "Studiare C++");
    EXPECT_TRUE(caricata.getAttivita(1).isCompletata());

    std::remove(nomeFile.c_str()); // cancella file dopo il test
}