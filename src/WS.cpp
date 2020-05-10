#include "Wektor3D.cpp"
#include "Macierz3D.cpp"
#include "rozmiar.h"
using namespace std;

template class Wektor3D<double,ROZMIAR>;
template istream & operator>> (istream & strm, Wektor3D<double,ROZMIAR>&Wek);
template ostream & operator<< (ostream & strm,const Wektor3D<double,ROZMIAR>&Wek);
template Wektor3D<double, ROZMIAR> operator * (double l1, Wektor3D<double,ROZMIAR> W2);

template class MacierzKw3D<double,ROZMIAR>;
template istream & operator>>(istream & strm, MacierzKw3D<double,ROZMIAR> &Mac);
template ostream & operator<<(ostream & strm,const MacierzKw3D<double,ROZMIAR> &Mac);


