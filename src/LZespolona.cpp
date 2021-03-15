#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - odjemna ,
 *    Skl2 - odjemnik.
 * Zwraca:
 *    Roznice dwoch liczb zespolonych przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy czynnik dodawania,
 *    Skl2 - drugi czynnik dodawania.
 * Zwraca:
 *    Iloczyn dwoch czynnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;
  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl2.re * Skl1.im);
  return Wynik;
}
/*!
 * Realizuje dzielenie liczby zespolonej przez liczbe rzeczywista.
 * Argumenty:
 *    Skl1 - dzielna,
 *    Skl2 - dzielnik.
 * Zwraca:
 *    Iloraz liczby zespolonej oraz liczby rzeczywistej przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2)
{
  LZespolona Wynik;
  if(Skl2 != 0)
  {
    Wynik.re = Skl1.re/Skl2;
    Wynik.im = Skl1.im/Skl2;
    return Wynik;
  }
  else
  {
    cerr<<"Dzielnie przez 0 - blad"<<endl;
    exit(1);
  }
  
}
/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - dzielna,
 *    Skl2 - dzielnik.
 * Zwraca:
 *    Iloraz dwoch liczb zespolonych przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;
  if (Modul2(Skl2) == 0)
  {
    cerr<<"Dzielenie przez 0 - blad "<<endl;
    exit(1);
  }
  else
    Wynik = (Skl1 * Sprzezenie(Skl2)) / (Modul2(Skl2)* Modul2(Skl2));
  return Wynik;

}
/*!
 * Realizuje wyswietlenie liczby zespolonej podanej jako parametr
 */
ostream & operator << ( ostream & StrmWy, LZespolona Lz )
{
  return StrmWy << '(' << Lz.re << showpos << Lz.im << noshowpos << 'i' << ')';
}
/*!
 * Realizuje wczytywanie liczby zespolonej podanej jako parametr
 */
istream & operator >> ( istream & StrmWe, LZespolona& Lz )
{
  char i, naw;
  StrmWe >> naw;
  if(StrmWe.fail())
    return StrmWe;
  if(naw != '(')
  {
    StrmWe.setstate(ios::failbit);
    return StrmWe;
  }
  StrmWe >> Lz.re;
  if(StrmWe.fail())
    return StrmWe;
  StrmWe >> Lz.im;
  if(StrmWe.fail())
    return StrmWe;
  StrmWe >> i;
  if(StrmWe.fail())
    return StrmWe;
  if(i != 'i')
  {
    StrmWe.setstate(ios::failbit);
    return StrmWe;
  }
  StrmWe >> naw;
  if(StrmWe.fail())
    return StrmWe;
  if(naw != ')')
  {
    StrmWe.setstate(ios::failbit);
    return StrmWe;
  }
  return StrmWe;
}

bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else 
    return false;
}
