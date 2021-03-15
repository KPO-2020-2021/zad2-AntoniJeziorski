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
};

void Wyswietlwynik(Statystyka wynik);



#endif