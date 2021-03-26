#include "Statystyka.hh"

/*!
 * Funkcja wyswietlajaca wynik testu
 * PRE :
 * Wyniki blednych oraz poprawnych odpowiedzi
 * POST :
 * Funkcja wyswietla ilosc poprawnych oraz blednych odpowiedzi wraz z wynikiem procentowym
 */


/*void Wyswietlwynik(Statystyka wynik)
{
    cout << "Poprawne odpowiedzi: " << wynik.poprawne << endl;
    cout << "Bledne odpowiedzi: " << wynik.bledne << endl;
    cout << "Wynik procentowy: " << (double(wynik.poprawne) / (wynik.poprawne + wynik.bledne)) * 100 << "%" << endl;
}*/

ostream & operator << (ostream & StrmWy, Statystyka wynik)
{
    cout << "Poprawne odpowiedzi: " << wynik.poprawne << endl;
    cout << "Bledne odpowiedzi: " << wynik.bledne << endl;
    cout << "Wynik procentowy: " << (double(wynik.poprawne) / (wynik.poprawne + wynik.bledne)) * 100 << "%" << endl;
    return StrmWy;
}

void Statystyka::Inicjalizuj()
{
    this->poprawne = 0;
    this->bledne = 0;
}

void Statystyka::Dodaj_poprawne()
{
    this->poprawne += 1;
}

void Statystyka::Dodaj_bledne()
{
    this->bledne += 1;
}