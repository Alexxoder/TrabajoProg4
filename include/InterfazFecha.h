#ifndef _INTERFAZFECHA_H
#define _INTERFAZFECHA_H

#include "date.h"

class InterfazFecha
{
public:
    virtual void actualizarFecha(date) = 0;
    virtual ~InterfazFecha()
    {
    
    }
};

#endif