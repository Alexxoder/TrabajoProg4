#ifndef _CALIFICACION_H
#define _CALIFICACION_H
#include "date.h"
#include <string>
using namespace std;


class Calificacion
{
private:
    date fecha;
    int nota;
    string comentario;
    string respuesta;
 public:
    //creates
    Calificacion();
    Calificacion(date, int, string);
    
    //setters
    void setFecha(date);
    void setNota(int);
    void setComentario(string);
    void setRespuesta(string);
    
    //getters
    date getFecha();
    int getNota();
    string getComentario();
    string getRespuesta();
    
    //operaciones
    bool sinResponder();
    string obtenerRespuesta();
};

#endif
