#include "WyrazenieZesp.hh"
#include <cstring>
using namespace std;

/*!
 * Oblicza wartosc wyrazenia zespolonego
 * PRE:
 * Wyrazenie zespolone ktore zostanie obliczone
 * POST:
 * Zwraca wynik rownania w postaci LZesp
 */

LZespolona WyrazenieZesp::Oblicz() const 
{
    LZespolona wynik;
    if(this->Op == 0) //jesli +
    {
        wynik = this->Arg1 + this->Arg2; // wykonaj dodawanie
    }
    else if(this->Op == 1) //jesli -
    {
        wynik = this->Arg1 - this->Arg2; //wykonaj odejmowanie
    }
    else if(this->Op == 2) //jesli *
    {
        wynik = this->Arg1 * this->Arg2; //wykonaj mnozenie
    }
    else if(this->Op == 3) //jesli /
    {
        wynik = this->Arg1 / this->Arg2; //wykonaj dzielenie
    }
    return wynik; //zwroc wynik
}



/*!
 * Realizuje wyswietlanie operatora arytmetycznego
 */

ostream & operator << (ostream & StrmWy, Operator wop) 
{
    const char znakop[] = "+-*/";
    return StrmWy << znakop[wop];
}



/*!
 * Realizuje wyswietlanie wyrazenia zespolonego
 */

ostream & operator << (ostream & StrmWy, WyrazenieZesp WyrZ) // przeciazenie operatora dla wyswietlania wyrazenia zespolonego
{
    return StrmWy << WyrZ.Arg1 << " " << WyrZ.Op << " " << WyrZ.Arg2 << endl;
}



/*!
 * Realizuje wprowadzanie operatora arytmetycznego
 */

istream & operator >> (istream & StrmWe, Operator & WczytSym)
{
    Operator TabTypOp[] = { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };
    const char TabSymOp[] = "+-*/", *wSymOp;
    wSymOp = TabSymOp;
    char CzytSymOp='x';

    StrmWe >> CzytSymOp; // wprowadz symbol

    if((wSymOp= strchr(wSymOp,CzytSymOp)) == nullptr) // jesli znak niepoprawny
    {
        StrmWe.setstate(ios::failbit); // ustaw flage fail
    }
    else
    {
        WczytSym = TabTypOp[wSymOp-TabSymOp]; // w przeciwnym wypadku podaj znak do strumienia
    }
    return StrmWe;
}


/*!
 * Realizuje wprowadzanie wyrazenia zespolonego
 */

istream & operator >> (istream & StrmWe, WyrazenieZesp & WyrZ)
{
    StrmWe >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
    return StrmWe;
}

