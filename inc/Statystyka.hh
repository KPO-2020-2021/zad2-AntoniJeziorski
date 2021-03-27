#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include <iostream>

using namespace std;

/*!
 * Modeluje strukture przetrzymujaca wyniki testu
 */

struct Statystyka
{
    int poprawne, bledne;
    void Dodaj_poprawne();
    void Dodaj_bledne();
    void Inicjalizuj();

};

/*!
 * Funkcja wyswietlajaca wyniki statysytki
 */

ostream & operator << (ostream & StrmWy, Statystyka wynik);



#endif