#ifndef _DTESTADIA_H
#define _DTESTADIA_H

#include "date.h"
#include <string>
#include <iostream>

using namespace std;


class DTEstadia
{
private:
    string huesped;
    int reserva;
    date entrada;
    date salida;
    string hostal;
    int habitacion;

public:
    DTEstadia();
    DTEstadia(string, int, date, date, string, int);

    /*getters*/
    string getHuesped();
    int getReserva();
    date getEntrada();
    date getSalida();
    string getHostal();
    int getHabitacion();

    /*setters*/
    void setHuesped(string);
    void setReserva(int);
    void setEntrada(date);
    void setSalida(date);
    void setHostal(string);
    void setHabitacion(int);

};

ostream &operator<<(ostream &o,  DTEstadia &e);

#endif

