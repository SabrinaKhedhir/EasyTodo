#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "Attivita.h"
#include "ListaAttivita.h"
#include "GestoreFile.h"
#include "Logger.h"

void mostraMenu() {
    std::cout << "\n\U0001F4CB ====== MENU PRINCIPALE ======\n";
    std::cout << "1️⃣  Aggiungi una nuova attività\n";
    std::cout << "2️⃣  Mostra elenco attività\n";
    std::cout << "3️⃣  Segna attività come completata\n";
    std::cout << "4️⃣  Salva attività su file \U0001F4BE\n";
    std::cout << "5️⃣  Elimina un'attività ❌\n";
    std::cout << "6️⃣  Modifica un'attività ✏️\n";
    std::cout << "7️⃣  Esci dal programma \U0001F6AA\n";
    std::cout << "===============================\n";
    std::cout << "\U0001F449 Scelta: ";
}


int main() {
    ListaAttivita lista;
    Logger logger;
    lista.aggiungiObserver(&logger);

    int scelta;
    std::string input;
    std::string nomeFile = "todo.txt";
    std::string fileDaFare = "todo_dafare.txt";
    std::string fileCompletate = "todo_completate.txt";

    do {
        system("cls"); // usa "clear" su Mac/Linux
        mostraMenu();
        std::cin >> scelta;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (scelta) {
            case 1: {
                std::string descrizione, dataStr;
                std::cout << "\n✏ Inserisci la descrizione dell'attività: ";
                std::getline(std::cin, descrizione);

                if (descrizione.empty()) {
                    std::cout << "⚠️ Attività non aggiunta. La descrizione è vuota.\n";
                } else {
                    std::cout << "\U0001F4C5 Inserisci la data e ora in cui farai l'attività (formato gg/mm/aaaa hh:mm): ";
                    std::getline(std::cin, dataStr);

                    std::tm tm = {};
                    std::istringstream ss(dataStr);
                    ss >> std::get_time(&tm, "%d/%m/%Y %H:%M");
                    tm.tm_isdst = -1;  // ✅ Disattiva ora legale

                    if (ss.fail()) {
                        std::cout << "❌ Formato data non valido. Usa gg/mm/aaaa hh:mm.\n";
                    } else {
                        std::time_t dataDaFare = mktime(&tm);
                        Attivita nuova(descrizione, std::time(nullptr), dataDaFare);
                        lista.aggiungiAttivita(nuova);
                        std::cout << "✅ Attività aggiunta con successo!\n";
                    }
                }
                break;
            }

            case 2: {
                std::cout << "\n\U0001F4C4 Elenco delle attività:\n";
                lista.mostraAttivita();
                break;
            }
            case 3: {
                std::cout << "✍️ Inserisci l'indice dell'attività da completare: ";
                int index;
                std::cin >> index;

                if (index >= 0 && index < lista.getNumeroAttivita()) {
                    lista.completaAttivita(index);
                    std::cout << "✅ Attività segnata come completata.\n";
                } else {
                    std::cout << "❌ Errore: indice non valido.\n";
                }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            case 4: {
                std::string fileTutte = "todo_tutte.txt";
                std::string fileDaFare = "todo_dafare.txt";
                std::string fileCompletate = "todo_completate.txt";

                std::cout << "\n💾 Cosa vuoi salvare?\n";
                std::cout << "1️⃣  Tutte le attività\n";
                std::cout << "2️⃣  Solo attività da fare\n";
                std::cout << "3️⃣  Solo attività completate\n";
                std::cout << "👉 Scelta: ";

                int tipoSalvataggio;
                std::cin >> tipoSalvataggio;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                switch (tipoSalvataggio) {
                    case 1:
                        GestoreFile::salvaSuFile(lista, fileTutte);
                    std::cout << "✅ Tutte le attività salvate su \"" << fileTutte << "\".\n";
                    break;
                    case 2:
                        GestoreFile::salvaDaFare(lista, fileDaFare);
                    std::cout << "✅ Attività da fare salvate su \"" << fileDaFare << "\".\n";
                    break;
                    case 3:
                        GestoreFile::salvaCompletate(lista, fileCompletate);
                    std::cout << "✅ Attività completate salvate su \"" << fileCompletate << "\".\n";
                    break;
                    default:
                        std::cout << "⚠️ Scelta non valida.\n";
                    break;
                }
                break;
            }


            case 5: {
                std::cout << "\n❌ Inserisci l'indice dell'attività da eliminare: ";
                int index;
                std::cin >> index;
                lista.rimuoviAttivita(index);
                std::cout << "🗑️ Attività eliminata (se l'indice era corretto).\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            case 6: {
                std::cout << "✏️ Inserisci l'indice dell'attività da modificare: ";
                int index;
                std::cin >> index;
                std::cin.ignore();

                if (index >= 0 && index < lista.getNumeroAttivita()) {
                    std::string nuovaDescrizione, nuovaDataStr;
                    std::cout << "📝 Nuova descrizione (lascia vuoto per non cambiare): ";
                    std::getline(std::cin, nuovaDescrizione);

                    std::cout << "🕒 Nuova data e ora (formato gg/mm/aaaa hh:mm, lascia vuoto per non cambiare): ";
                    std::getline(std::cin, nuovaDataStr);

                    Attivita att = lista.getAttivita(index);

                    if (!nuovaDescrizione.empty()) {
                        att.setDescrizione(nuovaDescrizione);
                    }

                    if (!nuovaDataStr.empty()) {
                        std::tm tm = {};
                        std::istringstream ss(nuovaDataStr);
                        ss >> std::get_time(&tm, "%d/%m/%Y %H:%M");
                        tm.tm_isdst = -1;  // ✅ Disattiva ora legale

                        if (!ss.fail()) {
                            std::time_t nuovaData = mktime(&tm);
                            att.setDataDaFare(nuovaData);
                        } else {
                            std::cout << "❌ Formato data non valido. Data non modificata.\n";
                        }
                    }


                    lista.rimuoviAttivita(index);

                    // ✅ Log della modifica (Observer)
                    lista.notifica("Attività modificata: " + att.getDescrizione());

                    lista.aggiungiAttivita(att);

                    std::cout << "✅ Attività modificata con successo!\n";
                } else {
                    std::cout << "⚠️ Indice non valido.\n";
                }

                break;
            }
            case 7:
                std::cout << "👋 Uscita dal programma. A presto!\n";
                break;
            default:
                std::cout << "⚠ Scelta non valida. Riprova.\n";
                break;
        }

    } while (scelta != 0);

    return 0;
}
