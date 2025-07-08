#include "Attivita.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <stdexcept>

Attivita::Attivita(const std::string& desc, const std::string& dataDaFareString)
    : descrizione(desc), completata(false), dataCreazione(std::time(nullptr)) {
    std::tm tm = {};
    std::istringstream ss(dataDaFareString);
    ss >> std::get_time(&tm, "%d/%m/%Y");
    if (ss.fail()) {
        throw std::invalid_argument("Formato data non valido. Usa gg/mm/aaaa");
    }
    dataDaFare = std::mktime(&tm);
}

Attivita::Attivita(const std::string& desc, std::time_t dataCreaz, std::time_t dataFare)
    : descrizione(desc), completata(false), dataCreazione(dataCreaz), dataDaFare(dataFare) {}

std::string Attivita::getDescrizione() const {
    return descrizione;
}

void Attivita::setDescrizione(const std::string& nuovaDesc) {
    descrizione = nuovaDesc;
}

bool Attivita::isCompletata() const {
    return completata;
}

void Attivita::completa() {
    completata = true;
}

std::time_t Attivita::getDataCreazione() const {
    return dataCreazione;
}

std::string Attivita::getDataCreazioneStringa() const {
    std::ostringstream oss;
    std::tm* tm_info = std::localtime(&dataCreazione);
    oss << std::put_time(tm_info, "%d/%m/%Y %H:%M");
    return oss.str();
}

std::time_t Attivita::getDataDaFare() const {
    return dataDaFare;
}

void Attivita::setDataDaFare(std::time_t data) {
    dataDaFare = data;
}

std::string Attivita::getDataDaFareStringa() const {
    std::ostringstream oss;
    std::tm* tm_info = std::localtime(&dataDaFare);  // ✅ rimetti localtime
    oss << std::put_time(tm_info, "%d/%m/%Y %H:%M");
    return oss.str();
}
