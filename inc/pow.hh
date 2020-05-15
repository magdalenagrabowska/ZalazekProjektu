#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include "bryla.hh"
#include"Wektor3D.hh"
#include "Macierz3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

class powierzchnia:public bryla{
protected:
Wektor3D punkt[4];
public:
uint powi;
powierzchnia(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D *wej, MacierzOb &orientacja):bryla(Api,transformacja,orientacja){
for(int i=0;i<4;i++){
    punkt[i]=wej[i];
}
rysuj();
}
void rysuj()override;
void usun(uint dr)override;
};

void powierzchnia::rysuj(){
    powierzchnia pow(*this);
for(unsigned int Ind; Ind<8;++Ind){
    pow.punkt[Ind]=punkt[Ind];
}
powi=api->draw_surface(vector<vector<drawNS::Point3D>> {{
    pow.punkt[0].zwrocpunkt(), pow.punkt[1].zwrocpunkt()
},{pow.punkt[2].zwrocpunkt(), pow.punkt[3].zwrocpunkt()}}, "blue");

}
void powierzchnia::usun(uint dr){
    api->erase_shape(dr);
}
#endif