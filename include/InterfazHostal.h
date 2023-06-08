#ifndef _INTERFAZHOSTAL_H
#define _INTERFAZHOSTAL_H

#include "DTHostal.h"
#include "DTHabitacion.h"
#include "DTCalificacion.h"
#include "DTReserva.h"
#include "DTEstadia.h"
#include <string>
#include <set>
using namespace std;

// interface
class InterfazHostal
{
public:
    virtual void registrarHostal(string, string, string) = 0;
    virtual map<string, DTHostal*> obtenerHostales() = 0;
    virtual void ingresarHabitacion(DTHabitacion*, string) = 0;
    virtual void cancelarAltaHabitacion() = 0;
    virtual void confirmarAltaHabitacion() = 0;
    virtual DTHostal** obtenerTop3() = 0;
    virtual set<DTCalificacion*> obtenerCalificacionesHostal(string) = 0;
    virtual map<int, DTReserva*> obtenerReservasNoCanceladas(string, string) = 0;
    virtual void finalizarEstadia(string, string) = 0;
    virtual set<DTEstadia*> obtenerEstadiasFinalizadas(string, string) = 0;
    virtual DTHostalExtendido* infoHostal(string) = 0;
    virtual map<int, DTReserva*> obtenerReservas(string) = 0;
    virtual set<DTEstadia*> obtenerEstadias(string) = 0;
    virtual DTEstadia* mostrarEstadia(string, int) = 0;
    virtual DTReserva* mostrarReserva(string, int) = 0;
    virtual map<int, DTHabitacion*> obtenerHabDisponibles(string, date, date) = 0; 
    virtual ~InterfazHostal()
    {
    
    }
};

#endif
