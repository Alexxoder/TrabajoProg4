#include "../include/Calificacion.h"

// Constructores

Calificacion::Calificacion()
{
    this->nota = 0;
    this->comentario = "0";
    this->fecha.setDia(0);
    this->fecha.setMes(0);
    this->fecha.setAnio(0);
    this->fecha.setHora(0);
    this->respuesta = "0";
}

Calificacion::Calificacion(date fec, int nota, string coment)
{
    // hay que hacer el trycatch pues notas acotadas
    this->nota = nota;
    this->comentario = coment;
    this->fecha = fec;
    this->respuesta = "0";
}

// setters

void Calificacion::setNota(int note)
{
    // recordar que las notas estan acotadas
    this->nota = note;
}

void Calificacion::setComentario(string coment)
{
    this->comentario = coment;
}

void Calificacion::setFecha(date fec)
{
    this->fecha = fec;
}

void Calificacion::setRespuesta(string res)
{
    this->respuesta = res;
}

// getters

int Calificacion::getNota()
{
    return this->nota;
}

string Calificacion::getComentario()
{
    return this->comentario;
}

date Calificacion::getFecha()
{
    return this->fecha;
}

string Calificacion::getRespuesta()
{
    return this->respuesta;
}

// operaciones

bool Calificacion::sinResponder()
{
    return true;
}

string Calificacion::obtenerRespuesta()
{
    return this->respuesta;
}
