#include "gtest/gtest.h"
#include "../src/GestoreFile.h"
#include <fstream>
#include <ctime>

TEST(GestoreFileTest, SalvataggioECaricamento) {
    ListaAttivita lista;
    lista.aggiungiAttivita(Attivita("Comprare il pane", "10/07/2025 10:00"));
    lista.aggiungiAttivita(Attivita("Studiare C++", "11/07/2025 09:30"));

    std::string filename = "test_output.txt";
    GestoreFile::salvaSuFile(lista, filename);

    std::ifstream file(filename);
    ASSERT_TRUE(file.is_open());

    std::string contenuto;
    std::getline(file, contenuto);
    EXPECT_NE(contenuto.find("Comprare il pane"), std::string::npos);

    file.close();
    std::remove(filename.c_str()); // pulizia
}
