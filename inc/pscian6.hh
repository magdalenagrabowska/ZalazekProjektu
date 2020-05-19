#pragma once


#include"Wektor3D.hh"
#include "Macierz3D.hh"
#include "pscian.hh"



class pscian6:public pscian{
protected:
char y;
uint wir=1;
Wektor3D wierzchy [12];
Wektor3D srodek=Wektor3D(0,0.5,0);
MacierzOb staly_obrot;
public:
pscian6(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[12], MacierzOb &orientacja):pscian(Api,transformacja,wej,orientacja){
for(int i=0;i<12;i++){
    wej[1]=wierzchy[i];
}
}
uint rysuj(){
if(wir!=1){
    api->erase_shape(wir);
}
pscian6 wirn(*this);
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
};


 

