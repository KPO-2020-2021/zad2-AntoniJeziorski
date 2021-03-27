#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("LZespolona - modul standard")
{
    LZespolona x;

    x.re = 3;
    x.im = -4;

    CHECK(x.Modul2() == 5);
}

TEST_CASE("LZespolona - modul dla (0+0i)")
{
    LZespolona x;

    x.re = 0;
    x.im = 0;

    CHECK(x.Modul2() == 0);
}

TEST_CASE("LZespolona - modul dla (1+0i)")
{
    LZespolona x;

    x.re = 1;
    x.im = 0;

    CHECK(x.Modul2() == 1);
}

TEST_CASE("LZespolona - modul dla (0+1i)")
{
    LZespolona x;

    x.re = 0;
    x.im = 1;

    CHECK(x.Modul2() == 1);
}