#ifndef _CONTROLADORRESERVA_H
#define _CONTROLADORRESERVA_H

#include "ControladorHostal.h"
#include "Reserva.h"
#include "ReservaGrupal.h"
#include "ReservaIndividual.h"
#include "InterfazReserva.h"
#include "DTReserva.h"
#include "date.h"
#include "DTCalificacion.h"
#include <string>
#include <map>
using namespace std;

class ControladorReserva : public InterfazReserva
{
private:
    static ControladorReserva *instancia;
    ControladorReserva();
    map<int, Reserva *> colReservas;
    
    date checkIn, checkOut;
    bool esGrupal;
    string nombreHostal;
    int codigoReserva;
    string emailResponsable;
    set<string> emailsHuespedes;

public:
    static ControladorReserva* getInstancia();
    ~ControladorReserva();

    virtual void ingresarReserva(date checkIn, date checkOut, bool esReservaGrupal);
    virtual void almacenarNombreHostal(string);
    virtual map<int, DTHabitacion*> obtenerHabDisponibles(string nombreHostal);
    string getNombreHostal();
    date getCheckIn();
    date getCheckOut();
    bool getEsGrupal();
    set<string> getHuespedesR();
    virtual void cancelarReserva();
    virtual void registrarEstadia(int codigoReserva, string emailHuesped);
    virtual void calificar(string texto, int nota, string emailHuesped, int codigoReserva, string nombreHostal);
    virtual void responder(string emailEmpleado, string texto, string emailHuesped, int codigoReserva);
    virtual DTCalificacion* darCalificacionRespuesta(int codigoReserva, string emailHuesped);
    virtual void identificarReserva(int codigoReserva);
    virtual void confirmarBajaReserva();
    virtual void cancelarBajaReserva();
    virtual void ingresarResponsable(string email);
    virtual void ingresarHuesped(string emailHuesped);
    virtual void confirmarReserva(int numeroHabitacion);
};

#endif

