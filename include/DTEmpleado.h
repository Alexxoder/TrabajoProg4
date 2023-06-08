#ifndef _DTEMPLEADO_H
#define _DTEMPLEADO_H

#include "DTUsuario.h"
#include "TipoCargo.h"
#include <iostream>
using namespace std;

class DTEmpleado : public DTUsuario
{
private:
    TipoCargo cargo;

public:
    DTEmpleado();
    DTEmpleado(string nombre, string email, string contrasenia, TipoCargo cargo);
    TipoCargo getCargo();
    ~DTEmpleado();

    virtual void print(ostream &o);
};

#endif