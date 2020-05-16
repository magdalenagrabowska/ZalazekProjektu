#ifndef WIRNIKI_HH
#define WIRNIKI_HH

#include "pscian.hh"
#include"Wektor3D.hh"
#include "Macierz3D.hh"


class wirnik:public pscian{
protected:
char y;
uint wir=1;
Wektor3D wierzchy [12];
Wektor3D srodek=Wektor3D(0,0.5,0);
MacierzOb staly_obrot = MacierzOb(y,1);
public:
wirnik(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[12], MacierzOb &orientacja):pscian(Api,transformacja,wej,orientacja){
for(int i=0;i<12;i++){
    wej[1]=wierzchy[i];
}
}
uint rysuj()override;
};

uint wirnik::rysuj(){
 if(wir!=1){
    api->erase_shape(wir);
}
wirnik wirn(*this);
for(unsigned int Ind=0; Ind<12;++Ind){
    wirn.wierzchy[Ind]=orientacja*wierzchy[Ind]+translacja; 
    _Wierz_glob[Ind]=wirn.wierzchy[Ind];
}
    id=api->draw_polyhedron(vector<vector<drawNS::Point3D> > {{
    wirn.wierzchy[0].zwrocpunkt(),wirn.wierzchy[1].zwrocpunkt(),wirn.wierzchy[2].zwrocpunkt(),wirn.wierzchy[3].zwrocpunkt(),
    wirn.wierzchy[4].zwrocpunkt(),wirn.wierzchy[5].zwrocpunkt()},{
    wirn.wierzchy[6].zwrocpunkt(),wirn.wierzchy[7].zwrocpunkt(), wirn.wierzchy[8].zwrocpunkt(),wirn.wierzchy[9].zwrocpunkt(),
     wirn.wierzchy[10].zwrocpunkt(),wirn.wierzchy[11].zwrocpunkt()
    }},"green");
return id;
}

class wirnik_lewy:public wirnik{
uint wirl=1;
public:
wirnik_lewy(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[12], MacierzOb &orientacja):wirnik(Api,transformacja,wej,orientacja){
   wierzchy[0]=Wektor3D(0,-3,1.5);
   wierzchy[1]=Wektor3D(0,-2.5,2) ;
   wierzchy[2]=Wektor3D(0,-1.5,2);
   wierzchy[3]=Wektor3D(0,-1,1.5) ;
   wierzchy[4]=Wektor3D(0,-1.5,1);
   wierzchy[5]=Wektor3D(0,-2.5,1) ;
   wierzchy[6]=Wektor3D(2,-3,1.5);
   wierzchy[7]=Wektor3D(2,-2.5,2) ;
   wierzchy[8]=Wektor3D(2,-1.5,2);
   wierzchy[9]=Wektor3D(2,-1,1.5) ;
   wierzchy[10]=Wektor3D(2,-1.5,1);
   wierzchy[11]=Wektor3D(2,-2.5,1) ;
   wirl=rysuj();
}

};






#endif