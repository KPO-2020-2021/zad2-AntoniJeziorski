#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH
#include <iostream>
#include <cmath>

#include <iomanip>
#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
  LZespolona Oblicz() const;
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */


istream & operator >> (istream & StrmWe, Operator & WczytSym);
ostream & operator << (ostream & StrmWy, Operator wop);
ostream & operator << (ostream & StrmWy, WyrazenieZesp WyrZ);
istream & operator >> (istream & StrmWe, WyrazenieZesp & WyrZ);
#endif
