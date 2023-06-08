#ifndef _ESTADIA_H
#define _ESTADIA_H

#include "Huesped.h"
#include "Calificacion.h"
#include "date.h"
#include "DTCalificacion.h"
#include "DTEstadia.h"
#include <set>

using namespace std;


class Estadia
{
private:
    date entrada;
    date salida;
    Huesped* huesped;
    Calificacion* cal;

public:
    Estadia();
    Estadia(date, date, Huesped*, Calificacion*);
    
    /*getters, setters*/
    void setEntrada(date);
    void setSalida(date);
    date getEntrada();
    date getSalida();

    /*get, set, punteros*/
    void setHuesped(Huesped*);
    void setCalificacion(Calificacion*);
    Huesped* getHuesped();
    Calificacion* getCalificacion();
    /*funciones*/
    bool esHuesped(string);
    DTCalificacion* obtenerComentariosSinResponder();
    void responder(string , string, string);
    DTCalificacion * darCalificacionRespuesta();
    DTEstadia * obtenerEstadia();
    void eliminarCalificacion();
};

#endif
