#include "../include/Empleado.h"
using namespace std;
#include <stdlib.h>

Empleado::Empleado():Usuario()
{
    this->cargo= TipoCargo::SinCargo;
}

Empleado::Empleado(string nombre,string email,string contrasenia, TipoCargo cargo):Usuario(nombre,email, contrasenia)
{
    this->cargo = cargo;
}

Empleado::~Empleado()
{
    this->eliminarNotificaciones();
}

//setters
void Empleado::setCargo(TipoCargo cargo)
{
    this->cargo = cargo;
}

void Empleado::setHostal(Hostal* h)
{
    this->hostal = h;
}

//getters
Hostal* Empleado::getHostal()
{
    return this->hostal;
}

TipoCargo Empleado::getCargo()
{
    return this->cargo;
}

//operaciones
bool Empleado::esEmpleado()
{
    return true;
}

void Empleado::notificar(int nota, string comentario,string emailHuesped)
{
   Notificacion *notif = new Notificacion(emailHuesped, nota, comentario);
   colNotificaciones.insert(notif);
}

void Empleado::suscribirse()
{
    Hostal* hostal = this->getHostal();
    hostal->agregarSuscrito(this);
}

set<Notificacion*> Empleado::getNotificaciones()
{
    return this->colNotificaciones;
}

void Empleado::eliminarNotificaciones()
{
    set<Notificacion*>::iterator it;
    for (it = colNotificaciones.begin(); it != colNotificaciones.end(); ++it)
    {
       delete *it;
    }
    colNotificaciones.clear();

}

void Empleado::desuscribir()
{
    Hostal * hostal = getHostal();
    hostal->eliminarEmpleadoSuscrito(this);
}

DTUsuario* Empleado::obtenerDTUsuario()
{
    DTUsuario* res = new DTEmpleado(this->getNombre(), this->getEmail(), this->getContrasenia(), this->cargo);
    return res;
}


set <DTCalificacion*> Empleado::obtenerComentariosSinResponder ()
{
    return hostal->obtenerComentariosSinResponder();
}