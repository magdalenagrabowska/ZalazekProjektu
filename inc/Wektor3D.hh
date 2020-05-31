#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <string.h>
#include<cmath>
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*
 *  Ta klasa opisuje wektor.
 *  Wektor jest SWymiarow tablicy 1xwartosc zdefiniowana SWymiar.
 *  Moze byc uzyty przy wyrazach wolnych albo przy niewiadomych.
 *  
 */
template<typename STyp, int SWymiar>
class Wektor {
  protected:
  STyp _tab [SWymiar];
  public:
 Wektor(){for(STyp &tab: _tab) tab=0; }
 Wektor<STyp, SWymiar> operator + (const Wektor<STyp, SWymiar> & W2) const;
 Wektor<STyp, SWymiar>  operator - (const Wektor<STyp, SWymiar>  & W2) const;
 
  STyp operator * (const Wektor<STyp, SWymiar>  & W2) const;

 Wektor<STyp, SWymiar>  operator * (double li) const;

 
   
  const STyp & operator[] (unsigned int index) const; 
  STyp & operator[] (unsigned int index);
  
};


/*
  *  Przeciazenie strumienia wejsciowego.Funkcja wczytuje podana wartosc od
  *  uzytkownika.
  * 
  *  Opis poszczegolnych parametrow wywolania funkcji:
  *   istream &strm  - odwolanie do sturmienia poprzez referencje,
  *   Wektor &Wek  - wartosc,ktora powinna zostac wczytana i zapisana
  *   w strukturze Wektor
  *   
  *   
  *  Warunki wstepne:
  *   strm musi byc strumieniem wejsciowym, by mozna bylo wczytac wartosci,
  *   podane watosci musza byc podane w odpowiedniej formie (tutaj za pomoca tablicy)
  *
  *  Warunki koncowe:
  *   wszystko musi byc poprawnie wczytane, w przeciwnym wypadku strumien jest bledny
  *
  *  Funkcja wczytuje do klasy wektor podane wartosci
  */
 template<typename STyp, int SWymiar>
 std::istream& operator >> (std::istream &Strm, Wektor<STyp, SWymiar>  &Wek);

/*
  *  Przeciazenie strumienia wyjsciowego.Funkcja wyswietla dla uzytkownika
  *  podana wartosc.
  * 
  *  Opis poszczegolnych parametrow wywolania funkcji:
  *   ostream &strm  - odwolanie do sturmienia poprzez referencje,
  *   const Wektor &Wek  - wartosc,ktora powinna zostac wyswietlona,
  *   bez jej zmiany, w dodatku odwolujac sie do oryginalu
  *   
  *  Warunki wstepne:
  *   strm musi byc strumieniem wyjsciowym, by mozna bylo wyswietlic wartosci,
  *   watosci musza byc podane w odpowiedniej formie (tutaj za pomoca tablicy)
  *
  *  Warunki koncowe:
  *   brak
  *
  *  Funkcja wyswietla na wyjsciu standardowym wartosci wektora.
  */
template<typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &strm, const  Wektor<STyp, SWymiar> &Wek);

template<typename STyp, int SWymiar> Wektor<STyp, SWymiar>  operator * (double l1, Wektor<STyp, SWymiar> W2);


class Wektor3D:public Wektor<double,3>{
  public:
Wektor3D(const Wektor<double,3>&W):Wektor<double,3>(W){}
Wektor3D(double x, double y, double z){
  _tab[0]=x; _tab[1]=y; _tab[2]=z;
}
Wektor3D(){
  for(double &tab: _tab) tab=0;
}
drawNS::Point3D zwrocpunkt(){
  return drawNS::Point3D(_tab[0],_tab[1],_tab[2]);
 }
double dlugosc() const{
  Wektor3D W2;
  double a;
  for(int i=0;i<3;i++){
    double skl=(pow((_tab[i]),(2)));
    a+=skl;
  }
  a=sqrt(a);
return a;
  }  
};

#endif

