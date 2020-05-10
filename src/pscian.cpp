#include "pscian.hh"
#include <fstream>
using namespace std;
pscian::pscian(){
    ifstream strmwej;
    strmwej.open("wspolrzedne_robota.dat");
    if(!strmwej.is_open()){
        cerr<<"cos jest nie tak!"<<endl;
        exit(1);
    }
    Wektor3D<double,3> punkt;
    while(strmwej>>punkt){
        _Wierz_lok.push_back(punkt);
    }
  strmwej.close();
}
void pscian::obliczwsp(){
    
    ofstream strmwyj;
    strmwyj.open("wyjsciowe_wsp.dat");

    if(!strmwyj.is_open()){
        cerr<<"cos jest nie tak!"<<endl;
        exit(1);
    }
    zmienkat(KatOstr);
   for(unsigned int Ind; Ind<_Wierz_lok.size();++Ind){
       strmwyj<<(/*orientacja**/_Wierz_lok[Ind]+translacja)<<endl; // na razie macierz obrotowa jeszcze nie jest potrzebna
   }
  strmwyj.close();
}
void pscian::zmienp(const Wektor3D<double,3> &M){
 translacja=translacja+M;
}
void pscian::zmienkat(const double KatOstr){
    orientacja=orientacja*KatOstr;
}