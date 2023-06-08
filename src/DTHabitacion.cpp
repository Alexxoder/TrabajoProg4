#include "../include/DTHabitacion.h"

//creates
DTHabitacion::DTHabitacion()
{
    this->numero=0;
    this->precio=0;
    this->capacidad=0;
}

DTHabitacion::DTHabitacion(int numero, float precio, int capacidad)
{
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}

//setters
void DTHabitacion::setNumero(int numero)
{
    this->numero = numero;
}
void DTHabitacion::setPrecio(float precio)
{
    this->precio = precio;
}

void DTHabitacion::setCapacidad(int capacidad)
{
    this->capacidad = capacidad;
}

//getters
int DTHabitacion::getNumero()
{
    return this->numero;
}

float DTHabitacion::getPrecio()
{
    return this->precio;
}

int DTHabitacion::getCapacidad()
{
    return this->capacidad;
}

ostream &operator<<(ostream &o, DTHabitacion &hab)
{
    o << "Habitacion: " << hab.getNumero() << endl;
    o << "Precio: $" << hab.getPrecio() << endl;
    o << "Capacidad: " << hab.getCapacidad() << endl;
    return o;
}
