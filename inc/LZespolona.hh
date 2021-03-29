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


ostream & operator << ( ostream & StrmWe, LZespolona Lz );
istream & operator >> ( istream & StrmWe, LZespolona& Lz );
LZespolona operator += (LZespolona &Arg1, LZespolona const &Arg2);
LZespolona operator /= (LZespolona &Arg1, LZespolona const &Arg2);
double arg(LZespolona z);
#endif
