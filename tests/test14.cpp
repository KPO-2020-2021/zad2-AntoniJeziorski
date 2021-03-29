#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona +=")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK((x+=y) == z);
}

TEST_CASE("test LZespolona += z (0+0i)")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = -0;

    z.re = 1;
    z.im = 1;
    
    CHECK((x+=y) == z);
}

TEST_CASE("test LZespolona += z ulamkami ")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.000000001;
    y.im = 0.000000001;

    z.re = 1;
    z.im = 1;
    
    CHECK((x+=y) == z);
}

TEST_CASE("test LZespolona += na granicach")
{
    LZespolona x, y, z;

    x.re = 1.009;
    x.im = 1.009;

    y.re = 0.001;
    y.im = 0.001;

    z.re = 1;
    z.im = 1;
    
    CHECK((x+=y) == z);
}

TEST_CASE("Test LZespolona /= - zero")
{
    LZespolona x, y;

    x.re = 3;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    WARN_THROWS(x/=y);
}

TEST_CASE("Test LZespolona /=")
{
    LZespolona x, y, z;

    x.re = 3;
    x.im = 2;

    y.re = -8;
    y.im = 3;

    z.re = -0.25;
    z.im = -0.35;
    CHECK((x/=y) == z);
}

TEST_CASE("Test arg dla liczby 0")
{
    LZespolona x = {0, 0};

    WARN_THROWS(arg(x));
}

TEST_CASE("Test arg dla liczby z I cwiartku ukladu")
{
    LZespolona x = {3, 7};

    std::ostringstream cout;
    arg(x);

    CHECK(cout.str() == "1.2");
}
