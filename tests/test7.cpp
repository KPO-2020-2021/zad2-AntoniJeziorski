#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("LZespolona - wczytywanie standard") {
    LZespolona x;
    
    std::istringstream in("(15+126.17i)");
    in >> x;
    std::ostringstream out;
    out << x;
    
    CHECK( "(15.00+126.17i)" == out.str() );
}

TEST_CASE("LZespolona - blad wczytywania - brak nawiasu otwierajacego") {
    LZespolona x;
    
    std::istringstream in("15+126.17i)");
    in >> x;
    
    CHECK(in.fail());
}

TEST_CASE("LZespolona - blad wczytywania - brak i") {
    LZespolona x;
    
    std::istringstream in("(15+126.17)");
    in >> x;
    
    CHECK(in.fail());
}

TEST_CASE("LZespolona - blad wczytywania - brak nawiasu zamykajacego") {
    LZespolona x;
    
    std::istringstream in("15+126.17i");
    in >> x;
    
    CHECK(in.fail());
}

TEST_CASE("LZespolona - blad wczytywania - brak znaku operatora") {
    LZespolona x;
    
    std::istringstream in("15126.17i)");
    in >> x;
    
    CHECK(in.fail());
}

TEST_CASE("LZespolona - blad wczytywania - litera zamiast liczby") {
    LZespolona x;
    
    std::istringstream in("c4h+126.17i)");
    in >> x;
    
    CHECK(in.fail());
}

