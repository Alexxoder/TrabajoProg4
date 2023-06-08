#include "../include/DTHostal.h"

// creates
DTHostal::DTHostal()
{
    this->nombre = "";
    this->direccion = "";
    this->telefono = "";
}

DTHostal::DTHostal(string nombre, string direccion, string telefono)
{
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
}

// getters
string DTHostal::getNombre()
{
    return this->nombre;
}

string DTHostal::getDireccion()
{
    return this->direccion;
}

string DTHostal::getTelefono()
{
    return this->telefono;
}

// setters
void DTHostal::setNombre(string nombre)
{
    this->nombre = nombre;
}

void DTHostal::setDireccion(string direccion)
{
    this->direccion = direccion;
}

void DTHostal::setTelefono(string telefono)
{
    this->telefono = telefono;
}

//creates
DTHostalExtendido::DTHostalExtendido(string nombre, string direccion, string telefono, float califPromedio, set<int> numerosHabitaciones, set<DTCalificacion*> colDTCalif, map<int, DTReserva*> colDTRes)
{
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
    this->calificacionPromedio = califPromedio;
    this->numerosHabitaciones = numerosHabitaciones; 
    this->colDTCalificacion = colDTCalif;
    this->colDTReserva = colDTRes;
}

// getters
string DTHostalExtendido::getNombre()
{
    return nombre;
}

string DTHostalExtendido::getDireccion()
{
    return direccion;
}

string DTHostalExtendido::getTelefono()
{
    return telefono;
}

float DTHostalExtendido::getCalificacionPromedio()
{
    return calificacionPromedio;
}

set<int> DTHostalExtendido::getNumHabitaciones()
{
    return this->numerosHabitaciones;
}

set<DTCalificacion*> DTHostalExtendido::getCalificaciones()
{
    return colDTCalificacion;
}

map<int, DTReserva*> DTHostalExtendido::getReservas()
{
    return colDTReserva;
}

// setters
void DTHostalExtendido::setNombre(string nombre)
{
    this->nombre = nombre;
}

void DTHostalExtendido::setDireccion(string direccion)
{
    this->direccion = direccion;
}

void DTHostalExtendido::setTelefono(string telefono)
{
    this->telefono = telefono;
}

void DTHostalExtendido::setCalificacionPromedio(float califProm)
{
    this->calificacionPromedio = califProm;
}

void DTHostalExtendido::setNumHabitaciones(set<int> numerosHabitaciones)
{
    this->numerosHabitaciones = numerosHabitaciones;
}

void DTHostalExtendido::setCalificaciones(set<DTCalificacion *> colDTCalif)
{
    this->colDTCalificacion = colDTCalif;
}

void DTHostalExtendido::setReservas(map<int, DTReserva*> colDTReserva)
{
    this->colDTReserva = colDTReserva;
}

ostream &operator<<(ostream &o, DTHostal &h)
{
    o << "Nombre Hostal:" << h.getNombre() << endl;
    o << "Dirección Hostal:" << h.getDireccion() << endl;
    o << "Teléfono Hostal:" << h.getTelefono() << endl;
    return o;
}


ostream &operator<<(ostream &o, DTHostalExtendido &h)
{
    o << "Nombre del Hostal: " << h.getNombre() << endl;
    o << "Dirección del Hostal: " << h.getDireccion() << endl;
    o << "Teléfono del Hostal: " << h.getTelefono() << endl;
    o << "Habitaciones del Hostal: ";
    set<int> habitaciones = h.getNumHabitaciones();
    if (habitaciones.empty())
        o << "No hay." << endl;
    else {
        o << endl;
        for(set<int>::iterator it = habitaciones.begin(); it != habitaciones.end(); ++it) {
            int numeroHab = *it;
            o << "Número de Habitación: " << numeroHab << endl;        
        }
    }

    o << "Reservas del Hostal: ";
    map<int,DTReserva*>reservas = h.getReservas();
    if (reservas.empty())
        o << "No hay." << endl;
    else {
        o << endl;
        for(map<int,DTReserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it)
            o << "Código Reserva: " << it->first << endl;
    }
    
    o << "Calificación Promedio del Hostal: " << h.getCalificacionPromedio() << endl;
    
    o << "Calificaciones del Hostal: ";
    set<DTCalificacion*> calificaciones = h.getCalificaciones();
    if (calificaciones.empty())
        o << "No hay." << endl;
    else {
        o << endl;
        for(set<DTCalificacion*>::iterator it2 = calificaciones.begin(); it2 != calificaciones.end(); ++it2) {
            DTCalificacion *calif = *it2;
            int calificacion = calif->getNota();
            o << calificacion << endl;
        }
    }

    return o;
}