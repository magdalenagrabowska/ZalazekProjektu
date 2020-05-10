#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <vector>
#include "bryla.hh"
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include <fstream>

class pscian:public virtual bryla{
  protected:
  std::vector<Wektor3D<double,3>> _Wierz_lok;
  public:
  pscian();
  void obliczwsp()override;
  void zmienp(const Wektor3D<double,3> &M)override;
  void zmienkat(const double KatOstr)override;
};
#endif