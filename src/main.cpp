#include <iostream>
#include <iomanip>
#include "BazaTestu.hh"
#include "Statystyka.hh"
using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  int licznik = 1; // licznik pytan
  Statystyka ocena = {0, 0}; // inicjacja strunktury statystyki
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) 
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
          ocena.bledne += 1; // dodaj 1 do blednych odpowiedzi
          licznik ++; // zwieksz licznik pytan
          continue; // przejdz do kolejnego pytania
        }
      }
    }
    if(wynik == odpowiedz) // jesli prawda
    {
      cout << "Poprawna odpowiedz" << endl;
      ocena.poprawne += 1; // dodaj 1 do poprawnych odpowiedzi
    }
    else // jesli nie
    {
      cout << "Bledna odpowiedz" << endl;
      cout << "Wynik poprawny: " << wynik << endl;
      ocena.bledne += 1; // dodaj 1 do blednych odpowiedzi
    }
    licznik++; // zwieksz licznik pytan
  }
  Wyswietlwynik(ocena);



  
  /* TESTY FUNKCJI TYDZIEN 0, 1 
  cout << endl << endl << "TESTY" << endl << endl;
  cin.clear();
  cin.ignore(10000, '\n');
  LZespolona x = {1,2}, y = {8,-9}, z;
  WyrazenieZesp w;
  double m;
  // test wprowadzania liczby zespolonej oraz jej wyswietlania
  cout << "Podaj liczbe zespolona :" << endl;
  cin >> z;
  if(cin.fail())
  {
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "blad formatu" << endl;
  }
  else
    cout << z << endl;

  // test prowadznia oraz wyswietlania wyrazenia zespolonego
  cout << "Podaj wyrazenie zespolone:"  << endl;
  cin >> w;
  cout << w << endl;

  // test obliczania wyrazenia zespolonego
  w = {x, Op_Dodaj, y};
  z = Oblicz(w);
  cout << "dodawanie: spodzniewana wartosc to (9-7i) -------" << z;
  cout << endl;
  w = {x, Op_Odejmij, y};
  z = Oblicz(w);
  cout << "odejmowanie: spodziewana wartosc to (-7+11i) ------" << z;
  cout << endl;
  w = {x, Op_Mnoz, y};
  z = Oblicz(w);
  cout << "mnozenie: spodziewana wartosc to (26+7i) -------" << z;
  cout << endl;
  w = {x, Op_Dziel, y};
  z = Oblicz(w);
  cout << "dzielenie: spodziewana wartosc to (-0.0689655+0.172414i) -----" << z;
  cout << endl;

  // test dzielenia przez skalar
  z = x/0.5;
  cout << "dzielenie przez skalar: spodziewana wartosc to (2+4i) -----" << z;
  cout << endl;
  //test obliczania modulu
  m = Modul2(x);
  cout << "moudl l. zesp.: spodziewana wartosc to 2.23607 -------" << m;
cout << endl;
  //test sprzezenia liczby zespolonej
  z = Sprzezenie(x);
  cout << "sprzerzenie l. zesp.: spodziewana wartosc to (1-2i) ------" << z;

  //wyniki sa poprawne, zostaly sprawdzone kalkulatorem wolfram alpha

*/
}
