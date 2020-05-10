#include "dron.hh"
#include <iostream>
#include<vector>
#include "Dr3D_gnuplot_api.hh"
#include<cmath>

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void dron::wait4key(){
  do {
    std::cout << "\n Press w to continue..." << std::endl;
  } while(std::cin.get() != 'w');
}

void dron::inicjalizacjadrona(){
 
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,1000)); //włacza gnuplota, pojawia się scena [-10,10] x [-10,10] x [-10,10] odświeżana co 1000 ms
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(-2,0,0), drawNS::Point3D(-2,2,0), drawNS::Point3D(1,2,0),
  drawNS::Point3D(1,0,0)
      },{
	drawNS::Point3D(-2,0,3), drawNS::Point3D(-2,2,3), drawNS::Point3D(1,2,3),
  drawNS::Point3D(1,0,3)      
	  }},"blue");//rysuje niebieski graniastosłup
  wait4key();
}
void dron::przesuneciedronaprzod(double a){
  pscian();
  Wektor3D<double,3> move;
  move[1]=a;
  zmienp(move);
  obliczwsp();
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,1000)); //włacza gnuplota, pojawia się scena [-10,10] x [-10,10] x [-10,10] odświeżana co 1000 ms
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  for(int i=0;i<abs(a);i++){
  if(a<0){
  int dr=api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(-2,0+i,0), drawNS::Point3D(-2,2+i,0), drawNS::Point3D(1,2+i,0),
  drawNS::Point3D(1,0+i,0)
      },{
	drawNS::Point3D(-2,0+i,3), drawNS::Point3D(-2,2+i,3), drawNS::Point3D(1,2+i,3),
  drawNS::Point3D(1,0+i,3)      
	  }},"purple");//rysuje niebieski graniastosłup
    wait4key();
   api->erase_shape(dr);
  }
  else{
    int dr=api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(-2,0-i,0), drawNS::Point3D(-2,2-i,0), drawNS::Point3D(1,2-i,0),
  drawNS::Point3D(1,0-i,0)
      },{
	drawNS::Point3D(-2,0-i,3), drawNS::Point3D(-2,2-i,3), drawNS::Point3D(1,2-i,3),
  drawNS::Point3D(1,0-i,3)      
	  }},"purple");//rysuje niebieski graniastosłup
    wait4key();
   api->erase_shape(dr); 
  }
    }
}

void dron::przesunieciedronabokl(double a){
  pscian();
  Wektor3D<double,3> move;
  move[0]=a;
  zmienp(move);
  obliczwsp();
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,1000)); //włacza gnuplota, pojawia się scena [-10,10] x [-10,10] x [-10,10] odświeżana co 1000 ms
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  for(int i=0;i<abs(a);i++){
    if(a>0){
    int dr=api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(-2+i,0,0), drawNS::Point3D(-2+i,2,0), drawNS::Point3D(1+i,2,0),
  drawNS::Point3D(1+i,0,0)
      },{
	drawNS::Point3D(-2+i,0,3), drawNS::Point3D(-2+i,2,3), drawNS::Point3D(1+i,2,3),
  drawNS::Point3D(1+i,0,3)      
	  }},"black");
    wait4key();
   api->erase_shape(dr);
  }
 else
    {
  int dr=api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(-2-i,0,0), drawNS::Point3D(-2-i,2,0), drawNS::Point3D(1-i,2,0),
  drawNS::Point3D(1-i,0,0)
      },{
	drawNS::Point3D(-2-i,0,3), drawNS::Point3D(-2-i,2,3), drawNS::Point3D(1-i,2,3),
  drawNS::Point3D(1-i,0,3)      
	  }},"black");//rysuje niebieski graniastosłup
    wait4key();
   api->erase_shape(dr);
    }
}
}
void dron::przesunieciedronagora(double a){
  pscian();
  Wektor3D<double,3> move;
  move[2]=a;
  zmienp(move);
  obliczwsp();
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,1000)); //włacza gnuplota, pojawia się scena [-10,10] x [-10,10] x [-10,10] odświeżana co 1000 ms
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  for(int i=0;i<abs(a);i++){
    if(a>0){
    int dr=api->draw_polyhedron(vector<vector<Point3D>> {{
	drawNS::Point3D(-2,0,0+i), drawNS::Point3D(-2,2,0+i), drawNS::Point3D(1,2,0+i),
  drawNS::Point3D(1,0,0+i)
      },{
	drawNS::Point3D(-2,0,3+i), drawNS::Point3D(-2,2,3+i), drawNS::Point3D(1,2,3+i),
  drawNS::Point3D(1,0,3+i)      
	  }},"green");
   wait4key();
   api->erase_shape(dr);
  }
  else{int dr=api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(-2,0,0-i), drawNS::Point3D(-2,2,0-i), drawNS::Point3D(1,2,0-i),
  drawNS::Point3D(1,0,0-i)
      },{
	drawNS::Point3D(-2,0,3-i), drawNS::Point3D(-2,2,3-i), drawNS::Point3D(1,2,3-i),
  drawNS::Point3D(1,0,3-i)      
	  }},"green");//rysuje niebieski graniastosłup
    wait4key();
   api->erase_shape(dr);
  }
  }
}
