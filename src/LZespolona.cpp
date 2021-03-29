#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include <bits/stdc++.h>
#define MIN_DIFF 0.01

using namespace std;

/*!
 * Realizuje operacje dodawania dwoch liczb zespolonych.
 * PRE:
 * Argumenty:
 *    Skl2 - drugi skladnik dodawania.
 * POST:
 * Zwraca:
 *    Sume dwoch skladnikow, gdzie jednym jest liczba dla ktorej zostala wywolana metoda, a druga jest argumentem metody.
 */

LZespolona  LZespolona::operator + (LZespolona  Skl2) const 
{
  Skl2.re += this->re;
  Skl2.im += this->im;
  return Skl2;
}



/*!
 * Realizuje operacje odejmowania dwoch liczb zespolonych.
 * PRE:
 * Argumenty:
 *    Skl2 - odjemnik.
 * POST:
 * Zwraca:
 *    Roznice dwoch liczb zespolonych gdzie: odjemna to liczba dla ktorej zostala wywolana metoda, a odjemnik to argument.
 */

LZespolona  LZespolona::operator - (LZespolona  Skl2) const
{

  Skl2.re = this->re - Skl2.re;
  Skl2.im = this->im - Skl2.im;
  return Skl2;
}



/*!
 * Realizuje operacje mnozenia dwoch liczb zespolonych.
 * PRE:
 * Argumenty:
 *    Skl2 - drugi czynnik
 * POST:
 *    Iloczyn dwoch czynnikow gdzie: pierwszy do liczba dla ktorej zostala wywolana metoda, a drugi to parametr
 */

LZespolona  LZespolona::operator * (LZespolona  Skl2) const
{
  LZespolona Wynik;
  Wynik.re = (this->re * Skl2.re) - (this->im * Skl2.im);
  Wynik.im = (this->re * Skl2.im) + (this->im * Skl2.re);
  return Wynik;
}



/*!
 * Realizuje dzielenie liczby zespolonej przez liczbe rzeczywista.
 * PRE:
 * Argumenty:
 *    Skl2 - dzielnik.
 * POST:
 *    Iloraz liczby zespolonej oraz liczby rzeczywistej gdzie: dzielna to LZespolona dla ktorej zostala wywolana metoda, a dzielnik to argument
 */

LZespolona  LZespolona::operator / (double  Skl2) const
{
  LZespolona Wynik;
  if(Skl2 == 0) // jesli dzielnik to 0
  {
    throw runtime_error("Dzielnie przez 0"); // wyrzuc blad
  }
  else
  {
    Wynik.re = this->re/Skl2;
    Wynik.im = this->im/Skl2;
  }
  return Wynik;
}



/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * PRE:
 * Argumenty:
 *    Skl2 - dzielnik.
 * POST:
 *    Iloraz dwoch liczb zespolonych gdzie: dzielna to liczba dla ktorej zostala wywolana metoda, a dzielnik to argument
 */

LZespolona  LZespolona::operator / (LZespolona  Skl2) const
{
  LZespolona Wynik;
  if (Skl2.Modul2() == 0)
  {
    throw runtime_error("Dzielnie przez 0");
  }
  else
  {
    Skl2.Sprzezenie();
    Wynik = (*this * Skl2) / (Skl2.Modul2() * Skl2.Modul2());
  }
  return Wynik;

}



/*!
 * Realizuje wyswietlenie liczby zespolonej podanej jako parametr
 */

ostream & operator << ( ostream & StrmWy, LZespolona Lz )
{
  StrmWy.precision(2); // ustawienie dokladnosci do dwoch miejsc po przecinku
  return StrmWy << '(' << std::fixed << Lz.re << showpos << Lz.im << noshowpos << 'i' << ')';
}



/*!
 * Realizuje wczytywanie liczby zespolonej podanej jako parametr
 */

istream & operator >> ( istream & StrmWe, LZespolona& Lz )
{
  char i, naw;
  StrmWe >> naw; // wprowadz znak
  if(StrmWe.fail())
    return StrmWe;
  if(naw != '(') // jesli nie jest nawiasem
  {
    StrmWe.setstate(ios::failbit); // ustaw flage fail
    return StrmWe;
  }
  StrmWe >> Lz.re; // wprowadz czesc rzeczywista
  if(StrmWe.fail())
    return StrmWe;
  StrmWe >> Lz.im; // wprowadz czesc urojona
  if(StrmWe.fail())
    return StrmWe;
  StrmWe >> i; // wprowadz znak
  if(StrmWe.fail())
    return StrmWe;
  if(i != 'i') // jesli nie jest i
  {
    StrmWe.setstate(ios::failbit); // ustaw flage fail
    return StrmWe;
  }
  StrmWe >> naw; // wprowadz znak
  if(StrmWe.fail())
    return StrmWe;
  if(naw != ')') // jesli nie jest to nawias
  {
    StrmWe.setstate(ios::failbit); // ustaw flage fail
    return StrmWe;
  }
  return StrmWe;
}



/*!
 * Realizuje porownanie dwoch liczb zespolonych w granicach bledu MIN_DIFF 0.01
 */

bool LZespolona::operator == (LZespolona Skl2) const
{
  if((this->re >= Skl2.re - MIN_DIFF)&&(this->re <= Skl2.re + MIN_DIFF)&&(this->im >= Skl2.im - MIN_DIFF)&&(this->im <= Skl2.im + MIN_DIFF)) // sprawdzenie czy liczba zespolona miesci sie w danym przedziale
    return true; // jesli tak zwroc prawde
  else 
    return false;
}



/*!
 * Realizuje operacje sprzezenia liczby zespolonej
 */

void LZespolona::Sprzezenie()
{
    if(this->im != 0) // jesli czesc urojona nie jest zerem
        this->im = -this->im; //zmien jej znak
}



/*!
 * Realizuje operacje wyliczenia modulu liczby zespolonej
 * PRE:
 * Liczba zespolona, z ktorej chcemy uzyskac modul
 * POST:
 * Modul liczby zespolonej w postaci double
 */

double LZespolona::Modul2() const
{
  double m;
  m = sqrt((this->re * this->re) + (this->im * this->im));
  return m;
}

/* Modyfikacje */

/*!
 * Realizuje przeciazenie operatora += dla LZespolonej
 */


LZespolona operator += (LZespolona &Arg1, LZespolona const &Arg2)
{
  Arg1 = Arg1 + Arg2;
  return Arg1;
}

/*!
 * Realizuje przeciazenie operatora /= dla liczby zespolonej
 */

LZespolona operator /= (LZespolona &Arg1, LZespolona const &Arg2)
{
  Arg1 = Arg1 / Arg2;
  return Arg1;
}

/*!
 * Wyswietla argument glowny liczby zespolonej
 * PRE:
 * Argumenty: LZespolona
 * POST:
 * Wyswietlenie argumentu glownego liczby zespolonej
 */

double arg(LZespolona z)
{
  double arg;
  if(z.re == 0 && z.im == 0) // jesli liczba jest postaci 0+0i
    throw runtime_error("Kat niezdefiniowany"); // pokaz blad
  if(z.re > 0)
    arg = atan2(z.im, z.re);
  if(z.re < 0)
    arg = atan2(z.im, z.re) + M_PI;
  if(z.re == 0)
  {
    if(z.im > 0)
      arg = M_PI/2;
    if(z.im < 0)
      arg = -M_PI/2;
  }
  cout << setprecision(2) << arg;
  return arg;
}
