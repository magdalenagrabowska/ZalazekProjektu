#include"pow.hh"
#include "dron.hh"
#include <iostream>
#include <vector>
#include <fstream>
#include "Dr3D_gnuplot_api.hh"
#include<fstream>
using std::fstream;
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
    wej[0]=Wektor3D(-2,0,0);
    wej[1]=Wektor3D(-2,2,0);
    wej[2]=Wektor3D(1,2,0);
    wej[3]=Wektor3D(1,0,0);
    wej[4]=Wektor3D(-2,0,3);
    wej[5]=Wektor3D(-2,2,3);
    wej[6]=Wektor3D(1,2,3);
    wej[7]=Wektor3D(1,0,3);
  dron dron(api,translacja,wej,ori);
    pow[0]=Wektor3D(-4,-4,-4);
    pow[1]=Wektor3D(-4,4,-4);
    pow[2]=Wektor3D(4,-4,-4);
    pow[3]=Wektor3D(4,4,-4);
 powierzchnia powi(api,translacja,pow,ori);
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
