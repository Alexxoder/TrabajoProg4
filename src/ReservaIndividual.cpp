#include "../include/ReservaIndividual.h"

//create
ReservaIndividual::ReservaIndividual(): Reserva()
{

}

ReservaIndividual::ReservaIndividual(int codigo, date checkIn, date checkOut, map<string, Huesped*> huespedes): Reserva(codigo, checkIn, checkOut, huespedes)
{

}

ReservaIndividual::ReservaIndividual(int codigo, date checkIn, date checkOut, set<string> huespedes): Reserva(codigo, checkIn, checkOut, huespedes)
{
    
}

float ReservaIndividual::calcularCosto(int precio)
{
    map<string, Huesped*> huespedes = getHuespedes();
    map<string, Huesped*>::iterator it = huespedes.begin();
    Huesped * hues = it->second;
    string email = hues->getEmail();

    float d = getCheckOut() - getCheckIn();
    return precio * d; 
}

//!No saquen los destructores
ReservaIndividual::~ReservaIndividual(){

}
