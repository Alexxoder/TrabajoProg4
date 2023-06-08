#include "../include/ControladorReserva.h"

ControladorReserva *ControladorReserva::instancia = NULL;

ControladorReserva::ControladorReserva()
{
    esGrupal = false;
    codigoReserva = 1;
}

ControladorReserva::~ControladorReserva()
{
    for (map<int, Reserva *>::iterator it = colReservas.begin(); it != colReservas.end(); ++it)
    {
        it->second->eliminarEstadiasCalificaciones();
        delete it->second;
    }
    colReservas.clear();
}

ControladorReserva *ControladorReserva::getInstancia()
{
    if (instancia == NULL)
        instancia = new ControladorReserva();
    return instancia;
}

void ControladorReserva::registrarEstadia(int codigoReserva, string emailHuesped)
{
    map<int, Reserva *>::iterator it = colReservas.find(codigoReserva);
    it->second->registrarEstadia(emailHuesped);
}

void ControladorReserva::ingresarReserva(date checkIn, date checkOut, bool esReservaGrupal)
{
    instancia->checkIn = checkIn;
    instancia->checkOut = checkOut;
    instancia->esGrupal = esReservaGrupal;
}

void ControladorReserva::almacenarNombreHostal(string nombre)
{
    instancia->nombreHostal = nombre;
}

map<int, DTHabitacion *> ControladorReserva::obtenerHabDisponibles(string nombreHostal)
{
    instancia->almacenarNombreHostal(nombreHostal);
    ControladorHostal *c = ControladorHostal::getInstancia();
    map<int, DTHabitacion *> res = c->obtenerHabDisponibles(nombreHostal, instancia->checkIn, instancia->checkOut);
    return res;
}

void ControladorReserva::ingresarResponsable(string email)
{
    instancia->ingresarHuesped(email);
    instancia->emailResponsable = email;
}

void ControladorReserva::ingresarHuesped(string emailHuesped)
{
    instancia->emailsHuespedes.insert(emailHuesped);
}

void ControladorReserva::confirmarReserva(int numeroHabitacion)
{
    Reserva *alta;
    if (instancia->esGrupal)
        alta = new ReservaGrupal(instancia->codigoReserva, instancia->checkIn, instancia->checkOut, instancia->emailsHuespedes, instancia->emailResponsable);
    else
        alta = new ReservaIndividual(instancia->codigoReserva, instancia->checkIn, instancia->checkOut, instancia->emailsHuespedes);
    ControladorHostal *c = ControladorHostal::getInstancia();
    c->vincularReservaHabitacion(alta, instancia->nombreHostal, numeroHabitacion);
    instancia->colReservas[instancia->codigoReserva] = alta;
    instancia->codigoReserva = instancia->codigoReserva + 1;
    instancia->emailsHuespedes.clear();
}

void ControladorReserva::cancelarReserva()
{
    instancia->emailsHuespedes.clear();
}

string ControladorReserva::getNombreHostal()
{
    return "";
}

date ControladorReserva::getCheckIn()
{
    date res;
    return res;
}

date ControladorReserva::getCheckOut()
{
    date res;
    return res;
}

bool ControladorReserva::getEsGrupal()
{
    return false;
}

set<string> ControladorReserva::getHuespedesR()
{
    set<string> res;
    return res;
}

void ControladorReserva::calificar(string texto, int nota, string emailHuesped, int codigoReserva, string nombreHostal)
{
    FechaSistema *f = FechaSistema::getInstancia();
    date fecha = f->getFecha();
    Calificacion *cal = new Calificacion(fecha, nota, texto);

    map<int, Reserva *>::iterator it = instancia->colReservas.find(codigoReserva);
    it->second->calificar(cal, emailHuesped);

    ControladorHostal *c = ControladorHostal::getInstancia();
    c->vincularYNotificarCalificacion(cal, nombreHostal, emailHuesped);
}

void ControladorReserva::responder(string emailEmpleado, string texto, string emailHuesped, int codigoReserva)
{
    map<int, Reserva *>::iterator it;
    it = colReservas.find(codigoReserva);
    Reserva *res = it->second;
    res->responder(texto, emailHuesped, emailEmpleado);
}

DTCalificacion *ControladorReserva::darCalificacionRespuesta(int codigoReserva, string emailHuesped)
{
    map<int, Reserva *>::iterator it = instancia->colReservas.find(codigoReserva);
    return it->second->darCalificacionRespuesta(emailHuesped);
}

void ControladorReserva::identificarReserva(int codigoReserva)
{
    instancia->codigoReserva = codigoReserva;
}

void ControladorReserva::confirmarBajaReserva()
{
    map<int, Reserva *>::iterator it = instancia->colReservas.find(instancia->codigoReserva);
    ControladorHostal *iHostal = ControladorHostal::getInstancia();
    Reserva *baja = it->second;
    iHostal->desvincularReservaHabitacion(instancia->nombreHostal, baja); //?aca pide el nombre del controlador en el hostal
    baja->eliminarEstadiasCalificaciones();
    delete baja;
    instancia->colReservas.erase(it->first);
}

void ControladorReserva::cancelarBajaReserva()
{
}
