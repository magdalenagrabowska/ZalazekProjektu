#ifndef INTERFEJS_PRZESZKODY_HH
#define INTERFEJS_PRZESZKODY_HH

#include<vector>
#include "interfejs_drona.hh"
#include "dron.hh"
#include "Macierz3D.hh"
#include "Wektor3D.hh"
#include "pscian.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

class przeszkoda{
public:
virtual bool czy_kolizja(std::shared_ptr<in_dron> dronus)=0;
};

class przeszkodapscian:public przeszkoda,public pscian{
public:
przeszkodapscian(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[8], MacierzOb &orientacja):pscian(Api,transformacja,wej,orientacja){
_Wierz_lok[0]=Wektor3D(-10,-11,0);
_Wierz_lok[1]=Wektor3D(-10,-2,0);
_Wierz_lok[2]=Wektor3D(-8,-2,0);
_Wierz_lok[3]=Wektor3D(-8,-11,0);
_Wierz_lok[4]=Wektor3D(-10,-11,5);
_Wierz_lok[5]=Wektor3D(-10,-2,5);
_Wierz_lok[6]=Wektor3D(-8,-2,5);
_Wierz_lok[7]=Wektor3D(-8,-11,5);  
 int var1=rysuj();
 api->change_shape_color(var1,"black");
}
int przesz=-1;
bool czy_kolizja(std::shared_ptr<in_dron> dronus) override{
float x=7;
float y=14;
float z=8;
float r=dronus->zwroc_srednice();
Wektor3D wek=dronus->zwroc_translacje();
float dlugosc=wek.dlugosc();
for(int i=0;i<8;i++){
  Wektor3D wekus=wek-_Wierz_lok[i];
  float dl=wekus.dlugosc();
  if(dl<r)  
  return false;
  else ;
}
if(x/2-wek[0]<r)
return false;
else if(y/2-wek[1]<r)
return false;
else if(z/2-wek[2]<r)
return false;
else
return true;
}
};

#endif