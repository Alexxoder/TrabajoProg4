#ifndef _FABRICA_H
#define _FABRICA_H

#include "InterfazUsuario.h"
#include "InterfazReserva.h"
#include "InterfazHostal.h"
#include "InterfazFecha.h"
#include "ControladorHostal.h"
#include "ControladorUsuario.h"
#include "ControladorReserva.h"
#include "FechaSistema.h"

class Fabrica
{
private:
    static Fabrica *instancia;
    Fabrica();
public:
    InterfazReserva* getInterfazReserva();
    InterfazHostal* getInterfazHostal();
    InterfazUsuario* getInterfazUsuario();
    InterfazFecha* getInterfazFecha();
    static Fabrica * getInstancia();
    ~Fabrica();
};

#endif