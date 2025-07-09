# 📝 EasyTodo

EasyTodo** è un'applicazione C++ da linea di comando per gestire attività da fare. Permette di aggiungere, visualizzare, modificare, eliminare e salvare attività su file, con un sistema di log basato sul pattern Observer. Include test automatici con GoogleTest.

## 🚀 Funzionalità principali

- Aggiunta di nuove attività con descrizione e data di esecuzione
- Visualizzazione elenco attività con stato, data di creazione ed esecuzione
- Modifica descrizione e data di attività esistenti
- Completamento e rimozione attività
- Salvataggio su file:
    - Tutte le attività
    - Solo attività da fare
    - Solo attività completate
- Logging automatico tramite observer `Logger`
- Test automatici con GoogleTest

## 📁 Struttura del progetto

EasyTodo/
│
├── src/
│ ├── main.cpp
│ ├── Attivita.cpp / Attivita.h
│ ├── ListaAttivita.cpp / ListaAttivita.h
│ ├── GestoreFile.cpp / GestoreFile.h
│ ├── Subject.h / Observer.h / Logger.h
│
├── tests/
│ ├── test_attivita.cpp
│ ├── test_lista_attivita.cpp
│ ├── test_gestore_file.cpp
│
├── CMakeLists.txt
└── README.md <-- (questo file)

## 🧪 Testing
Include 3 suite di test:
    -test_attivita: verifica Attivita
    -test_lista_attivita: verifica ListaAttivita
    -test_gestore_file: verifica scrittura file


## 📄 File salvati
Il programma salva su tre file diversi:
    todo_tutte.txt – tutte le attività
    todo_dafare.txt – solo quelle da completare
    todo_completate.txt – solo quelle completate

## 👩‍💻 Autore
Sabrina Khedhir
Corso di Ingegneria Informatica – Università degli Studi di Firenze
Anno Accademico 2024/2025