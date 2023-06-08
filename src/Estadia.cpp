#include <string>
#include "../include/Estadia.h"

using namespace std;

Estadia::Estadia()
{
    this->huesped = NULL;
    this->cal = NULL;
}

Estadia::Estadia(date entrada, date salida, Huesped *hues, Calificacion *cal)
{
    this->entrada = entrada;
    this->salida = salida;
    this->huesped = hues;
    this->cal = cal;
}

void Estadia::setEntrada(date entrada)
{
    this->entrada = entrada;
}

void Estadia::setSalida(date salida)
{
    this->salida.setDia(salida.getDia());
    this->salida.setMes(salida.getMes());
    this->salida.setAnio(salida.getAnio());
    this->salida.setHora(salida.getHora());
}

void Estadia::setHuesped(Huesped *hues)
{
    this->huesped = hues;
}

void Estadia::setCalificacion(Calificacion *cal)
{
    this->cal = cal;
}

date Estadia::getEntrada()
{
    return this->entrada;
}

date Estadia::getSalida()
{
    return this->salida;
}

Huesped *Estadia::getHuesped()
{
    return this->huesped;
}

Calificacion *Estadia::getCalificacion()
{
    return this->cal;
}

bool Estadia::esHuesped(string emailHuesped)
{
    Huesped *hues = this->getHuesped();
    string email = hues->getEmail();
    return email == emailHuesped;
}

DTEstadia *Estadia::obtenerEstadia()
{
    string emailHues = this->huesped->getEmail();
    DTEstadia *nuevaEst = new DTEstadia(emailHues, 0, this->entrada, this->salida, "", 0); //* el nombre del hostal, el codigo de la reserva
    return nuevaEst;                                                                       //* y el numero de la habitacion luego se setean
}

DTCalificacion *Estadia::obtenerComentariosSinResponder()
{
    Calificacion *cal = this->getCalificacion();

    string resp = cal->obtenerRespuesta();
    if (resp == "0")
    {
        Huesped *hues = this->getHuesped();
        string emailHuesped = hues->getEmail();
        DTCalificacion *DTcalif = new DTCalificacion(cal->getFecha(), cal->getNota(), cal->getComentario(), "", emailHuesped, 0);
        return DTcalif;
    }
    else
    {

        return NULL;
    }
}

DTCalificacion *Estadia::darCalificacionRespuesta()
{
    DTCalificacion *c = NULL;
    Calificacion *cal = this->getCalificacion();
    if (cal != NULL)
    {
        Huesped *hues = this->getHuesped();
        string email = hues->getEmail();
        c = new DTCalificacion(cal->getFecha(), cal->getNota(), cal->getComentario(), email, cal->getRespuesta(), 0);
    }

    return c;
}

void Estadia::responder(string texto, string emailHuesped, string emailEmpleado)
{
    Calificacion *cal = this->getCalificacion();
    if (cal != NULL)
    {
        string space = ": ";
        string r = emailEmpleado;
        r += space;
        r += texto;
        cal->setRespuesta(r);
    }
}

void Estadia::eliminarCalificacion()
{
    delete cal;
}
