#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1")
{
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 3")
{
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.67;
    y.im = 0.67;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero")
{
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;

   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona dzielenie przez LZespolona - zero")
{
    LZespolona x, y;

    x.re = 3;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    WARN_THROWS(x/y);
}

TEST_CASE("Test LZespolona dzielenie przez LZespolona")
{
    LZespolona x, y, z;

    x.re = 3;
    x.im = 2;

    y.re = -8;
    y.im = 3;

    z.re = -0.25;
    z.im = -0.35;
    CHECK(x/y == z);
}
