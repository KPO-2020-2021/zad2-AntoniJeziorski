#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Statystyka.hh"

TEST_CASE("Test modulu statystyka - inizjalizacja")
{
    Statystyka s;

    s.Inicjalizuj();

    
    CHECK((s.poprawne == 0 && s.bledne == 0));
}

TEST_CASE("Test modulu statystyka - dodawanie poprawnych odpowiedzi")
{
    Statystyka s;

    s.Inicjalizuj();
    s.Dodaj_poprawne();
    s.Dodaj_poprawne();
    
    CHECK(s.poprawne == 2);
}

TEST_CASE("Test modulu statystyka - dodawanie blednych odpowiedzi")
{
    Statystyka s;

    s.Inicjalizuj();
    s.Dodaj_bledne();
    s.Dodaj_bledne();
    
    CHECK(s.bledne == 2);
}

TEST_CASE("Test modulu statystyka - wynik procentowy")
{
    Statystyka s;

    s.Inicjalizuj();
    s.Dodaj_bledne();
    s.Dodaj_poprawne();
    s.Dodaj_poprawne();
    s.Dodaj_poprawne();

    std::ostringstream out;
    out << s;

    CHECK("Poprawne odpowiedzi: 3\nBledne odpowiedzi: 1\nWynik procentowy: 75%\n" == out.str());
}