#ifndef GESTOREFILE_H
#define GESTOREFILE_H

#include "ListaAttivita.h"
#include <string>

class GestoreFile {
public:
    static void salvaSuFile(const ListaAttivita& lista, const std::string& nomeFile);
    static void caricaDaFile(ListaAttivita& lista, const std::string& nomeFile);
};

#endif // GESTOREFILE_H