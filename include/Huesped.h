#ifndef _HUESPED_H
#define _HUESPED_H

#include "Usuario.h"
#include "DTHuesped.h"

#include <string>
using namespace std;

class Huesped : public Usuario
{
private:
    bool finger;

public:
    //creates
    Huesped();
    Huesped(string nombre, string email, string contrasenia, bool finger);
    
    //opts del DC
    bool getEsFinger();
    virtual bool esEmpleado();
    DTHuesped *obtenerDTHuesped();
    virtual DTUsuario* obtenerDTUsuario();
};

#endif
