#ifndef _HABITACION_H
#define _HABITACION_H
#include "Reserva.h"
#include "DTEstadia.h"
#include "DTReserva.h"
#include "DTHabitacion.h"
#include <string>
#include <set>
#include <map>
using namespace std;

class Habitacion
{
private:
    int numero;
    float precio;
    int capacidad;
    map<int, Reserva*> colReservasHab;

    public:
    //creates
    Habitacion();
    Habitacion(int,float,int);
    ~Habitacion();
    
    //setters
    void setNumero(int);
    void setPrecio(float);
    void setCapacidad(int);
    
    //getters
    int getNumero();
    float getPrecio();
    int getCapacidad();
    
    //opts del DC
    bool estaDisponible(date,date);
    DTHabitacion* getDTHabitacion();
    void vincularReservaHabitacion(Reserva*);
    set<DTEstadia*> obtenerEstadiasFinalizadas(string);
    map<int, DTReserva*> obtenerReservas();
    map<int, DTReserva*> obtenerReservasNoCanceladas(string);
    set<DTEstadia*> obtenerEstadias();
    void desvincularReservaHabitacion(Reserva *res);
};

#endif
