#include "../include/DTReserva.h"

//creates
DTReserva::DTReserva()
{
    this->codigo = 0 ;
    this->estado = EstadoReserva::abierta;
    this->numHabitacion = 0;
    this->costo = 0;
}

DTReserva::DTReserva(int codigo, date checkIn, date checkOut, EstadoReserva estado, int numHabitacion, float costo, set<string> emailsHuespedes)
{
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->numHabitacion = numHabitacion;
    this->costo = costo;
    this->colEmailsHuespedes = emailsHuespedes;
}

//getters
int DTReserva::getCodigo()
{
    return codigo;
}

date DTReserva::getCheckIn()
{
    return checkIn;
}

date DTReserva::getCheckOut()
{
    return checkOut;
}

EstadoReserva DTReserva::getEstado()
{
    return estado;
}

int DTReserva::getNumHabitacion()
{
    return numHabitacion;
}

float DTReserva::getCosto()
{
    return costo;
}

set<string> DTReserva::getEmailsHuespedes()
{
    return this->colEmailsHuespedes;
}

//setters
void DTReserva::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void DTReserva::setCheckIn(date checkIn)
{
    this->checkIn = checkIn;
}

void DTReserva::setCheckOut(date checkOut)
{
    this->checkOut = checkOut;
}

void DTReserva::setEstado(EstadoReserva estado)
{
    this->estado = estado;
}

void DTReserva::setNumHabitacion(int numHabitacion)
{
    this->numHabitacion = numHabitacion;
}

void DTReserva::setCosto(float costo)
{
    this->costo = costo;
}

void DTReserva::setEmailsHuespedes(set<string> emailsHuespedes)
{
    this->colEmailsHuespedes = emailsHuespedes;
}


ostream &operator<<(ostream &o, DTReserva &r)
{   
    o << "Código Reserva: " << r.getCodigo() << endl;
    date checkIn = r.getCheckIn();
    o << "Fecha de entrada: " << checkIn << endl;
    date checkOut = r.getCheckOut();
    o << "Fecha de salida: " << checkOut << endl;
    EstadoReserva estado = r.getEstado();
    o << "Estado de la reserva: ";
    switch (estado)
    {
        case EstadoReserva::abierta:
        {
            o << "Abierta." << endl;
            break;
        }
        case EstadoReserva::cerrada:
        {
            o << "Cerrada." << endl;
            break;
        }
        case EstadoReserva::cancelada:
        {
            o << "Cancelada." << endl;
            break;
        }    
    }
    o << "Número de Habitación: " << r.getNumHabitacion() << endl;
    o << "Costo: $" << r.getCosto() << endl;
    set<string> emails = r.getEmailsHuespedes();  
    for (set<string>::iterator it = emails.begin(); it!= emails.end(); ++it)
    {
        string email = *it;
        o << "Mail Huesped: " << email << endl;
    }
    return o;
}

