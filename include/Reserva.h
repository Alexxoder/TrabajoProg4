#ifndef _RESERVA_H
#define _RESERVA_H

#include "date.h"
#include "EstadoReserva.h"
#include "Estadia.h"
#include "DTEstadia.h"
#include "Huesped.h"
#include "DTHuesped.h"
#include "DTCalificacion.h"
#include "FechaSistema.h"
#include "ControladorUsuario.h"
#include <string>
using namespace std;
#include <set>
#include <map>

class Reserva
{
private:
    int codigo;
    date checkIn, checkOut;
    EstadoReserva estado;
    set<Estadia *> colEstadias;
    map<string, Huesped*> colHuespedes;

public:
    // creates
    Reserva();
    Reserva(int, date, date, map<string, Huesped*>);
    Reserva(int, date, date, set<string>);
    virtual ~Reserva();

    // getters
    int getCodigo();
    date getCheckIn();
    date getCheckOut();
    EstadoReserva getEstado();
    set<Estadia *> getEstadias();
    map<string, Huesped *> getHuespedes();

    // setters
    void setCodigo(int);
    void setCheckIn(date);
    void setCheckOut(date);
    void setEstado(EstadoReserva);
    void setEstadias(set<Estadia *>);
    void setHuespedes(map<string, Huesped *>);

    // opts del DC
    bool fechaDisponible(date, date);
    bool verificarReserva(string);
    DTEstadia * obtenerEstadiaFinalizada(string);
    set<DTEstadia *> obtenerEstadias();
    virtual float calcularCosto(int) = 0;
    DTHuesped *getDTHuespedes();
    void agregarDTHuesped(string);
    void finalizarEst(string);
    set<DTCalificacion *> obtenerComentariosSinResponder();
    void responder(string, string,string);
    DTEstadia *obtenerDatosEstadia();
    DTCalificacion *darCalificacionRespuesta(string);
    void calificar(Calificacion*, string);
    void registrarEstadia(string);
    void eliminarEstadiasCalificaciones();
};

#endif
