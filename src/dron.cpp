#include "dron.hh"
#include <iostream>
#include<vector>
#include "Dr3D_gnuplot_api.hh"
#include<cmath>
#include<fstream>

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using std::cerr;

/*!
   * \brief funkcja wait4key jest poleceniem dla gnuplota, żeby poczekał na wskazany przycisk wpisany
   * z klawiatury przez użytkownika, w tym wypadku jest to klawisz "w", po nim przechodzi do następnej akcji
   */ 


void dron::wait4key(){
  do {
    std::cout << "\n Press w to continue..." << std::endl;
  } while(std::cin.get() != 'w');
}

/*!
   * \brief medota klasy dron. Przesuwa drona w przód albo w tyl, czyli z założeń wzdłuż osi Y o zadaną wartość
   */ 


void dron::przesuneciedronaprzod(double a){
  Wektor3D move;
  for(int i=0;i<abs(a);i++){
  /*if(iden!=1){
  bryla::api->erase_shape(iden);
  }*/
  if(a>0)move[1]=1;
  else move[1]=-1;
  zmienp(move);
  iden=rysuj();
  wait4key();
  }
}
/*!
   * \brief medota klasy dron. Przesuwa drona w bok, czyli z założeń wzdłuż osi X o zadaną wartość
   */ 
void dron::przesunieciedronabokl(double a){
  Wektor3D move;
  for(int i=0;i<abs(a);i++){
  /*if(iden!=1){
  bryla::api->erase_shape(iden);
  }*/
  if(a>0)move[0]=1;
  else move[0]=-1;
  zmienp(move);
  iden=rysuj();
  wait4key();
  }
}
/*!
   * \brief medota klasy dron. Przesuwa drona w pionie, czyli z założeń wzdłuż osi Z o zadaną wartość
   */
void dron::przesunieciedronagora(double a){
  Wektor3D move;
  for(int i=0;i<abs(a);i++){
  /*if(iden!=1){
  bryla::api->erase_shape(iden);
  }*/
  if(a>0)move[2]=1;
  else move[2]=-1;
  zmienp(move);
  iden=rysuj();
  wait4key();
  }
}
/*!
   * \brief medota klasy dron. Z zalozenia obraca dronem o zadany kat
   */
void dron::obrot(double kat){
  /*bryla::api->erase_shape(iden);*/
  zmienkat(kat);
  uint am=rysuj();
}

uint dron::rysuj(){
  uint p=pscian::rysuj();
  uint w=lewus.rysuj();
 uint wi=prawus.rysuj();
  iden=p+w;
  return iden;
}
