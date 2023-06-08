#ifndef _DTHOSTAL_H
#define _DTHOSTAL_H

#include "DTCalificacion.h"
#include "DTReserva.h"
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class DTHostal
{
private:
    string nombre;
    string direccion;
    string telefono;

public:
    // creates
    DTHostal();
    DTHostal(string, string, string);

    // getters
    string getNombre();
    string getDireccion();
    string getTelefono();

    // setters
    void setNombre(string nombre);
    void setDireccion(string direccion);
    void setTelefono(string telefono);
};

ostream &operator<<(ostream &o, DTHostal &h);

class DTHostalExtendido
{
private:
    string nombre;
    string direccion;
    string telefono;
    float calificacionPromedio;
    set<int> numerosHabitaciones;
    set<DTCalificacion*> colDTCalificacion;
    map<int, DTReserva*> colDTReserva;

public:
    //creates
    DTHostalExtendido(string nombre, string direccion, string telefono, float calfPromedio, set<int> numerosHabitaciones, set<DTCalificacion*> colDTCalif, map<int, DTReserva*> colDTReserva);
    
    //getters
    string getNombre();
    string getDireccion();
    string getTelefono();
    float getCalificacionPromedio();
    set<int> getNumHabitaciones();
    set<DTCalificacion*> getCalificaciones();
    map<int, DTReserva*> getReservas();

    // setters
    void setNombre(string nombre);
    void setDireccion(string direccion);
    void setTelefono(string telefono);
    void setCalificacionPromedio(float califProm);
    void setNumHabitaciones(set<int> numerosHabitaciones);
    void setCalificaciones(set<DTCalificacion*> colDTCalif);
    void setReservas(map<int, DTReserva*> colDTReserva);
};

ostream &operator<<(ostream &o, DTHostalExtendido &h);

#endif
