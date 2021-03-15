#include <iostream>
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
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    LZespolona wynik, odpowiedz;
    cout << "Zadanie " << licznik << ": ";
    Wyswietl(WyrZ_PytanieTestowe);
    wynik = Oblicz(WyrZ_PytanieTestowe);
    cin >> odpowiedz;
    if(wynik == odpowiedz)
    {
      cout << "Poprawna odpowiedz" << endl;
      ocena.poprawne += 1;
    }
    else
    {
      cout << "Bledna odpowiedz" << endl;
      ocena.bledne += 1;
    }
    licznik++;
  }
  Wyswietlwynik(ocena);

  /*LZespolona a;
  cin>>a;
  Wyswietl(a);
  cout << endl;
  LZespolona x = {2,-1}, y = {5,3}, z;
  WyrazenieZesp w = {x, Op_Dodaj, y};
  Wyswietl(w);
  cout << endl;                             // testy funkcji
  z = Oblicz(w);                            // wyniki obliczen sa poprawne; zostaly sprawdzone kalkulatorem Wolfram Alpha
  cout << endl;
  Wyswietl(z);
  w = {x, Op_Odejmij, y};
  cout << endl;
  z = Oblicz(w);
  Wyswietl(z);
  cout << endl;
  w = {x, Op_Mnoz, y};
  z = Oblicz(w);
  Wyswietl(z);
  cout << endl;
  w = {x, Op_Dziel, y};
  z = Oblicz(w);
  Wyswietl(z);
  WyrazenieZesp o;
  o = Wprowadz(o);
  Wyswietl(o);*/
  

  cout << endl;
  cout << "Koniec testu" << endl;
  cout << endl;
  
}
