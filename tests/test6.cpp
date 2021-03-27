#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("LZespolona - wyswietlanie standard") {
    LZespolona x;
   
    x.re = 87;
    x.im = 29;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(87.00+29.00i)" == out.str() );
}

TEST_CASE("LZespolona - wyswietlanie zaokraglone w dol") {
    LZespolona x;
   
    x.re = 87;
    x.im = 29.863;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(87.00+29.86i)" == out.str() );
}

TEST_CASE("LZespolona - wyswietlanie zaokraglone w gore") {
    LZespolona x;
   
    x.re = 87;
    x.im = 29.866;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(87.00+29.87i)" == out.str() );
}