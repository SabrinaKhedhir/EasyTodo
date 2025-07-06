#include "GestoreFile.h"
#include <fstream>

void GestoreFile::salvaSuFile(const ListaAttivita& lista, const std::string& nomeFile) {
    std::ofstream outFile(nomeFile);
    for (int i = 0; i < lista.getNumeroAttivita(); ++i) {
        Attivita att = lista.getAttivita(i);
        outFile << att.getDescrizione() << ";" << att.isCompletata() << "\n";
    }
    outFile.close();
}

void GestoreFile::caricaDaFile(ListaAttivita& lista, const std::string& nomeFile) {
    std::ifstream inFile(nomeFile);
    std::string descrizione;
    int completata;

    while (std::getline(inFile, descrizione, ';')) {
        inFile >> completata;
        inFile.ignore(); // per leggere \n
        Attivita att(descrizione);
        if (completata) att.completa();
        lista.aggiungiAttivita(att);
    }

    inFile.close();
}