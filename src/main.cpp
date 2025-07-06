#include <iostream>
#include <limits>
#include <cstdlib>
#include "Attivita.h"
#include "ListaAttivita.h"
#include "GestoreFile.h"

void mostraMenu() {
    std::cout << "\n📋 ====== MENU PRINCIPALE ======\n";
    std::cout << "1️⃣  Aggiungi una nuova attivita\n";
    std::cout << "2️⃣  Mostra elenco attivita\n";
    std::cout << "3️⃣  Segna attivita come completata\n";
    std::cout << "4️⃣  Salva attivita su file 💾\n";
    std::cout << "5️⃣  Carica attivita da file 📂\n";
    std::cout << "0️⃣  Esci dal programma 🚪\n";
    std::cout << "===============================\n";
    std::cout << "👉 Scelta: ";
}

void attendiInvio() {
    std::cout << "\n🔁 Premi INVIO per continuare...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    ListaAttivita lista;
    int scelta;
    std::string input;
    std::string nomeFile = "todo.txt";

    do {
        system("cls"); // per Windows
        mostraMenu();
        std::cin >> scelta;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (scelta) {
            case 1: {
                std::cout << "\n✏ Inserisci la descrizione dell'attività: ";
                std::getline(std::cin, input);
                lista.aggiungiAttivita(Attivita(input));
                std::cout << "✅ Attività aggiunta con successo!\n";
                attendiInvio();
                break;
            }
            case 2: {
                std::cout << "\n📄 Elenco delle attività:\n";
                lista.mostraAttivita();
                attendiInvio();
                break;
            }
            case 3: {
                std::cout << "🆗 Inserisci l'indice dell'attività da completare: ";
                int index;
                std::cin >> index;
                lista.completaAttivita(index);
                std::cout << "✅ Attività segnata come completata (se l'indice era corretto).\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                attendiInvio();
                break;
            }
            case 4: {
                GestoreFile::salvaSuFile(lista, nomeFile);
                std::cout << "💾 Attività salvate su \"" << nomeFile << "\".\n";
                attendiInvio();
                break;
            }
            case 5: {
                lista = ListaAttivita(); // reset lista
                GestoreFile::caricaDaFile(lista, nomeFile);
                std::cout << "📂 Attività caricate da \"" << nomeFile << "\".\n";
                attendiInvio();
                break;
            }
            case 0:
                std::cout << "👋 Uscita dal programma. A presto!\n";
                break;
            default:
                std::cout << "⚠ Scelta non valida. Riprova.\n";
                attendiInvio();
                break;
        }

    } while (scelta != 0);

    return 0;
}