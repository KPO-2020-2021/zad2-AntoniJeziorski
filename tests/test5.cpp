#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("LZespolona - porownanie 1") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(!(x == y));
}

TEST_CASE("LZespolona - porownanie 2") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 2;
   
    CHECK(x == y);
}

TEST_CASE("LZespolona - porownanie wartosci granicznych") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 1.99;
    y.im = 1.99;
   
    CHECK(x == y);
}

TEST_CASE("LZespolona - porownanie wartosci granicznych 2") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2.01;
    y.im = 2.01;
   
    CHECK(x == y);
}