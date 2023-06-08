#include "../include/DTEmpleado.h"
#include "../include/TipoCargo.h"

using namespace std;
#include <stdlib.h>

DTEmpleado::DTEmpleado() : DTUsuario()
{
    this->cargo = TipoCargo::SinCargo;
}

DTEmpleado::DTEmpleado(string nombre, string email, string contrasenia, TipoCargo cargo) : DTUsuario(nombre, email, contrasenia)
{
    this->cargo = cargo;
}

TipoCargo DTEmpleado::getCargo()
{
    return this->cargo;
}

DTEmpleado::~DTEmpleado()
{

}

void DTEmpleado::print(ostream &o)
{ 
    o << "Nombre del empleado: " << this->getNombre() << endl;
    o << "Email del empleado: " << this->getEmail() << endl;
    o << "Cargo del empleado: ";
    TipoCargo cargo = this->getCargo();
    switch (cargo)
    {
        case TipoCargo::Administracion:
        {
            o <<"Administrador"<< endl;
            break;
        }
        case TipoCargo::Limpieza:
        {
            o << "Limpieza" << endl;
            break;
        }
        case TipoCargo::Infraestructura:
        {
            o << "Infraestructura" << endl;
            break;
        }    
        case TipoCargo::Recepcion:
        {
            o << "Recepción" << endl;
            break;
        }    
        case TipoCargo::SinCargo:
        {
            o << "Sin Cargo" << endl;
            break;
        }
    }
}
