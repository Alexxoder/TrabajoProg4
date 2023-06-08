#ifndef _RESERVAGRUPAL_H
#define _RESERVAGRUPAL_H

#include "../include/Reserva.h"

class ReservaGrupal : public Reserva
{
private:
    string emailEncargado;
public:
    // creates
    ReservaGrupal();
    ReservaGrupal(int, date, date, map<string, Huesped *>, string);
    ReservaGrupal(int, date, date, set<string>, string);
    ~ReservaGrupal();
    
    //getters
    string getEncargado();

    //setters
    void setEncargado(string);
    
    //opts del DC
    virtual float calcularCosto(int);
};

#endif
