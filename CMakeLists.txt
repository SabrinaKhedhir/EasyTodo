cmake_minimum_required(VERSION 3.20)
project(EasyTodo)

set(CMAKE_CXX_STANDARD 17)

# Sorgenti principali
add_executable(EasyTodo
        src/main.cpp
        src/Attivita.cpp
        src/ListaAttivita.cpp
        src/GestoreFile.cpp
        src/Observer.h
        src/Logger.h
        src/Subject.h

)

# ------------------ GOOGLE TEST ------------------
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Test: Attivita
add_executable(test_attivita
        tests/test_attivita.cpp
        src/Attivita.cpp
)

target_link_libraries(test_attivita gtest_main)

# Test: ListaAttivita
add_executable(test_lista_attivita
        tests/test_lista_attivita.cpp
        src/ListaAttivita.cpp
        src/Attivita.cpp
)

target_link_libraries(test_lista_attivita gtest_main)

# Test: GestoreFile
add_executable(test_gestore_file
        tests/test_gestore_file.cpp
        src/GestoreFile.cpp
        src/ListaAttivita.cpp
        src/Attivita.cpp
)

target_link_libraries(test_gestore_file gtest_main)


include(GoogleTest)
gtest_discover_tests(test_attivita)
gtest_discover_tests(test_lista_attivita)
gtest_discover_tests(test_gestore_file)