#include "../include/DTCalificacion.h"

//creates
DTCalificacion::DTCalificacion()
{
    this->fecha.setDia(0);
    this->fecha.setMes(0);
    this->fecha.setAnio(0);
    this->fecha.setHora(0);
    this->nota = 0;
    this->comentario = "0";
    this->respuesta = "0";
    this->huesped = "0";
    this->reserva = 0;
}

DTCalificacion::DTCalificacion(date fecha, int nota, string comentario,string rerspuesta,string huesped,int reserva)
{
    this->fecha = fecha;
    this->nota = nota;
    this->comentario = comentario;
    this->respuesta = respuesta;
    this->huesped = huesped;
    this->reserva = reserva;
}

//getters
date DTCalificacion::getFecha()
{
    return this->fecha;
}

int DTCalificacion::getNota()
{
    return this->nota;
}

string DTCalificacion::getComentario()
{
    return this->comentario;
}

string DTCalificacion::getRespuesta()
{
    return this->respuesta;
}

string DTCalificacion::getHuesped()
{
    return this->huesped;
}

int DTCalificacion::getReserva()
{
    return this->reserva;
}

//setters
void DTCalificacion::setFecha(date fecha)
{
    this->fecha = fecha;
}

void DTCalificacion::setNota(int nota)
{ //trycatch?
    this->nota = nota;
}

void DTCalificacion::setComentario(string comentario)
{
    this->comentario = comentario;
}

void DTCalificacion::setRespuesta(string respuesta)
{
    this->respuesta = respuesta;
}

void DTCalificacion::setHuesped(string huesped)
{
    this->huesped = huesped;   
}

void DTCalificacion::setReserva(int reserva)
{
    this->reserva = reserva;
}

ostream &operator<<(ostream &o,  DTCalificacion &c)
{
    date fecha = c.getFecha();
    string emailHuesped = c.getHuesped();
    o << "Realizada por el huesped con el email: " << emailHuesped << endl; 
    o << "Realizada el dia: " << fecha << endl;
    o << "Nota: " << c.getNota() << endl;
    o << "Comentario: " << c.getComentario() << endl;
    o << "Código de Reserva: " << c.getReserva() << endl;
    string respuesta = c.getRespuesta();
    if (respuesta != "")
        o << "Respuesta de un empleado: " << respuesta << endl;
    else
        o << "No hay respuesta de ningun empleado." << endl;

    return o;
}