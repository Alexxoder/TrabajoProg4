#include "../include/Huesped.h"

Huesped::Huesped() : Usuario()
{
    this->finger = false;
}

Huesped::Huesped(string nombre, string email, string contrasenia, bool finger) : Usuario(nombre, email, contrasenia)
{
    this->finger = finger;
}

bool Huesped::getEsFinger()
{
    return this->finger;
}

bool Huesped::esEmpleado()
{
    return false;
}

DTHuesped *Huesped::obtenerDTHuesped()
{
    DTHuesped *dt = new DTHuesped(getNombre(), getEmail(), getContrasenia(), getEsFinger());
    return dt;
}

DTUsuario* Huesped::obtenerDTUsuario()
{
    DTUsuario* res = this->obtenerDTHuesped();
    return res;
}