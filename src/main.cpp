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
  int licznik = 1;
  Statystyka ocena = {0, 0};
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) 
  {
    LZespolona wynik, odpowiedz;
    cout << "Zadanie " << licznik << ": ";
    Wyswietl(WyrZ_PytanieTestowe);
    wynik = Oblicz(WyrZ_PytanieTestowe);
    cin.clear();
    cin >> odpowiedz;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Blad wczytywania. Podaj wynik jeszcze raz:" << endl;
      cin >> odpowiedz;
      if(cin.fail())
      {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Blad wczytywania. Ostatnia szansa:" << endl;
        cin >> odpowiedz;
        if(cin.fail())
        {
          cin.ignore(10000, '\n');
          cout << "Bledna odpowiedz" << endl;
          cout << "Wynik poprawny: " << wynik << endl;
          ocena.bledne += 1;
          licznik ++;
          continue;
        }
      }
    }
    if(wynik == odpowiedz)
    {
      cout << "Poprawna odpowiedz" << endl;
      ocena.poprawne += 1;
    }
    else
    {
      cout << "Bledna odpowiedz" << endl;
      cout << "Wynik poprawny: " << wynik << endl;
      ocena.bledne += 1;
    }
    
    licznik++;
  }
  Wyswietlwynik(ocena);

  /* TESTY FUNKCJI TYDZIEN 0, 1 */

  LZespolona x = {1,2}, y = {8,-9}, z;
  WyrazenieZesp w;
  double m;
  // test wprowadzania liczby zespolonej oraz jej wyswietlania
  //cin >> z;
  //cout << z;

  // test prowadznia oraz wyswietlania wyrazenia zespolonego
  //cin >> w;
  // cout << w;

  // test obliczania wyrazenia zespolonego
  //w = {x, Op_Dodaj, y};
  //z = Oblicz(w);
  //cout << z;
  //cout << endl;
  //w = {x, Op_Odejmij, y};
  //z = Oblicz(w);
  //cout << z;
  //cout << endl;
  //w = {x, Op_Mnoz, y};
  //z = Oblicz(w);
  //cout << z;
  //cout << endl;
  //w = {x, Op_Dziel, y};
  //z = Oblicz(w);
  //cout << z;
  //cout << endl;

  // test dzielenia przez 0
  //z = x/0;

  // test obliczania modulu
  //m = Modul2(x);
  //cout << m;

  // test sprzezenia liczby zespolonej
  //z = Sprzezenie(x);
  //cout << z;



}
