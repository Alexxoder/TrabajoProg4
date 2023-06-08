#ifndef _INTERFAZRESERVA_H
#define _INTERFAZRESERVA_H

#include "DTReserva.h"
#include "DTHabitacion.h"
#include "DTCalificacion.h"
#include <set>
#include <map>
using namespace std;

class InterfazReserva
{
public:
    virtual void ingresarReserva(date checkIn, date checkOut, bool esReservaGrupal) = 0;
    virtual void almacenarNombreHostal(string) = 0;
    virtual map<int, DTHabitacion*> obtenerHabDisponibles(string nombreHostal) = 0;
    virtual void ingresarResponsable(string email) = 0;
    virtual void ingresarHuesped(string email) = 0;
    virtual void confirmarReserva(int numeroHabitacion) = 0;
    virtual void cancelarReserva() = 0;
    virtual void registrarEstadia(int codigoReserva, string emailHuesped) = 0;
    virtual void calificar(string texto, int nota, string emailHuesped, int codigoReserva, string nombreHostal) = 0;
    virtual void responder(string emailEmpleado, string texto, string emailHuesped, int codigoReserva) = 0;
    virtual DTCalificacion* darCalificacionRespuesta(int codigoReserva, string emailHuesped) = 0;
    virtual void identificarReserva(int codigoReserva) = 0;
    virtual void confirmarBajaReserva() = 0;
    virtual void cancelarBajaReserva() = 0;
    virtual ~InterfazReserva()
    {

    }
};

#endif
