#include"pow_morza.hh"
#include "dron.hh"
#include <iostream>
#include <vector>
#include <fstream>
#include "Dr3D_gnuplot_api.hh"
#include<fstream>
#include "interfejs_przeszkody.hh"
#include <math.h>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

//modyfikacja modułu na tydzień 2

int main(){
  drawNS::APIGnuPlot3D *api=new drawNS::APIGnuPlot3D(-20,20,-20,20,-20,20,0);
  Wektor3D translacja;
  MacierzOb ori;
  Wektor3D pow[4];
  Wektor3D wej[8];
  Wektor3D wirnikl[12];
 Wektor3D trans=Wektor3D(10,11,-5); 
 Wektor3D tran=Wektor3D(10,15,-10);
 Wektor3D tansik=Wektor3D(-9,-5,12);
  vector<std::shared_ptr<przeszkodapscian>> kolekcja_przeszkod{
    std::make_shared<przeszkodapscian>(api,translacja,wej,ori), 
    std::make_shared<przeszkodapscian>(api,tran,wej,ori),
    std::make_shared<przeszkodapscian>(api,tansik,wej,ori)

  };
  vector<std::shared_ptr<in_dron>> kolekcja_Dronow;
    std::shared_ptr<dron> dronik1=std::make_shared<dron>(api,translacja,wej,wirnikl,wirnikl,ori);
    kolekcja_Dronow.push_back(dronik1);
    std:shared_ptr<dron> dronik2=std::make_shared<dron>(api,trans,wej,wirnikl,wirnikl,ori);
    kolekcja_Dronow.push_back(dronik2);
  pow_dna dno(api,translacja,pow,ori);
  pow_morza powi(api,translacja,pow,ori);
  double a=0;
  int nr=0;
  char wybor[2] = " ";
  cout<<"Menu"<<endl;
  cout<<"podaj numer drona. Dostępny jest 0 albo 1"<<endl;
  cin>>nr;
  if(nr<0 || nr>1)
  cin.fail();
  if(cin.fail()){
       cout<<"Blad.Nie ma takiego drona"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
  }
  while (wybor[0]!='0'){
  cout<<"Menu"<<endl;
  cout<<"1-zmien drona"<<endl;
  cout<<"2-przemieść drona w przod"<<endl;
  cout<<"3-przemiesc drona w górę"<<endl;
  cout<<"4-obrot drona"<<endl;
  cout<<"0-koniec programu"<<endl;

  cout<<"Twoj wybor"<<endl;

  cin>>wybor;

  switch(wybor[0]){
   case '1':{
     cout<<"nastąpi zmiana dronow do kierowania"<<endl;
     if(nr==0)
     nr=1;
     else nr=0;
     if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    break;
  }
  case '2':{
    cout<<"podaj o ile chcesz przemieścić w przod.Uwaga:podanie dodatniej wartosci spowoduje przesuniecie w tyl, a ujemnej w przod"<<endl;
    cin>>a;
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    for(int i=0;i<abs(a);i++){
    if(a>0)
    kolekcja_Dronow[nr]->przesuneciedronaprzod(1);
    else kolekcja_Dronow[nr]->przesuneciedronaprzod(-1);
    for(int j=0;j<kolekcja_przeszkod.size();++j){
    bool podroz=kolekcja_przeszkod[j]->czy_kolizja(kolekcja_Dronow[nr]);
    if(podroz==false)
    {
      cerr<<"kolizja drona"<<endl;
      exit(1);
    }
    }
    }
    break;
  }
  
  case '3':{cout<<"podaj o ile chcesz przemieścić w gore.Uwaga:podanie dodatniej wartosci spowoduje przesuniecie w gore, a ujemnej w dol"<<endl;
    cin>>a;
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    for(int i=0;i<abs(a);i++){
    if(a>0)
    kolekcja_Dronow[nr]->przesunieciedronagora(1);
    else kolekcja_Dronow[nr]->przesunieciedronagora(-1);
    bool podroz=dno.czy_kolizja(kolekcja_Dronow[nr]);
    if(podroz==false)
    {
      cerr<<"kolizja drona"<<endl;
      exit(1);
    }
    podroz=powi.czy_kolizja(kolekcja_Dronow[nr]);
    if(podroz==false)
    {
      cerr<<"kolizja drona"<<endl;
      exit(1);
    }
    }
    break;}
  
  case '4':{

    cout<<"podaj o ile chcesz obrocic drona. Uwaga:kat jest podawany w stopniach"<<endl;
    cin>>a;
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
   else int w=kolekcja_Dronow[nr]->obrot(a);
    break;}
  
  case '0':{cout<<"koniec dzialania programu"<<endl;break;
  }
  default:{
    cerr<<"Nierozpoznana opcja. Sprobuj ponownie albo uruchom program od poczatku"<<endl;
    }
   } //koniec switch
 } //koniec while
}


