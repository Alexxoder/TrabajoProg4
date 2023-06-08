#ifndef _SUSCRITO_H
#define _SUSCRITO_H

#include "Calificacion.h"
#include <string>
using namespace std;

//interface
class Suscrito
{
public:
    virtual void notificar(int nota, string comentario ,string emailHuesped) = 0;
};

#endif