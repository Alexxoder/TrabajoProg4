#ifndef _USUARIO_H
#define _USUARIO_H

#include "DTUsuario.h"
using namespace std;
#include <string>
class Usuario
{
private:
    string nombre;
    string email;
    string contrasenia; 

public:
    Usuario();
    Usuario(string nombre,string email,string contrasenia);
    void setNombre(string);
    void setEmail(string);
    void setContrasenia(string);
    string getNombre();
    string getEmail();
    string getContrasenia();
    virtual bool esEmpleado() = 0;
    virtual ~Usuario();

    virtual DTUsuario* obtenerDTUsuario() = 0;
};

#endif
