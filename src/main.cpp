#include"pow_morza.hh"
#include "dron.hh"
#include <iostream>
#include <vector>
#include <fstream>
#include "Dr3D_gnuplot_api.hh"
#include<fstream>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

int main(){
  drawNS::APIGnuPlot3D *api=new drawNS::APIGnuPlot3D(-20,20,-20,20,-20,20,0);
  Wektor3D translacja;
  MacierzOb ori;
  Wektor3D pow[4];
  Wektor3D wej[8];
  Wektor3D wirnikl[12];
  Wektor3D wirnikp[12];
  dron dron(api,translacja,wej,wirnikl,wirnikp,ori);
  pow_dna dno(api,translacja,pow,ori);
  pow_morza powi(api,translacja,pow,ori);
  dron.rysuj();
  double a=0;
  char wybor[2] = " ";
  while (wybor[0]!='0'){
  cout<<"Menu"<<endl;
  cout<<"1-przemieść drona w bok"<<endl;
  cout<<"2-przemieść drona w przod"<<endl;
  cout<<"3-przemiesc drona w górę"<<endl;
  cout<<"4-obrot drona"<<endl;
  cout<<"0-koniec programu"<<endl;

  cout<<"Twoj wybor"<<endl;

  cin>>wybor;

  switch(wybor[0]){
  case '1':{
    cout<<"podaj o ile chcesz przemieścić w bok.Uwaga:podanie dodatniej wartosci spowoduje przesuniecie w prawo, a ujemnej w lewo"<<endl;
    cin>>a;
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    else dron.przesunieciedronabokl(a);
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
    else dron.przesuneciedronaprzod(a);
    break;
  }
  case '3':{cout<<"podaj o ile chcesz przemieścić w gore.Uwaga:podanie dodatniej wartosci spowoduje przesuniecie w gore, a ujemnej w dol"<<endl;
    cin>>a;
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    else dron.przesunieciedronagora(a);
    break;}
  case '4':{cout<<"podaj o ile chcesz obrocic drona. Uwaga:kat jest podawany w stopniach"<<endl;
    cin>>a;
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    else dron.obrot(a);
    break;}
  
  case '0':cout<<"koniec dzialania programu"<<endl;break;
  default:{
    cerr<<"Nierozpoznana opcja. Sprobuj ponownie albo uruchom program od poczatku"<<endl;
    }
  }
  }
}
