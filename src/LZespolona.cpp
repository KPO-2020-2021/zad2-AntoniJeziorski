#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#define MIN_DIFF 0.01



/*!
 * Realizuje operacje dodawania dwoch liczb zespolonych.
 * Argumenty:
 *    Skl2 - drugi skladnik dodawania.
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
 * Argumenty:
 *    Skl2 - odjemnik.
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
 * Argumenty:
 *    Skl2 - drugi czynnik
 * Zwraca:
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
 * Argumenty:
 *    Skl2 - dzielnik.
 * Zwraca:
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
 * Argumenty:
 *    Skl2 - dzielnik.
 * Zwraca:
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
  StrmWy.precision(2);
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
 */

double LZespolona::Modul2() const
{
  double m;
  m = sqrt((this->re * this->re) + (this->im * this->im));
  return m;
}