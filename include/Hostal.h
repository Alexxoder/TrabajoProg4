#ifndef _HOSTAL_H
#define _HOSTAL_H

#include "Suscrito.h"
#include "DTHostal.h"
#include "Reserva.h"
#include "Habitacion.h"
#include "DTHabitacion.h"
#include "DTCalificacion.h"
#include "DTReserva.h"
#include <set>
#include <string>
#include <map>
using namespace std;

class Hostal
{
private:
    string nombre;
    string direccion;
    string telefono;
    void notificarSuscritos(Calificacion *calif, string emailHuesped);
    set<Suscrito*> observadores;
    map<int, Reserva*> colReservas;
    map<int, Habitacion*> colHabitaciones;
    set<Calificacion*> colCalificaciones;
public:
    // creates
    Hostal();
    Hostal(string nombre, string direccion, string telefono);
    ~Hostal();

    // getters
    string getNombre();
    string getDireccion();
    string getTelefono();

    // setters
    void setNombre(string nombre);
    void setDireccion(string direccion);
    void setTelefono(string telefono);

    // opts del DC
    DTHostal *getDTHostal();
    set<DTCalificacion*> obtenerCalificaciones();
    map<int, DTHabitacion*> obtenerDTHabitaciones();
    void agregarDTCalif(Calificacion*);
    void agregarDTHabitacion(Habitacion*);
    map<int, DTReserva*> obtenerReservas();
    void aniadirHabitacion(DTHabitacion*);
    map<int, DTHabitacion*> obtenerHabDisponibles(date, date);
    void vincularReservaHabitacion(Reserva*, int);
    map<int, DTReserva*> vincularReservasNoCanceladas(string);
    map<int, DTReserva*> obtenerReservasNoCanceladas(string);
    void registrarEstadia();
    set<DTEstadia*> obtenerEstadiasFinalizadas(string);
    void agregarCaliFHostal(Calificacion*, string emailHuesped);
    void agregarSuscrito(Suscrito* observador);
    void eliminarEmpleadoSuscrito(Suscrito *observador);
    float calcularPromedio();
    void finalizarEst(string email);
    set<DTCalificacion*> obtenerComentariosSinResponder();
    set<DTEstadia*> obtenerEstadias();
    DTHostalExtendido* infoHostal();
    void desvincularReservaHabitacion(Reserva *res);
};

#endif
