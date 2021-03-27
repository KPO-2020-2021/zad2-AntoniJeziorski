#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma z (0+0i)")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = -0;

    z.re = 1;
    z.im = 1;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma z ulamkami ")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.000000001;
    y.im = 0.000000001;

    z.re = 1;
    z.im = 1;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma na granicach")
{
    LZespolona x, y, z;

    x.re = 1.009;
    x.im = 1.009;

    y.re = 0.001;
    y.im = 0.001;

    z.re = 1;
    z.im = 1;
    
    CHECK(x+y == z);
}