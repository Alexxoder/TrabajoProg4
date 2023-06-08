#ifndef _DTRESERVA_H
#define _DTRESERVA_H

#include "date.h"
#include "EstadoReserva.h"
#include <set>
#include <string>
#include <iostream>
using namespace std;

class DTReserva
{
private:
    int codigo;
    date checkIn, checkOut;
    EstadoReserva estado;
    int numHabitacion;
    float costo;
    set<string> colEmailsHuespedes;
public:
    //creates
    DTReserva();
    DTReserva(int, date, date, EstadoReserva, int, float, set<string>);
    
    //getters
    int getCodigo();
    date getCheckIn();
    date getCheckOut();
    EstadoReserva getEstado();
    int getNumHabitacion();
    float getCosto();
    set<string> getEmailsHuespedes();

    //setters
    void setCodigo(int);
    void setCheckIn(date);
    void setCheckOut(date);
    void setEstado(EstadoReserva);
    void setNumHabitacion(int);
    void setCosto(float);
    void setEmailsHuespedes(set<string>);
    //
};

ostream &operator<<(ostream &o, DTReserva &r);


#endif
