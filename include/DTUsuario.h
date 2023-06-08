#ifndef _DTUSUARIO_H
#define _DTUSUARIO_H

using namespace std;
#include <string>

class DTUsuario
{
private:
    /* data */
    string nombre;
    string email;
    string contrasenia;

public:
    DTUsuario();
    DTUsuario(string nombre, string email, string contrasenia);
    void setNombre(string);
    void setEmail(string);
    void setContrasenia(string);
    string getNombre();
    string getEmail();
    string getContrasenia();
    virtual ~DTUsuario();
    
    virtual void print(ostream &o) = 0;
};

ostream &operator<<(ostream &o,  DTUsuario &u);

#endif