#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona mnozenie")
{
    LZespolona x, y, z;

    x.re = 7;
    x.im = 2;

    y.re = 4;
    y.im = -3;

    z.re = 34;
    z.im = -13;
    
    CHECK(x*y == z);
}

TEST_CASE("Test LZespolona mnozenie z (0+0i)")
{
    LZespolona x, y, z;

    x.re = 7;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    CHECK(x*y == z);
}

TEST_CASE("Test LZespolona mnozenie z (1+0i)")
{
    LZespolona x, y, z;

    x.re = 7;
    x.im = 2;

    y.re = 1;
    y.im = 0;

    z.re = 7;
    z.im = 2;
    
    CHECK(x*y == z);
}

TEST_CASE("Test LZespolona mnozenie z (0+1i)")
{
    LZespolona x, y, z;

    x.re = 7;
    x.im = 2;

    y.re = 0;
    y.im = 1;

    z.re = -2;
    z.im = 7;
    
    CHECK(x*y == z);
}

TEST_CASE("Test LZespolona mnozenie z (1+1i)")
{
    LZespolona x, y, z;

    x.re = 7;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    z.re = 5;
    z.im = 9;
    
    CHECK(x*y == z);
}

TEST_CASE("Test LZespolona mnozenie poza zakresem dokaldnosci")
{
    LZespolona x, y, z;

    x.re = 0.002;
    x.im = 0.002;

    y.re = 0.01;
    y.im = 0.01;

    z.re = 0.01;
    z.im = 0.01;
    
    CHECK(x*y == z);
}