#ifndef _DTHUESPED_H
#define _DTHUESPED_H

#include "DTUsuario.h"
#include <iostream>
using namespace std;

class DTHuesped : public DTUsuario
{
private:
    bool finger;

public:
    DTHuesped();
    DTHuesped(string nombre, string email, string contrasenia, bool finger);
    bool esFinger();
    ~DTHuesped();

    virtual void print(ostream &o);
};

#endif