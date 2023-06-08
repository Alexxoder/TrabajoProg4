#include "../include/DTUsuario.h"

DTUsuario::DTUsuario()
{
    this->nombre = '0';
    this->email = '0';
    this->contrasenia = '0';
}

DTUsuario::DTUsuario(string nombre, string email, string contrasenia)
{
    this->nombre = nombre;
    this->email = email;
    this->contrasenia = contrasenia;
}

void DTUsuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

void DTUsuario::setEmail(string email)
{
    this->email = email;
}

void DTUsuario::setContrasenia(string contra)
{
    this->contrasenia = contra;
}

string DTUsuario::getNombre()
{
    return this->nombre;
}

string DTUsuario::getEmail()
{
    return this->email;
}

string DTUsuario::getContrasenia()
{
    return this->contrasenia;
}

DTUsuario::~DTUsuario()
{

}

ostream &operator<<(ostream &o, DTUsuario &u)
{   
    u.print(o);
    return o;
}
