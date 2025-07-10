#include "gtest/gtest.h"
#include "../src/GestoreFile.h"
#include <fstream>

TEST(GestoreFileTest, SalvataggioSuFile) {
    ListaAttivita lista;
    Attivita att("Scrivi il test", std::time(nullptr), std::time(nullptr));
    lista.aggiungiAttivita(att);

    std::string filename = "test_output.txt";
    GestoreFile::salvaSuFile(lista, filename);
    std::ifstream file(filename);
    ASSERT_TRUE(file.is_open());

    std::string contenuto;
    std::getline(file, contenuto);
    EXPECT_NE(contenuto.find("Scrivi il test"), std::string::npos);

    file.close();
    std::remove(filename.c_str()); // pulizia dopo test
}
