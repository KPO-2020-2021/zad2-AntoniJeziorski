#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"

TEST_CASE("Wczytywanie wyrazenia zespolonego")
{
    WyrazenieZesp w;

    std::istringstream in("(2+3i)/(8-7i)");
    in >> w;

    std::ostringstream out;
    out << w;

    CHECK("(2.00+3.00i) / (8.00-7.00i)\n" == out.str());
}

TEST_CASE("Wczytywanie wyrazenia zespolonego - brak znaku")
{
    WyrazenieZesp w;

    std::istringstream in("(2+3i)(8-7i)");
    in >> w;

    CHECK(in.fail());
}

TEST_CASE("Wczytywanie wyrazenia zespolonego - niepoprawny znak")
{
    WyrazenieZesp w;

    std::istringstream in("(2+3i)%(8-7i)");
    in >> w;

    CHECK(in.fail());
}

TEST_CASE("Wczytywanie wyrazenia zespolonego - blad argumentu 1")
{
    WyrazenieZesp w;

    std::istringstream in("(23i)+(8-7i)");
    in >> w;

    CHECK(in.fail());
}

TEST_CASE("Wczytywanie wyrazenia zespolonego - blad argumentu 2")
{
    WyrazenieZesp w;

    std::istringstream in("(2+3i)/(8%7i)");
    in >> w;

    CHECK(in.fail());
}

TEST_CASE("Wczytywanie wyrazenia zespolonego - brak argumentu 2")
{
    WyrazenieZesp w;

    std::istringstream in("(2+3i)/");
    in >> w;

    CHECK(in.fail());
}

TEST_CASE("Wczytywanie wyrazenia zespolonego - brak argumentu 1")
{
    WyrazenieZesp w;

    std::istringstream in("/(8%7i)");
    in >> w;

    CHECK(in.fail());
}




