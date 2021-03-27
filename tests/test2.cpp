#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona roznica")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 3;
    y.im = -8;

    z.re = -2;
    z.im = 9;
    
    CHECK(x-y == z);
}

TEST_CASE("Test LZespolona roznica z  (0+0i)")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;
    
    CHECK(x-y == z);
}

TEST_CASE("Test LZespolona roznica z  ulamkami")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.0001;
    y.im = 0.0001;

    z.re = 0.99;
    z.im = 0.99;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona roznica na granicach")
{
    LZespolona x, y, z;

    x.re = 1.01;
    x.im = 1.01;

    y.re = 0.009;
    y.im = 0.009;

    z.re = 1;
    z.im = 1;
    
    CHECK(x-y == z);
}