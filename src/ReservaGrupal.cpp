#include "../include/ReservaGrupal.h"

// create
ReservaGrupal::ReservaGrupal(): Reserva()
{
    
}

ReservaGrupal::ReservaGrupal(int codigo, date checkIn, date checkOut, map<string, Huesped *> huespedes, string emailEncargado) : Reserva(codigo, checkIn, checkOut, huespedes)
{
    this->emailEncargado = emailEncargado;
}

ReservaGrupal::ReservaGrupal(int codigo, date checkIn, date checkOut, set<string> emails, string emailEncargado) : Reserva(codigo, checkIn, checkOut, emails)
{
    this->emailEncargado = emailEncargado;
}

//getters
string ReservaGrupal::getEncargado()
{
    return emailEncargado;
}

//setters
void ReservaGrupal::setEncargado(string email)
{
    this->emailEncargado = email;
}

float ReservaGrupal::calcularCosto(int precio)
{  
    int cantfingers = 0;
    int costo = (getCheckOut() - getCheckIn()) * precio;
    map<string, Huesped*> huespedes = getHuespedes();
    map<string, Huesped*>::iterator it = huespedes.begin();
    while (it != huespedes.end())
    {
        Huesped* hues = it->second;
        if (hues->getEsFinger())
            cantfingers++;
        it++;
    }
    if (cantfingers >= 2)
    {
        int descuento = (costo / 10) * 3;
        return costo - descuento;
    }
    else
        return costo; 
}

//!No saquen los destructores
ReservaGrupal::~ReservaGrupal(){

}
