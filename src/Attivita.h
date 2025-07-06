#ifndef ATTIVITA_H
#define ATTIVITA_H

#include <string>

class Attivita {
private:
    std::string descrizione;
    bool completata;

public:
    Attivita(const std::string& desc);

    void completa();
    bool isCompletata() const;

    std::string getDescrizione() const;
    void setDescrizione(const std::string& desc);
};

#endif // ATTIVITA_H