#include "../include/DTHuesped.h"

DTHuesped::DTHuesped() : DTUsuario()
{
    this->finger = false;
}

DTHuesped::DTHuesped(string nombre, string email, string contrasenia, bool finger) : DTUsuario(nombre, email, contrasenia)
{
    this->finger = finger;
}

bool DTHuesped::esFinger()
{
    return this->finger;
}

DTHuesped::~DTHuesped()
{

}

void DTHuesped::print(ostream &o)
{
    o << "Nombre Huesped: " << this->getNombre() << endl;
    o << "Email Huesped: " << this->getEmail() << endl;
    if (this->esFinger())
        o << "Es Finger: Si" << endl;
    else
        o << "Es Finger: No" << endl;
}
