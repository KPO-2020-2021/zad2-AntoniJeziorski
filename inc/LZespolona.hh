#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  LZespolona operator + (LZespolona Skl2) const;
  LZespolona operator - (LZespolona Skl2) const;
  LZespolona operator * (LZespolona  Skl2) const;
  LZespolona operator / (double  Skl2) const;
  LZespolona operator / (LZespolona  Skl2) const;
  bool operator == (LZespolona Skl2) const;
  void Sprzezenie();
  double Modul2() const;
};
void Wyswietl(LZespolona a);

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


//LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona  operator / (LZespolona  Skl1,  double  Skl2);
ostream & operator << ( ostream & StrmWe, LZespolona Lz );
istream & operator >> ( istream & StrmWe, LZespolona& Lz );
//bool operator == (LZespolona Skl1, LZespolona Skl2);

#endif
