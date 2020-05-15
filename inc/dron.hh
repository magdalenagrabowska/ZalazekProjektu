#ifndef DRON_HH
#define DRON_HH

#include "interfejs_drona.hh"
#include "pscian.hh"


class dron:public in_dron,public pscian{
public:
uint iden;
dron(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D *wej, MacierzOb &orientacja):pscian(Api,translacja,wej,orientacja){
   /* wej[0]=_Wierz_lok[0]=Wektor3D(-2,0,0);
    wej[1]=_Wierz_lok[1]=Wektor3D(-2,2,0);
    wej[2]=_Wierz_lok[2]=Wektor3D(1,2,0);
    wej[3]=_Wierz_lok[3]=Wektor3D(1,0,0);
    wej[4]=_Wierz_lok[4]=Wektor3D(-2,0,3);
    wej[5]=_Wierz_lok[5]=Wektor3D(-2,2,3);
    wej[6]=_Wierz_lok[6]=Wektor3D(1,2,3);
    wej[7]=_Wierz_lok[7]=Wektor3D(1,0,3);*/
  rysuj();
}
void wait4key();
void przesunieciedronabokl(double a)override;
void przesuneciedronaprzod(double a)override;
void przesunieciedronagora(double a)override;
void obrot(double kat);

};



#endif