#include "GestoreFile.h"
#include <fstream>
#include <sstream>
#include <iomanip>

void GestoreFile::salvaSuFile(const ListaAttivita& lista, const std::string& nomeFile) {
    std::ofstream outFile(nomeFile);
    for (int i = 0; i < lista.getNumeroAttivita(); ++i) {
        Attivita att = lista.getAttivita(i);

        outFile << "[" << (att.isCompletata() ? "Completata" : "Da fare") << "] "
                << att.getDescrizione()
                << " - DataDaFare: " << att.getDataDaFareStringa()
                << " - CreataIl: " << att.getDataCreazioneStringa()
                << "\n";
    }
    outFile.close();
}



void GestoreFile::salvaDaFare(const ListaAttivita& lista, const std::string& nomeFile) {
    std::ofstream outFile(nomeFile);
    for (int i = 0; i < lista.getNumeroAttivita(); ++i) {
        const Attivita& att = lista.getAttivita(i);
        if (!att.isCompletata()) {
            outFile << "[" << "Da fare" << "] "
                    << att.getDescrizione()
                    << " - Creata il " << att.getDataCreazioneStringa()
                    << " - Da fare il " << att.getDataDaFareStringa() << "\n";
        }
    }
    outFile.close();
}

void GestoreFile::salvaCompletate(const ListaAttivita& lista, const std::string& nomeFile) {
    std::ofstream outFile(nomeFile);
    for (int i = 0; i < lista.getNumeroAttivita(); ++i) {
        const Attivita& att = lista.getAttivita(i);
        if (att.isCompletata()) {
            outFile << "[" << "Completata" << "] "
                    << att.getDescrizione()
                    << " - Creata il " << att.getDataCreazioneStringa()
                    << " - Completata il " << att.getDataDaFareStringa() << "\n";
        }
    }
    outFile.close();
}


