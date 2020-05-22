#ifndef DRON_HH
#define DRON_HH

#include "interfejs_drona.hh"
#include "pscian.hh"
#include "wirniki.hh"
#include "Macierz3D.hh"
#include "interfejs_przeszkody.hh"

class dron:public in_dron,public pscian,public przeszkoda{
public:
wirnik_lewy prawus;
wirnik_prawy lewus;
int iden=-1;
dron(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[8],Wektor3D wirusl[12],Wektor3D wirusp[12],MacierzOb &orientacja):pscian(Api,transformacja,wej,orientacja),lewus(Api,transformacja,wirusl,orientacja),prawus(Api,transformacja,wirusp,orientacja){
 
} 
void wait4key();
void przesunieciedronabokl(double a)override;
void przesuneciedronaprzod(double a)override;
void przesunieciedronagora(double a)override;
int obrot(double kat);
/*bool czy_kolizja(in_dron) override{};*/
int rysuj();
};

class dron2:public dron{
  int dronik=-1;
public:
dron2(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[8],Wektor3D wirusl[12],Wektor3D wirusp[12],MacierzOb &orientacja):dron(Api,transformacja,wej,wirusl,wirusp,orientacja){
 dronik=rysuj();
 api->change_shape_color(dronik,"light-blue");
}
int rysuj(){
  _Wierz_lok[0]=Wektor3D(4,11,-5);  
  _Wierz_lok[1]=Wektor3D(4,13,-5);  
  _Wierz_lok[2]=Wektor3D(8,13,-5);     
  _Wierz_lok[3]=Wektor3D(8,11,-5);     
  _Wierz_lok[4]=Wektor3D(4,11,-2);   
  _Wierz_lok[5]=Wektor3D(4,13,-2);    
  _Wierz_lok[6]=Wektor3D(8,13,-2);   
 _Wierz_lok[7]=Wektor3D(8,11,-2);
  int p=pscian::rysuj();
  /*int w=lewus.rysuj();
  int wi=prawus.rysuj();*/
  dronik=p/*+w+wi*/;
  return dronik;
}
};


#endif