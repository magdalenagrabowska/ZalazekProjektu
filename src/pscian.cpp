#include "pscian.hh"
#include <fstream>
#include<vector>
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::vector;


void pscian::rysuj(){
pscian psian(*this);
for(unsigned int Ind; Ind<8;++Ind){
    psian._Wierz_lok[Ind]=orientacja*_Wierz_lok[Ind]+translacja; 
    _Wierz_glob[Ind]=psian._Wierz_lok[Ind];
}
    id=api->draw_polyhedron(vector<vector<drawNS::Point3D> > {{
    psian._Wierz_lok[0].zwrocpunkt(),psian._Wierz_lok[1].zwrocpunkt(),psian._Wierz_lok[2].zwrocpunkt(),psian._Wierz_lok[3].zwrocpunkt()
    },{
    psian._Wierz_lok[4].zwrocpunkt(),psian._Wierz_lok[5].zwrocpunkt(),psian._Wierz_lok[6].zwrocpunkt(),psian._Wierz_lok[7].zwrocpunkt()
    }},"green");
for(unsigned int Ind; Ind<8;++Ind){
    _Wierz_lok[Ind]=_Wierz_glob[Ind];
}
}

void pscian::usun(uint dr){
    api->erase_shape(dr);
}
void pscian::rysujodtylu(uint dr){
    usun(dr);
    rysuj();
}


   
