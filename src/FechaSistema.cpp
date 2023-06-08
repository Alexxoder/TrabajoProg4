#include <string>
#include "../include/FechaSistema.h"

using namespace std;

FechaSistema * FechaSistema::instancia = NULL;

FechaSistema::FechaSistema()
{
    this->fecha.setDia(1);
    this->fecha.setMes(1);
    this->fecha.setAnio(1);
    this->fecha.setHora(1);
}

FechaSistema::FechaSistema(date fecha)
{
    this->fecha = fecha;
}

FechaSistema* FechaSistema::getInstancia()
{
    if (instancia == NULL)
        instancia = new FechaSistema();
    return instancia;
}

date FechaSistema::getFecha()
{
    return instancia->fecha;
}

void FechaSistema::setFecha(date fecha)
{
    instancia->fecha = fecha;
}

void FechaSistema::actualizarFecha(date fecha)
{
    instancia->setFecha(fecha);
}

FechaSistema::~FechaSistema()
{

}