#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"

TEST_CASE("Wyrazenie zespolone - dodawanie")
{
    WyrazenieZesp w;
    LZespolona y;
    w.Arg1 = {3, 7};
    w.Op = Op_Dodaj;
    w.Arg2 = {-2, -3};
    
    y = {1, 4};

    CHECK(w.Oblicz() == y);
}

TEST_CASE("Wyrazenie zespolone - odejmowanie")
{
    WyrazenieZesp w;
    LZespolona y;
    w.Arg1 = {3, 7};
    w.Op = Op_Odejmij;
    w.Arg2 = {-2, -3};
    
    y = {5, 10};

    CHECK(w.Oblicz() == y);
}

TEST_CASE("Wyrazenie zespolone - mnozenie")
{
    WyrazenieZesp w;
    LZespolona y;
    w.Arg1 = {3, 7};
    w.Op = Op_Mnoz;
    w.Arg2 = {-2, -3};
    
    y = {15, -23};

    CHECK(w.Oblicz() == y);
}

TEST_CASE("Wyrazenie zespolone - dzielenie")
{
    WyrazenieZesp w;
    LZespolona y;
    w.Arg1 = {3, 7};
    w.Op = Op_Dziel;
    w.Arg2 = {-2, -3};
    
    y = {-2.08, -0.38};

    CHECK(w.Oblicz() == y);
}

TEST_CASE("Wyrazenie zespolone - dzielenie przez 0")
{
    WyrazenieZesp w;

    w.Arg1 = {3, 7};
    w.Op = Op_Dziel;
    w.Arg2 = {0, 0};
    
    WARN_THROWS(w.Oblicz());
}

TEST_CASE("Wyrazenie zespolone - mnozenie razy (0+0i)")
{
    WyrazenieZesp w;

    w.Arg1 = {3, 7};
    w.Op = Op_Mnoz;
    w.Arg2 = {0, 0};
    
    LZespolona y;
    y = {0, 0};
    CHECK(w.Oblicz() == y);
}

TEST_CASE("Wyrazenie zespolone - dodawanie (0+0i)")
{
    WyrazenieZesp w;

    w.Arg1 = {3, 7};
    w.Op = Op_Dodaj;
    w.Arg2 = {0, 0};
    
    LZespolona y;
    y = {3, 7};
    CHECK(w.Oblicz() == y);
}

