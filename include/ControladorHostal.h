#ifndef _CONTROLADORHOSTAL_H
#define _CONTROLADORHOSTAL_H

#include "InterfazHostal.h"
#include "Hostal.h"
#include "DTHostal.h"
#include "DTHabitacion.h"
#include "Reserva.h"
#include "DTReserva.h"
#include "Empleado.h"
#include "Calificacion.h"
#include "Usuario.h"
#include "DTEstadia.h"
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

// singleton
class ControladorHostal : public InterfazHostal
{
private:
    static ControladorHostal *instancia;
    ControladorHostal();

    // coleccion global de Hostal
    map<string, Hostal*> colHostales;

    // memoria del controlador
    string nombreHostal;
    DTHabitacion *datosHab;
    set<DTEstadia*> colDTEstadia;

public:
    // creates
    static ControladorHostal* getInstancia();
    ~ControladorHostal();

    // getters
    string getNombreHostal();
    DTHabitacion* getDTHabitacion();
    set<DTEstadia* > getDTEstadias();

    // setters
    void setNombreHostal(string);
    void setDTHabitacion(DTHabitacion*);
    void setDTEstadia(set<DTEstadia *>);

    // opts del DC
    virtual void registrarHostal(string, string, string);
    virtual map<string, DTHostal*> obtenerHostales();
    virtual void ingresarHabitacion(DTHabitacion*, string);
    virtual void cancelarAltaHabitacion();
    void liberarDTHostal();
    virtual void confirmarAltaHabitacion();
    void liberarDTHabitacion();
    void vincularEmpleadoHostal(Empleado*, string);
    map<int, DTHabitacion*> obtenerHabDisponibles(string, date, date);
    void vincularReservaHabitacion(Reserva*, string, int);
    virtual DTHostal** obtenerTop3();
    virtual set<DTCalificacion*> obtenerCalificacionesHostal(string);
    virtual map<int, DTReserva*> obtenerReservasNoCanceladas(string, string);
    virtual void finalizarEstadia(string, string);
    virtual set<DTEstadia*> obtenerEstadiasFinalizadas(string, string);
    void vincularYNotificarCalificacion(Calificacion*, string, string);
    virtual DTHostalExtendido* infoHostal(string);
    virtual map<int, DTReserva*> obtenerReservas(string);
    virtual set<DTEstadia*> obtenerEstadias(string);
    void almacenarColDTEstadia(set<DTEstadia*>);
    virtual DTEstadia* mostrarEstadia(string, int);
    virtual DTReserva* mostrarReserva(string, int);
    void desvincularReservaHabitacion(string, Reserva*);
    void mostrarHostales();
};

#endif
