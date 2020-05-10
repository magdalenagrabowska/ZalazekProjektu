#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <vector>
#include "bryla.hh"
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include <fstream>

class pscian:public virtual bryla{
  protected:
  std::vector<Wektor3D<double,3>> _Wierz_lok=std::vector<Wektor3D<double,3>>(8);
  std::vector<Wektor3D<double,3>> _Wierz_glb=_Wierz_lok;
  public:
  bool obliczwsp()override;
  void zmienp(Wektor3D<double,3> M)override;
  void zmienkat(double KatOstr)override;
};
#endif