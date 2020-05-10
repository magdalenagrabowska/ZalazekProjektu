#include "pscian.hh"
#include <fstream>
using namespace std;

bool pscian::obliczwsp(){
    ifstream strmwej;
    strmwej.open("wspolrzedne_robota.dat");
    ofstream strmwyj;
    strmwyj.open("wyjsciowe_wsp.dat");

    if(!strmwej.is_open() || !strmwyj.is_open()) return false;
    /*zmienkat(KatOstr);*/
   for(unsigned int Ind; Ind<8;++Ind){
       strmwej>>_Wierz_lok[Ind];
       strmwyj<<(/*orientacja**/_Wierz_lok[Ind]+translacja)<<endl;
   }
   return !strmwej.fail() && !strmwyj.fail();
}
void pscian::zmienp(Wektor3D<double,3> M){
 translacja=translacja+M;
}
void pscian::zmienkat(double KatOstr){
   /* orientacja=orientacja*KatOstr;*/
}