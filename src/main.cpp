#include <iostream>
#include <iomanip>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;


int main(int argc, char **argv)
{

  if (argc < 2) // jesli nie podano przy wlacznaiu programu poziomu trudnosci
  { 
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1; // zakoncz program i zwroc 1
  }


  BazaTestu   BazaT = { nullptr, 0, 0 }; // inicjalizacja struktury BazaTestu

  if (InicjalizujTest(&BazaT,argv[1]) == false) // jesli inicjalizacja sie nie powiodla
  {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1; // zakoncz program i zwroc 1
  }


  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  int licznik = 1; // licznik pytan
  Statystyka ocena;
  ocena.Inicjalizuj(); // inicjacja strunktury statystyki
  try
  {
    while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) // petla wczytujaca kolejne pytanie z bazy
    {
    LZespolona wynik, odpowiedz; // zmienna wynik z policzonym wyrazeniem oraz zmienna odpowiedz do podawania odpowiedzi
    cout << "Zadanie " << licznik << ": ";
    cout << WyrZ_PytanieTestowe;
    wynik = WyrZ_PytanieTestowe.Oblicz(); // obliczenie wyrazenia
    cin.clear();
    cin >> odpowiedz;
    if(cin.fail()) // jesli wystapil blad przy wczytywaniu
    {
      cin.clear(); // odpowiedz jeszcze raz
      cin.ignore(10000, '\n');
      cout << "Blad wczytywania. Podaj wynik jeszcze raz:" << endl;
      cin >> odpowiedz;
      if(cin.fail()) // jesli znow blad
      {
        cin.clear(); // odpowiedz ostatni raz
        cin.ignore(10000, '\n');
        cout << "Blad wczytywania. Ostatnia szansa:" << endl;
        cin >> odpowiedz;
        if(cin.fail()) // jesli blad
        {
          cin.ignore(10000, '\n');
          cout << "Bledna odpowiedz" << endl;
          cout << "Wynik poprawny: " << wynik << endl;
          ocena.Dodaj_bledne(); // dodaj 1 do blednych odpowiedzi
          licznik ++; // zwieksz licznik pytan
          continue; // przejdz do kolejnego pytania
        }
      }
    }
    if(wynik == odpowiedz) // jesli prawda
    {
      cout << "Poprawna odpowiedz" << endl;
      ocena.Dodaj_poprawne(); // dodaj 1 do poprawnych odpowiedzi
    }
    else // jesli nie
    {
      cout << "Bledna odpowiedz" << endl;
      cout << "Wynik poprawny: " << wynik << endl;
      ocena.Dodaj_bledne(); // dodaj 1 do blednych odpowiedzi
    }
    licznik++; // zwieksz licznik pytan
    }
  }
  catch(runtime_error& e)
  {
    cerr << "Blad " << e.what() << '\n';
    exit(1);
  }
  
  cout << ocena; // wyswietl wynik

  return 0;
}
