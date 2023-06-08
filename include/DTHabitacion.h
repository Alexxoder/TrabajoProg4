#ifndef _DTHABITACION_H
#define _DTHABITACION_H
#include <string>
#include <iostream>
using namespace std;

class DTHabitacion
{
private:
    int numero;
    float precio;
    int capacidad;

public:
    //creates
    DTHabitacion();
    DTHabitacion(int, float, int);
    
    //setters
    void setNumero(int);
    void setPrecio(float);
    void setCapacidad(int);

    //getters
    int getNumero();
    float getPrecio();
    int getCapacidad();
};

ostream &operator<<(ostream &o, DTHabitacion &hab);

#endif
