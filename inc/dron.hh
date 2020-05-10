#ifndef DRON_HH
#define DRON_HH

#include "interfejs_drona.hh"
#include "pscian.hh"


class dron:public virtual in_dron,public pscian{
public:
void inicjalizacjadrona()override;
void przesunieciedronabokl(double a)override;
void przesuneciedronaprzod(double a)override;
void przesunieciedronagora(double a)override;
void wait4key();
};



#endif