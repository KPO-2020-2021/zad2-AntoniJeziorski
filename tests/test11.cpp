#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"

TEST_CASE("Wyswietlanie wyrazenia zespolonego - standard")
{
    WyrazenieZesp w;
    w.Arg1.re = 8.37;
    w.Arg1.im = -7.98;
    w.Op = Op_Mnoz;
    w.Arg2.re = 8;
    w.Arg2.im = -3;

    std::ostringstream out;
    out << w;
    
    CHECK("(8.37-7.98i) * (8.00-3.00i)\n" == out.str());
}