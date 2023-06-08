#ifndef _RESERVAINDIVIDUAL_H
#define _RESERVAINDIVIDUAL_H

#include "../include/Reserva.h"

class ReservaIndividual: public Reserva
{
public:
    //creates
    ReservaIndividual();
    ReservaIndividual(int, date, date, map<string, Huesped*>);
    ReservaIndividual(int, date, date, set<string>);
    ~ReservaIndividual();
    
    //opts del DC
    virtual float calcularCosto(int);
};

#endif
