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

TEST_CASE("Test arg dla liczby z I cwiartki")
{
    LZespolona x = {3, 7};
    double y = 1.16;

    CHECK((arg(x)>= y - 0.01 && arg(x) <= y + 0.01));
}

TEST_CASE("Test arg dla liczby z II cwiartki")
{
    LZespolona x = {6, -2};
    double y = -0.32;

    CHECK((arg(x) >= y - 0.01 && arg(x) <= y + 0.01));
}

TEST_CASE("Test arg dla liczby z IV cwiartki")
{
    LZespolona x = {5, -3};
    double y = -0.54;

    CHECK((arg(x) >= y - 0.01 && arg(x) <= y + 0.01));
}

TEST_CASE("Test arg dla liczby z re = 0 i im > 0")
{
    LZespolona x = {0, 3};
    double y = M_PI_2;

    CHECK((arg(x) >= y - 0.01 && arg(x) <= y + 0.01));
}

TEST_CASE("Test arg dla liczby z re = 0 i im < 0")
{
    LZespolona x = {0, -3};
    double y = -M_PI_2;

    CHECK((arg(x) >= y - 0.01 && arg(x) <= y + 0.01));
}