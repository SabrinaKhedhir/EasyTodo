#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
#include <string>
#include <algorithm>

class Subject {
protected:
    std::vector<Observer*> osservatori;

public:
    void aggiungiObserver(Observer* obs) {
        osservatori.push_back(obs);
    }

    void rimuoviObserver(Observer* obs) {
        osservatori.erase(std::remove(osservatori.begin(), osservatori.end(), obs), osservatori.end());
    }

    void notifica(const std::string& messaggio) {
        for (auto obs : osservatori) {
            obs->update(messaggio);
        }
    }
};

#endif // SUBJECT_H
