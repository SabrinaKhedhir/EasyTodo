#ifndef ATTIVITA_H
#define ATTIVITA_H

#include <string>
#include <ctime>

class Attivita {
private:
    std::string descrizione;
    bool completata;
    std::time_t dataCreazione;
    std::time_t dataDaFare;

public:
    Attivita(const std::string& desc, const std::string& dataDaFareString);
    Attivita(const std::string& desc, std::time_t dataCreaz, std::time_t dataFare);

    std::string getDescrizione() const;
    void setDescrizione(const std::string& nuovaDesc);

    bool isCompletata() const;
    void completa();

    std::time_t getDataCreazione() const;
    std::string getDataCreazioneStringa() const;

    std::time_t getDataDaFare() const;
    void setDataDaFare(std::time_t data);
    std::string getDataDaFareStringa() const;
};

#endif // ATTIVITA_H
