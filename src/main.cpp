
#include "dron.hh"
#include <iostream>
#include <vector>
#include <fstream>
#include "Dr3D_gnuplot_api.hh"


using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using std::cin;


int main(){
  
 /*std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,1000)); //włacza gnuplota, pojawia się scena [-10,10] x [-10,10] x [-10,10] odświeżana co 1000 ms
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  
 void wait4key(){
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}*/
  dron dron;
  int a=0;
  char wybor[2] = " ";
  while (wybor[0]!='0'){
  cout<<"Menu"<<endl;;
  cout<<"1-Pokaż drona"<<endl;;
  cout<<"2-przemieść drona w bok"<<endl;
  cout<<"3-przemieść drona w przod"<<endl;;
  cout<<"4-przemiesc drona w górę"<<endl;;
  cout<<"0-koniec programu"<<endl;;

  cout<<"Twoj wybor"<<endl;;

  cin>>wybor;

  switch(wybor[0]){
  case '1':{
  dron.inicjalizacjadrona();
  break;
  }
  case '2':{
    cout<<"podaj o ile chcesz przemieścić w bok.Uwaga:podanie dodatniej wartosci spowoduje przesuniecie w prawo, a ujemnej w lewo"<<endl;
    cin>>a;
    dron.przesunieciedronawbok(a);
    break;
  }
  case '3':{
    cout<<"podaj o ile chcesz przemieścić w przod.Uwaga:podanie dodatniej wartosci spowoduje przesuniecie w przod, a ujemnej w tyl"<<endl;
    cin>>a;
    dron.przesuneciedronaprzod(a);
    break;
  }
  case '4':{cout<<"podaj o ile chcesz przemieścić w gore.Uwaga:podanie dodatniej wartosci spowoduje przesuniecie w gore, a ujemnej w dol"<<endl;
    cin>>a;
    dron.przesunieciedronagora(a);
    break;}
  case '0':cout<<"koniec dzialania programu"<<endl;break;
   }
     }
   }
