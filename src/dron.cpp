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

void dron::wait4key(){
  do {
    std::cout << "\n Press w to continue..." << std::endl;
  } while(std::cin.get() != 'w');
}

void dron::przesuneciedronaprzod(double a){
  Wektor3D move;
  move[1]=a;
  zmienp(move);
 rysuj();
  wait4key();
}

void dron::przesunieciedronabokl(double a){
  Wektor3D move;
  move[0]=a;
  zmienp(move);
  rysuj();
  wait4key();
}
void dron::przesunieciedronagora(double a){
  Wektor3D move;
  move[2]=a;
  zmienp(move);
  rysuj();
  wait4key();

}

void dron::obrot(double kat){
  zmienkat(kat);
  rysuj();
}