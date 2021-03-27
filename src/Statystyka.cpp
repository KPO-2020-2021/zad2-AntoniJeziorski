#include "Statystyka.hh"

/*!
 * Realizuje wyswietlanie modulu statystyki
 */

ostream & operator << (ostream & StrmWy, Statystyka wynik)
{
    StrmWy << "Poprawne odpowiedzi: " << wynik.poprawne << "\nBledne odpowiedzi: " << wynik.bledne << "\nWynik procentowy: " << (double(wynik.poprawne) / (wynik.poprawne + wynik.bledne)) * 100 << "%\n";
    return StrmWy;
}

/*!
 * Inicjalizuje modul statystyki przypisujac zmiennym wartosc 0
 */

void Statystyka::Inicjalizuj() 
{
    this->poprawne = 0;
    this->bledne = 0;
}

/*!
 * Dodaje 1 kiedy uzytkownik poda poprawna odpowiedz
 */

void Statystyka::Dodaj_poprawne()
{
    this->poprawne += 1;
}

/*!
 * Dodaje 1 kiedy uzytkownik poda zla odpowiedz
 */

void Statystyka::Dodaj_bledne()
{
    this->bledne += 1;
}

