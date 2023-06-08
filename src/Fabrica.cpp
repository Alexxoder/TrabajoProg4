#include "../include/Fabrica.h"

Fabrica * Fabrica::instancia = NULL;

Fabrica::Fabrica()
{

}

Fabrica::~Fabrica() 
{
    InterfazHostal *iHostal = instancia->getInterfazHostal();
    delete iHostal;
    InterfazReserva *iReserva = instancia->getInterfazReserva();
    delete iReserva;
    InterfazUsuario *iUsuario = instancia->getInterfazUsuario();
    delete iUsuario;
    InterfazFecha *iFecha = instancia->getInterfazFecha();
    delete iFecha;
}

Fabrica * Fabrica::getInstancia() 
{
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}

//hacer subsumption
InterfazReserva* Fabrica::getInterfazReserva() 
{
    return ControladorReserva::getInstancia();
}

InterfazHostal* Fabrica::getInterfazHostal() 
{
    return ControladorHostal::getInstancia();
}

InterfazUsuario* Fabrica::getInterfazUsuario() 
{
    return ControladorUsuario::getInstancia();
}

InterfazFecha* Fabrica::getInterfazFecha()
{
    return FechaSistema::getInstancia();
}