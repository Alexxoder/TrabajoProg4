#include <string>
#include "../include/Hostal.h"
using namespace std;

Hostal::Hostal()
{
    this->nombre = "";
    this->direccion = "";
    this->telefono = "";
}

Hostal::~Hostal()
{
    observadores.clear();
    colReservas.clear();
    for (map<int, Habitacion *>::iterator it = colHabitaciones.begin(); it != colHabitaciones.end(); ++it)
        delete it->second;
    colHabitaciones.clear();
    colCalificaciones.clear();
}

Hostal::Hostal(string nombre, string direccion, string telefono)
{
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
}

string Hostal::getNombre()
{
    return this->nombre;
}

string Hostal::getDireccion()
{
    return this->direccion;
}
string Hostal::getTelefono()
{
    return this->telefono;
}
void Hostal::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Hostal::setDireccion(string direccion)
{
    this->direccion = direccion;
}

void Hostal::setTelefono(string telefono)
{
    this->telefono = telefono;
}

DTHostal *Hostal::getDTHostal()
{
    DTHostal *res = new DTHostal(nombre, direccion, telefono);
    return res;
}

set<DTCalificacion *> Hostal::obtenerCalificaciones()
{
    set<DTCalificacion *> DTCals;

    for (set<Calificacion *>::iterator it = colCalificaciones.begin(); it != colCalificaciones.end(); ++it)
    {
        Calificacion *cal = *it;
        DTCalificacion *nuevoDT = new DTCalificacion(cal->getFecha(), cal->getNota(), cal->getComentario(), cal->obtenerRespuesta(), "", 0); // huesped y reserva no son necesarios para este caso de uso.
        DTCals.insert(nuevoDT);
    }
    return DTCals;
}

map<int, DTReserva *> Hostal::obtenerReservas()
{
    map<int, DTReserva *> colDTRes;
    map<int, DTReserva *> colDTResAinsertar;

    for (map<int, Habitacion *>::iterator it = colHabitaciones.begin(); it != colHabitaciones.end(); ++it)
    {
        Habitacion *hab = it->second;
        colDTResAinsertar = hab->obtenerReservas();
        if (!colDTResAinsertar.empty())
            colDTRes.insert(colDTResAinsertar.begin(), colDTResAinsertar.end());
    }

    return colDTRes;
}

void Hostal::aniadirHabitacion(DTHabitacion *datosHab)
{
    if (colHabitaciones.find(datosHab->getNumero()) == colHabitaciones.end())
    {
        Habitacion *nueva = new Habitacion(datosHab->getNumero(), datosHab->getPrecio(), datosHab->getCapacidad());
        colHabitaciones[nueva->getNumero()] = nueva;
    }
}

map<int, DTHabitacion *> Hostal::obtenerDTHabitaciones()
{

    map<int, DTHabitacion *> colDTHab;

    for (map<int, Habitacion *>::iterator it = colHabitaciones.begin(); it != colHabitaciones.end(); ++it)
    {
        int numHab = it->first;
        Habitacion *hab = it->second;

        DTHabitacion *nuevaHab = new DTHabitacion(hab->getNumero(), hab->getPrecio(), hab->getCapacidad());
        colDTHab[numHab] = nuevaHab;
    }
    return colDTHab;
}

map<int, DTHabitacion *> Hostal::obtenerHabDisponibles(date in, date out)
{
    map<int, DTHabitacion *> res;
    for (map<int, Habitacion *>::iterator it = colHabitaciones.begin(); it != colHabitaciones.end(); ++it)
    {
        bool disponible = it->second->estaDisponible(in, out);
        if (disponible)
        {
            DTHabitacion *dt = it->second->getDTHabitacion();
            res[it->first] = dt;
        }
    }
    return res;
}

void Hostal::vincularReservaHabitacion(Reserva *res, int numeroHabitacion)
{
    map<int, Habitacion *>::iterator it = this->colHabitaciones.find(numeroHabitacion);
    it->second->vincularReservaHabitacion(res);
    this->colReservas[res->getCodigo()] = res;
}

map<int, DTReserva *> Hostal::obtenerReservasNoCanceladas(string emailHuesped)
{

    map<int, DTReserva *> colDTRes;
    map<int, DTReserva *> colDTResAinsertar;

    for (map<int, Habitacion *>::iterator it = colHabitaciones.begin(); it != colHabitaciones.end(); ++it)
    {
        Habitacion *hab = it->second;

        colDTResAinsertar = (hab->obtenerReservasNoCanceladas(emailHuesped));
        if (!colDTResAinsertar.empty())
            colDTRes.insert(colDTResAinsertar.begin(), colDTResAinsertar.end());
    }
    return colDTRes;
}

set<DTEstadia *> Hostal::obtenerEstadiasFinalizadas(string emailHuesped)
{
    set<DTEstadia *> DTEst;
    set<DTEstadia *> aInsertar;
    for (map<int, Habitacion *>::iterator it = colHabitaciones.begin(); it != colHabitaciones.end(); ++it)
    {
        Habitacion *hab = it->second;
        aInsertar = hab->obtenerEstadiasFinalizadas(emailHuesped);
        DTEst.insert(aInsertar.begin(), aInsertar.end());
    }

    for (set<DTEstadia *>::iterator it2 = DTEst.begin(); it2 != DTEst.end(); ++it2)
    {
        DTEstadia *actual = *it2;
        actual->setHostal(this->nombre);
    }
    return DTEst;
}

void Hostal::agregarCaliFHostal(Calificacion *calif, string emailhuesped)
{
    notificarSuscritos(calif, emailhuesped);
    colCalificaciones.insert(calif);
}

void Hostal::agregarSuscrito(Suscrito *observador)
{
    observadores.insert(observador);
}

void Hostal::eliminarEmpleadoSuscrito(Suscrito *observador)
{
    observadores.erase(observador);
}

void Hostal::notificarSuscritos(Calificacion *calif, string emailHuesped)
{
    int nota = calif->getNota();
    string comentario = calif->getComentario();
    set<Suscrito *>::iterator it;
    for (it = observadores.begin(); it != observadores.end(); ++it)
    {
        Suscrito *sus = *it;
        sus->notificar(nota, comentario, emailHuesped);
    }
}

float Hostal::calcularPromedio()
{
    set<DTCalificacion *>::iterator it;
    set<DTCalificacion *> calificaciones;
    calificaciones = this->obtenerCalificaciones();
    int divisor = 0;
    divisor = calificaciones.size();
    float contador = 0;
    float promedio = 0;
    for (it = calificaciones.begin(); it != calificaciones.end(); ++it)
    {
        DTCalificacion *dt = *it;
        contador = dt->getNota() + contador;
    }

    if (divisor != 0)
    {
        promedio = (contador / divisor);
    }

    for (set<DTCalificacion *>::iterator it2 = calificaciones.begin() ;it2 != calificaciones.end() ; ++it2)
    {
        DTCalificacion * dt = *it2;
        delete dt;
    }
    
    calificaciones.clear();

    return promedio;
}

void Hostal::finalizarEst(string email)
{
    for (map<int, Reserva *>::iterator it = colReservas.begin(); it != colReservas.end(); ++it)
    {
        Reserva *reserva = it->second;
        reserva->finalizarEst(email);
    }
}

set<DTCalificacion *> Hostal::obtenerComentariosSinResponder()
{
    set<DTCalificacion *> comentariosSinResponder;
    set<DTCalificacion *> aIngresar;
    for (map<int, Reserva *>::iterator it = colReservas.begin(); it != colReservas.end(); ++it)
    {
        Reserva *res = it->second;
        aIngresar = res->obtenerComentariosSinResponder();
        comentariosSinResponder.insert(aIngresar.begin(), aIngresar.end());
    }
    return comentariosSinResponder;
}

set<DTEstadia *> Hostal::obtenerEstadias()
{
    set<DTEstadia *> estadias;
    set<DTEstadia *> aIngresar;
    for (map<int, Habitacion *>::iterator it = colHabitaciones.begin(); it != colHabitaciones.end(); ++it)
    {
        Habitacion *hab = it->second;
        aIngresar = hab->obtenerEstadias();
        estadias.insert(aIngresar.begin(), aIngresar.end());
    }

    for (set<DTEstadia *>::iterator it2 = estadias.begin(); it2 != estadias.end(); ++it2)
    {
        DTEstadia *actual = *it2;
        actual->setHostal(this->nombre);
    }

    return estadias;
}

DTHostalExtendido *Hostal::infoHostal()
{

    set<DTCalificacion *> calificaciones = this->obtenerCalificaciones();
    float promedio = this->calcularPromedio();
    map<int, Habitacion *>::iterator it;
    set<int> habitaciones;
    for (it = colHabitaciones.begin(); it != colHabitaciones.end(); ++it)
    {
        habitaciones.insert(it->first);
    }
    map<int, DTReserva *> reservas = this->obtenerReservas();

    DTHostalExtendido *DTHE = new DTHostalExtendido(this->nombre, this->direccion, this->telefono, promedio, habitaciones, calificaciones, reservas);

    return DTHE;
}

void Hostal::desvincularReservaHabitacion(Reserva *res)
{
    for (map<int, Habitacion *>::iterator it = colHabitaciones.begin(); it != colHabitaciones.end(); it++)
        it->second->desvincularReservaHabitacion(res);
    this->colReservas.erase(res->getCodigo());
}