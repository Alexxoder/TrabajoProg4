#include "../include/Habitacion.h"

// constructores
Habitacion::Habitacion()
{
    this->numero = 0;
    this->precio = 0;
    this->capacidad = 0;
}

Habitacion::Habitacion(int n, float p, int c)
{
    this->numero = n;
    this->precio = p;
    this->capacidad = c;
}

Habitacion::~Habitacion()
{
    colReservasHab.clear();
}

// setter
void Habitacion::setNumero(int numero)
{
    this->numero = numero;
}

void Habitacion::setPrecio(float precio)
{
    this->precio = precio;
}

void Habitacion::setCapacidad(int capacidad)
{
    this->capacidad = capacidad;
}

// getters
int Habitacion::getNumero()
{
    return this->numero;
}

float Habitacion::getPrecio()
{
    return this->precio;
}

int Habitacion::getCapacidad()
{
    return this->capacidad;
}

bool Habitacion::estaDisponible(date in, date out)
{
    bool res = true;
    map<int, Reserva *>::iterator it = colReservasHab.begin();
    if (colReservasHab.empty())
    {
        return res;
    }

    do
    {
        res = it->second->fechaDisponible(in, out) && res;
        ++it;
    } while (res);

    return res;
}

DTHabitacion *Habitacion::getDTHabitacion()
{
    DTHabitacion *res = new DTHabitacion(numero, precio, capacidad);
    return res;
}

void Habitacion::vincularReservaHabitacion(Reserva *res)
{

    this->colReservasHab[res->getCodigo()] = res;
}

set<DTEstadia *> Habitacion::obtenerEstadiasFinalizadas(string emailHuesped)
{
    set<DTEstadia *> DTEst;
    DTEstadia *aInsertar;
    for (map<int, Reserva *>::iterator it = colReservasHab.begin(); it != colReservasHab.end(); ++it)
    {
        Reserva *res = it->second;
        aInsertar = res->obtenerEstadiaFinalizada(emailHuesped);
        if (aInsertar != NULL){
            DTEst.insert(aInsertar);
        }
    }

    for (set<DTEstadia *>::iterator it2 = DTEst.begin(); it2 != DTEst.end(); ++it2)
    {
        DTEstadia *actual = *it2;
        int num = this->getNumero();
        actual->setHabitacion(num);
    }
    return DTEst;
}

map<int, DTReserva *> Habitacion::obtenerReservas()
{
    map<int, DTReserva *> colDTRes;

    for (map<int, Reserva *>::iterator it = colReservasHab.begin(); it != colReservasHab.end(); ++it)
    {
        int codigo = it->first;
        Reserva *res = it->second;
        float costo = res->calcularCosto(this->precio);
        set<string> huespedes;
        map<string, Huesped *> hues = res->getHuespedes();
        map<string, Huesped *>::iterator it2;
        for (it2 = hues.begin(); it2 != hues.end(); ++it2)
        {
            string email = it2->first;
            huespedes.insert(email);
        }
        DTReserva *DTRes = new DTReserva(codigo, res->getCheckIn(), res->getCheckOut(), res->getEstado(), this->getNumero(), costo, huespedes);
        colDTRes[codigo] = DTRes;
    }

    return colDTRes;
}

map<int, DTReserva *> Habitacion::obtenerReservasNoCanceladas(string emailHuesped)
{
    map<int, DTReserva *> colDTRes;
    for (map<int, Reserva *>::iterator it = colReservasHab.begin(); it != colReservasHab.end(); ++it)
    {
        int codigo = it->first;
        Reserva *res = it->second;
        if (res->verificarReserva(emailHuesped))
        {
            float costo = res->calcularCosto(this->precio);
            set<string> huespedes;
            map<string, Huesped *> hues = res->getHuespedes();
            map<string, Huesped *>::iterator it2;
            if (hues.size() == 1)
            {
                it2 = hues.begin();
                huespedes.insert(it2->first);
            }
            else
            {
                for (it2 = hues.begin(); it2 != hues.end(); ++it2)
                {
                    string email = it2->first;
                    huespedes.insert(email);
                }
            }

            DTReserva *DTRes = new DTReserva(codigo, res->getCheckIn(), res->getCheckOut(), res->getEstado(), this->getNumero(), costo, huespedes);
            colDTRes[codigo] = DTRes;
        }
    }
    return colDTRes;
}

set<DTEstadia *> Habitacion::obtenerEstadias()
{
    set<DTEstadia *> estadias;
    set<DTEstadia *> aIngresar;
    for (map<int, Reserva *>::iterator it = colReservasHab.begin(); it != colReservasHab.end(); ++it)
    {
        Reserva *res = it->second;
        aIngresar = res->obtenerEstadias();
        estadias.insert(aIngresar.begin(), aIngresar.end());
    }

    for (set<DTEstadia *>::iterator it2 = estadias.begin(); it2 != estadias.end(); ++it2)
    {
        DTEstadia *est = *it2;
        est->setHabitacion(this->numero);
    }

    return estadias;
}

void Habitacion::desvincularReservaHabitacion(Reserva *res)
{
    map<int, Reserva *>::iterator it = colReservasHab.find(res->getCodigo());
    if (it != colReservasHab.end())
        colReservasHab.erase(res->getCodigo());
}