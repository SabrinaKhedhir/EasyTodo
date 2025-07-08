#ifndef LOGGER_H
#define LOGGER_H

#include "Observer.h"
#include <iostream>

class Logger : public Observer {
public:
    void update(const std::string& messaggio) override {
        std::cout << "📢 Log: " << messaggio << std::endl;
    }
};

#endif // LOGGER_H
