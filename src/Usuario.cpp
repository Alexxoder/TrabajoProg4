#include "../include/Usuario.h"

Usuario::Usuario()
{
    this->nombre = '0';
    this->email = '0';
    this->contrasenia = '0';
}

Usuario::Usuario(string nombre, string email, string contrasenia)
{
    this->nombre = nombre;
    this->email = email;
    this->contrasenia = contrasenia;
}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Usuario::setEmail(string email)
{
    this->email = email;
}

void Usuario::setContrasenia(string contra)
{
    this->contrasenia = contra;
}

string Usuario::getNombre()
{
    return this->nombre;
}

string Usuario::getEmail()
{
    return this->email;
}

string Usuario::getContrasenia()
{
    return this->contrasenia;
}

Usuario::~Usuario(){
    
}