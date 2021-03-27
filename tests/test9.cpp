#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test sprzezenia - standar")
{
    LZespolona x, y;

    x.re = 1;
    x.im = -3;

    y.re = 1;
    y.im = 3;

    x.Sprzezenie();
    CHECK(x == y);
}

TEST_CASE("Test sprzezenia - zerowa wartosc im")
{
    LZespolona x;

    x.re = 1;
    x.im = 0;

    x.Sprzezenie();

    std::ostringstream out;
    out << x;

    std::cout << out.str() << std::endl;

    CHECK("(1.00+0.00i)" == out.str());
}

