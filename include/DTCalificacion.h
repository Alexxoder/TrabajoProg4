#ifndef _DTCALIFICACION_H
#define _DTCALIFICACION_H

#include "date.h"
#include <string>
#include <iostream>
using namespace std;


class DTCalificacion
{
    private:
        date fecha;
        int nota;
        string comentario;
        string respuesta;
        string huesped; // es el identificador (email)
        int reserva; //? para que se nesecita este atributo

    public:
        //creates
        DTCalificacion();
        DTCalificacion(date, int, string, string, string, int);
    
        //getters
        date getFecha();
        int getNota();
        string getComentario();
        string getRespuesta();
        string getHuesped();
        int getReserva();

        //setters
        void setFecha(date);
        void setNota(int);
        void setComentario(string);
        void setRespuesta(string);
        void setHuesped(string);
        void setReserva(int);
};

ostream &operator<<(ostream &o,  DTCalificacion &c);

#endif