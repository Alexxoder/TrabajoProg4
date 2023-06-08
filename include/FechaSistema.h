#ifndef _FechaSistema_H
#define _FechaSistema_H

#include "InterfazFecha.h"
using namespace std;


//interface
class FechaSistema: public InterfazFecha
{
private:
    static FechaSistema *instancia;

    date fecha;
    FechaSistema();
    FechaSistema(date);
    
public:
    ~FechaSistema();
    static FechaSistema* getInstancia(); 
    virtual void actualizarFecha(date);
    void setFecha(date);
    date getFecha();
};

#endif