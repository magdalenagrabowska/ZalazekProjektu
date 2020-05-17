#ifndef WIRNIKI_HH
#define WIRNIKI_HH

#include "pscian6.hh"
#include"Wektor3D.hh"
#include "Macierz3D.hh"



class wirnik:public pscian6{
protected:
/*char y;
uint wir=1;
Wektor3D wierzchy [12];
Wektor3D srodek=Wektor3D(0,0.5,0);
MacierzOb staly_obrot = MacierzOb(y,1);*/
public:
wirnik(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[12], MacierzOb &orientacja):pscian6(Api,transformacja,wej,orientacja){
/*for(int i=0;i<12;i++){
    wej[1]=wierzchy[i];
}*/
}
/*uint rysuj();*/
};

/*uint wirnik::rysuj(){
 if(wir!=1){
    api->erase_shape(wir);
}
wirnik wirn(*this);
for(unsigned int Ind=0; Ind<12;++Ind){
    wirn.wierzchy[Ind]=orientacja*wierzchy[Ind]+translacja; 
}
    wir=api->draw_polyhedron(vector<vector<drawNS::Point3D> > {{
    wirn.wierzchy[0].zwrocpunkt(),wirn.wierzchy[1].zwrocpunkt(),wirn.wierzchy[2].zwrocpunkt(),wirn.wierzchy[3].zwrocpunkt(),
    wirn.wierzchy[4].zwrocpunkt(),wirn.wierzchy[5].zwrocpunkt()},{
    wirn.wierzchy[6].zwrocpunkt(),wirn.wierzchy[7].zwrocpunkt(), wirn.wierzchy[8].zwrocpunkt(),wirn.wierzchy[9].zwrocpunkt(),
     wirn.wierzchy[10].zwrocpunkt(),wirn.wierzchy[11].zwrocpunkt()
    }},"green");
return wir;
}

class wirnik_lewy:public wirnik{
public:
uint wirl=1;
wirnik_lewy(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[12], MacierzOb &orientacja):wirnik(Api,transformacja,wej,orientacja){
   wierzchy[0]=Wektor3D(-3,0,1.5);
   wierzchy[1]=Wektor3D(-2.5,0,2) ;
   wierzchy[2]=Wektor3D(-1.5,0,2);
   wierzchy[3]=Wektor3D(-1,0,1.5) ;
   wierzchy[4]=Wektor3D(-1.5,0,1);
   wierzchy[5]=Wektor3D(-2.5,0,1) ;
   wierzchy[6]=Wektor3D(-3,-2,1.5);
   wierzchy[7]=Wektor3D(-2.5,-2,2) ;
   wierzchy[8]=Wektor3D(-1.5,-2,2);
   wierzchy[9]=Wektor3D(-1,-2,1.5) ;
   wierzchy[10]=Wektor3D(-1.5,-2,1);
   wierzchy[11]=Wektor3D(-2.5,-2,1) ;
}
};

class wirnik_prawy:public wirnik{
uint wirp=1;
public:
wirnik_prawy(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[12], MacierzOb &orientacja):wirnik(Api,transformacja,wej,orientacja){
  
   wierzchy[0]=Wektor3D(-1,0,1.5);
   wierzchy[1]=Wektor3D(-0.5,0,2) ;
   wierzchy[2]=Wektor3D(0.5,0,2);
   wierzchy[3]=Wektor3D(1,0,1.5) ;
   wierzchy[4]=Wektor3D(0.5,0,1);
   wierzchy[5]=Wektor3D(-0.5,0,1) ;
   wierzchy[6]=Wektor3D(-1,-2,1.5);
   wierzchy[7]=Wektor3D(-0.5,-2,2) ;
   wierzchy[8]=Wektor3D(0.5,-2,2);
   wierzchy[9]=Wektor3D(1,-2,1.5) ;
   wierzchy[10]=Wektor3D(0.5,-2,1);
   wierzchy[11]=Wektor3D(-0.5,-2,1) ;
}
};
*/



#endif