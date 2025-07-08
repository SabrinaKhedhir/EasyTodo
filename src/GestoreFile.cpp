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


void GestoreFile::caricaDaFile(ListaAttivita& lista, const std::string& nomeFile) {
    std::ifstream inFile(nomeFile);
    std::string linea;

    while (std::getline(inFile, linea)) {
        if (linea.empty()) continue;

        size_t statoStart = linea.find("[");
        size_t statoEnd = linea.find("]");
        size_t dataFareStart = linea.find(" - DataDaFare: ");
        size_t dataCreazioneStart = linea.find(" - CreataIl: ");

        if (statoStart != std::string::npos &&
            statoEnd != std::string::npos &&
            dataFareStart != std::string::npos &&
            dataCreazioneStart != std::string::npos) {

            std::string stato = linea.substr(statoStart + 1, statoEnd - statoStart - 1);
            std::string descrizione = linea.substr(statoEnd + 2, dataFareStart - statoEnd - 2);
            std::string dataDaFareStr = linea.substr(dataFareStart + 15, dataCreazioneStart - (dataFareStart + 15));
            std::string dataCreazioneStr = linea.substr(dataCreazioneStart + 14);

            // Conversione date
            std::tm tmCreaz = {}, tmFare = {};
            std::istringstream ssCreaz(dataCreazioneStr);
            std::istringstream ssFare(dataDaFareStr);
            ssCreaz >> std::get_time(&tmCreaz, "%d/%m/%Y %H:%M");
            ssFare >> std::get_time(&tmFare, "%d/%m/%Y %H:%M");

            if (!ssCreaz.fail() && !ssFare.fail()) {
                std::time_t dataCreazione = std::mktime(&tmCreaz);
                std::time_t dataDaFare = std::mktime(&tmFare);

                Attivita att(descrizione, dataCreazione, dataDaFare);
                if (stato == "Completata") {
                    att.completa();
                }
                lista.aggiungiAttivita(att);
            }
            }
    }

    inFile.close();
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


