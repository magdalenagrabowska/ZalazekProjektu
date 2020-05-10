
#include "dron.hh"
#include <iostream>
#include <vector>
#include <fstream>
#include "Dr3D_gnuplot_api.hh"


using std::cout;
using std::endl;
using std::cin;
using std::cerr;

int main(){
  dron dron;
  double a=0;
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
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    else dron.przesunieciedronabokl(a);
    break;
  }
  case '3':{
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
  case '4':{cout<<"podaj o ile chcesz przemieścić w gore.Uwaga:podanie dodatniej wartosci spowoduje przesuniecie w gore, a ujemnej w dol"<<endl;
    cin>>a;
    if(cin.fail()){
       cout<<"Blad. Program wroci sie do menu"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    else dron.przesunieciedronagora(a);
    break;}
  case '0':cout<<"koniec dzialania programu"<<endl;break;
  default:{
    cerr<<"Nierozpoznana opcja. Sprobuj ponownie albo uruchom program od poczatku"<<endl;
    }
  }
  }
}
