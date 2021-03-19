#include "WyrazenieZesp.hh"
#include <cstring>
using namespace std;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */


/*! 
 * Funkcja wyswiewtlajaca wyrazenie zespolone
 * PRE:
 * Args:
 *  -Wyrazenie Zesp
 * POST:
 * Funkcja wyswietla wyrazenie zespolone
 */

void Wyswietl(WyrazenieZesp  WyrZ)
{
    if(WyrZ.Op == 0) //jesli dodawajnie
    {
        Wyswietl(WyrZ.Arg1);
        cout<<" + "; //wyswietl +
        Wyswietl(WyrZ.Arg2);
    }
    else if(WyrZ.Op == 1) //jesli odejmowanie
    {
        Wyswietl(WyrZ.Arg1);
        cout<<" - "; //wyswietl -
        Wyswietl(WyrZ.Arg2);
    }
    else if(WyrZ.Op == 2) //jesli mnoezenie
    {
        Wyswietl(WyrZ.Arg1);
        cout<<" * "; //wyswietl *
        Wyswietl(WyrZ.Arg2);
    }
    else if(WyrZ.Op == 3) //jesli dzielenie
    {
        Wyswietl(WyrZ.Arg1);
        cout<<" / "; //wyswietl /
        Wyswietl(WyrZ.Arg2);
    }
    cout << endl;
}

/*!
 * Funkcja wyswietlajaca liczbe zespolona
 * PRE:
 * Args:
 *  - LZespolona
 * POST: 
 * Wyswietlenie liczby zespolonej
 */

void Wyswietl(LZespolona a)
{
    cout << "(" << a.re << showpos << a.im << noshowpos << "i)";
}

/*!
 * Funkcja obliczajaca sprzezenie liczby zespolonej
 * PRE:
 * Args:
 *  - LZespolona
 * POST:
 * Funkcja zwraca sprzezenie liczby zespolonej
 */


LZespolona Sprzezenie(LZespolona a)
{
  a.im = -a.im;
  return a;
}

/*!
 * Funkcja obliczajaca modul liczby zespolonej
 * PRE:
 * Args:
 *  - LZespolona
 * POST:
 * Funkcja zwraza modul liczby zespolonej
 */

double Modul2(LZespolona a)
{
  double m;
  m = sqrt((a.re * a.re) + (a.im * a.im));
  return m;
}

/*!
 * Funkcja obliczajaca wyrazenie zespolone
 * PRE:
 * Args:
 *  -WyrazenieZesp
 * POST:
 * Funkcja zwraza wartosc wyrazenia zespolonego
 */

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    LZespolona wynik;
    if(WyrZ.Op == 0) //jesli +
    {
        wynik = WyrZ.Arg1 + WyrZ.Arg2; // wykonaj dodawanie
    }
    else if(WyrZ.Op == 1) //jesli -
    {
        wynik = WyrZ.Arg1 - WyrZ.Arg2; //wykonaj odejmowanie
    }
    else if(WyrZ.Op == 2) //jesli *
    {
        wynik = WyrZ.Arg1 * WyrZ.Arg2; //wykonaj mnozenie
    }
    else if(WyrZ.Op == 3) //jesli /
    {
        wynik = WyrZ.Arg1 / WyrZ.Arg2; //wykonaj dzielenie
    }
    return wynik; //zwroc wynik
}

/*!
 * Funkcja sluzaca do wprowadzania liczby zespolonej
 * PRE:
 * Args:
 *  - LZespolona
 * POST:
 * Funkcja zwraca wprowadzona liczbe zespolona
 */

LZespolona Wprowadz(LZespolona a)
{
    cout << "Podaj Re : \n";
    cin >> a.re;
    cout << "Podaj Im : \n";
    cin >> a.im;
    return a;
}

/*! Funkcja do wprowadzania wyrazenia zespolonego
 * PRE:
 * Args:
 *  - Wyrazenie zesp;
 * POST:
 * Funkcja zwraca wpisane wyrazenie zespolone
 */

WyrazenieZesp Wprowadz(WyrazenieZesp x)
{
    LZespolona a, b;
    cin >> a;
    char znak;
    cin >> znak;
    if(znak == '+')
    {
        x.Op = Op_Dodaj;
    }
    if(znak == '-')
    {
        x.Op = Op_Odejmij;
    }
    if(znak == '*')
    {
        x.Op = Op_Mnoz;
    }
    if(znak == '/')
    {
        x.Op = Op_Dziel;
    }
    cout << endl;
    cin >> b;
    x.Arg1 = a;
    x.Arg2 = b;
    return x;
}


ostream & operator << (ostream & StrmWy, Operator wop)
{
    const char znakop[] = "+-*/";
    return StrmWy << znakop[wop];
}

ostream & operator << (ostream & StrmWy, WyrazenieZesp WyrZ)
{
    return StrmWy << WyrZ.Arg1 << " " << WyrZ.Op << " " << WyrZ.Arg2;
}


istream & operator >> (istream & StrmWe, Operator & WczytSym)
{
    Operator TabTypOp[] = { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };
    const char TabSymOp[] = "+-*/", *wSymOp;
    wSymOp = TabSymOp;
    char CzytSymOp='x';

    StrmWe >> CzytSymOp;

    if((wSymOp= strchr(wSymOp,CzytSymOp)) == nullptr)
    {
        StrmWe.setstate(ios::failbit);
    }
    else
    {
        WczytSym = TabTypOp[wSymOp-TabSymOp];
    }
    return StrmWe;
}

istream & operator >> (istream & StrmWe, WyrazenieZesp & WyrZ)
{
    StrmWe >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
    return StrmWe;
}
