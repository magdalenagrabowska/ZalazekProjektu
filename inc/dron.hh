#ifndef DRON_HH
#define DRON_HH

#include "interfejs_drona.hh"
#include "pscian.hh"


class dron:public virtual in_dron,public pscian{
public:
void inicjalizacjadrona()override;
void przesunieciedronawbok(int a)override;
void przesuneciedronaprzod(int a)override;
void przesunieciedronagora(int a)override;
void wait4key();
};



#endif