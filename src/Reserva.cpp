#include "../include/Reserva.h"

// creates
Reserva::Reserva()
{
    this->codigo = 0;
    this->checkIn = date(0, 0, 0, 0);
    this->checkOut = date(0, 0, 0, 0);
    this->estado = EstadoReserva::abierta;
}

Reserva::Reserva(int codigo, date checkIn, date checkOut, map<string, Huesped *> huespedes)
{
    this->codigo = codigo; // generado por ControladorReserva
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = EstadoReserva::abierta;
    this->colHuespedes = huespedes;
}

Reserva::Reserva(int codigo, date checkIn, date checkOut, set<string> emailsHuespedes)
{
    this->codigo = codigo; // generado por ControladorReserva
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = EstadoReserva::abierta;
    ControladorUsuario *iUsuario = ControladorUsuario::getInstancia();
    map<string, Usuario*> usuarios = iUsuario->getColUsuarios();
    map<string, Usuario*>::iterator it2;
    for (set<string>::iterator it = emailsHuespedes.begin(); it != emailsHuespedes.end(); ++it) {
        it2 = usuarios.find(*it);
        Huesped *h = dynamic_cast<Huesped*>(it2->second);
        this->colHuespedes[it2->first] = h;
    }
    usuarios.clear();
}

// getters
int Reserva::getCodigo()
{
    return codigo;
}

date Reserva::getCheckIn()
{
    return checkIn;
}

date Reserva::getCheckOut()
{
    return checkOut;
}

set<Estadia *> Reserva::getEstadias()
{
    return colEstadias;
}

map<string, Huesped *> Reserva::getHuespedes()
{
    return colHuespedes;
}

EstadoReserva Reserva::getEstado()
{
    return this->estado;
}

// setters
void Reserva::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Reserva::setCheckIn(date checkIn)
{
    this->checkIn = checkIn;
}

void Reserva::setCheckOut(date checkOut)
{
    this->checkOut = checkOut;
}

void Reserva::setEstado(EstadoReserva estado)
{
    this->estado = estado;
}

void Reserva::setEstadias(set<Estadia *> estadias)
{
    this->colEstadias = estadias;
}

void Reserva::setHuespedes(map<string, Huesped *> huespedes)
{
    this->colHuespedes = huespedes;
}

// opts del DC
bool Reserva::fechaDisponible(date in, date out)
{
    return !(checkIn < in || out < checkOut);
}

bool Reserva::verificarReserva(string emailHuesped)
{
    if (this->estado != EstadoReserva::cancelada)
    {
        map<string, Huesped *>::iterator it = colHuespedes.begin();
        string emailHues = it->first;

        while (it != colHuespedes.end() && emailHues != emailHuesped)
        {
            ++it;
        }

        if (emailHues == emailHuesped)
            return true;
        else
            return false;
    }
    return false;
}

void Reserva::registrarEstadia(string emailHuesped)
{
    this->estado = EstadoReserva::cerrada;
    FechaSistema *f = FechaSistema::getInstancia();
    date fecha = f->getFecha();
    map<string, Huesped*>::iterator it = this->colHuespedes.find(emailHuesped);
    Estadia *est = new Estadia();
    est->setEntrada(fecha);
    Huesped *hues = it->second;
    est->setHuesped(hues);
    this->colEstadias.insert(est);
}

DTEstadia * Reserva::obtenerEstadiaFinalizada(string emailHuesped) 
{
DTEstadia * DTEst = NULL;
    for(set<Estadia *>::iterator it = colEstadias.begin(); it != colEstadias.end(); ++it)
    {
        Estadia * est = *it;
        if(est->esHuesped(emailHuesped) && !(est->getSalida().esVacia())) //si es del huesped y esta finalziada.
        {
            Huesped* hues = est->getHuesped();
            string huesped = hues->getEmail();
            DTEst = new DTEstadia(huesped, this->codigo, est->getEntrada(), est->getSalida(), "", 0);
        }        
    }
    return DTEst;
}


set<DTEstadia *> Reserva::obtenerEstadias()
{
    set<DTEstadia *> estadias;
    DTEstadia *aIngresar;
    for (set<Estadia *>::iterator it = colEstadias.begin(); it != colEstadias.end(); ++it)
    {
        Estadia *est = *it;
        aIngresar = est->obtenerEstadia();
        estadias.insert(aIngresar);
    }

    for (set<DTEstadia *>::iterator it2 = estadias.begin(); it2 != estadias.end(); ++it2)
    {
        DTEstadia *esta = *it2;
        esta->setReserva(this->codigo);
    }

    return estadias;
}

DTHuesped *Reserva::getDTHuespedes()
{
    return NULL;
}

void Reserva::agregarDTHuesped(string)
{
}

void Reserva::finalizarEst(string emailHuesped)
{
    for (set<Estadia *>::iterator it = colEstadias.begin(); it != colEstadias.end(); ++it)
    {
        Estadia *estadia = *it;
        date salida = estadia->getSalida();
        bool em = estadia->esHuesped(emailHuesped);
        if (em && salida.esVacia()) {
            //pedir instancia global de la fecha sistema
            FechaSistema *f = FechaSistema::getInstancia();
            date fecha = f->getFecha();
            estadia->setSalida(fecha);
        }
    }
}

set<DTCalificacion *> Reserva::obtenerComentariosSinResponder()
{
    set<DTCalificacion *> comentariosSinResponder;
    DTCalificacion* aIngresar;
    
    for (set<Estadia*>::iterator it = colEstadias.begin(); it != colEstadias.end(); ++it){
        Estadia* est = *it;
        date checkOut;
        date fechavacia = date(0,0,0,0);
        checkOut = est->getSalida();
        if (!(checkOut == fechavacia) && (est->getCalificacion() != NULL)){
            aIngresar = est->obtenerComentariosSinResponder();
            if (aIngresar != NULL)
                comentariosSinResponder.insert(aIngresar);
        }
    }
    
    for (set <DTCalificacion*>::iterator it2 = comentariosSinResponder.begin(); it2 != comentariosSinResponder.end(); ++it2){
        DTCalificacion* DTCalif = *it2;
        DTCalif->setReserva(this->codigo);
    }
    return comentariosSinResponder;
}

void Reserva::responder(string texto, string emailHuesped, string emailEmpleado)
{
    for (set<Estadia*>::iterator it = colEstadias.begin(); it != colEstadias.end(); ++it){
        Estadia* est = *it;
        if (est->esHuesped(emailHuesped))
            est->responder(texto,emailHuesped,emailEmpleado);
    }
}

DTEstadia *Reserva::obtenerDatosEstadia()
{
    return NULL;
}

DTCalificacion *Reserva::darCalificacionRespuesta(string emailHuesped)
{
    DTCalificacion * cali = NULL;
    for(set<Estadia* >::iterator it = colEstadias.begin(); it != colEstadias.end(); ++it)
    {
        Estadia* actual = *it;
        if (actual->esHuesped(emailHuesped))
        {
            cali = actual->darCalificacionRespuesta();
        }
    }
    
    if (cali != NULL)
    {
        cali->setReserva(this->codigo);
    }
    

    return cali;
}

void Reserva::calificar(Calificacion * cal, string emailHuesped)
{
    for(set<Estadia* >::iterator it = colEstadias.begin(); it != colEstadias.end(); ++it)
    {
        Estadia* actual = *it;
        if (actual->esHuesped(emailHuesped))
        {
            actual->setCalificacion(cal);
        }
    }
}

void Reserva::eliminarEstadiasCalificaciones()
{
    for (set<Estadia*>::iterator it = this->colEstadias.begin(); it != this->colEstadias.end(); ++it) {
        Estadia *e = *it;
        e->eliminarCalificacion();
        delete e;
    }
    this->colEstadias.clear();
}

//!No saquen los destructores
Reserva::~Reserva(){

}
