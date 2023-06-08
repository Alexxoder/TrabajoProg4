#include "../include/ControladorHostal.h"

ControladorHostal *ControladorHostal::instancia = NULL;

// creates
ControladorHostal::ControladorHostal()
{
    nombreHostal = "";
    datosHab = NULL;
}

ControladorHostal::~ControladorHostal()
{
    for (map<string, Hostal *>::iterator it = this->colHostales.begin(); it != this->colHostales.end(); ++it)
        delete it->second;
    this->colHostales.clear();
}

ControladorHostal *ControladorHostal::getInstancia()
{
    if (instancia == NULL)
        instancia = new ControladorHostal();
    return instancia;
}

// getters
string ControladorHostal::getNombreHostal()
{
    return instancia->nombreHostal;
}

DTHabitacion *ControladorHostal::getDTHabitacion()
{
    return instancia->datosHab;
}

// setters
void ControladorHostal::setNombreHostal(string nombreHostal)
{
    instancia->nombreHostal = nombreHostal;
}

void ControladorHostal::setDTHabitacion(DTHabitacion *datosHab)
{
    instancia->datosHab = datosHab;
}

// opts del DC
void ControladorHostal::registrarHostal(string nombre, string direccion, string telefono)
{
    if (instancia->colHostales.find(nombre) == instancia->colHostales.end())
    {
        Hostal *h = new Hostal(nombre, direccion, telefono);
        instancia->colHostales[nombre] = h;
    }
}

map<string, DTHostal *> ControladorHostal::obtenerHostales()
{
    map<string, DTHostal *> res;
    if (!instancia->colHostales.empty())
    {

        // recorro colHostales
        for (map<string, Hostal *>::iterator it = instancia->colHostales.begin(); it != instancia->colHostales.end(); ++it)
        {
            Hostal *h = it->second;

            // se añaden los datos de h a datosHostal y se agrega a ser
            DTHostal *dt = h->getDTHostal();
            // res.insert(h->getNombre(), dt);
            res[h->getNombre()] = dt;
        }
    }
    return res;
}

void ControladorHostal::ingresarHabitacion(DTHabitacion *datosHabitacion, string nombreHostal)
{
    // se almacena los parametros en la memoria del controlador
    instancia->setDTHabitacion(datosHabitacion);
    instancia->setNombreHostal(nombreHostal);
}

void ControladorHostal::cancelarAltaHabitacion()
{
    instancia->liberarDTHabitacion();
}

void ControladorHostal::liberarDTHabitacion()
{
    instancia->datosHab = NULL;
}

void ControladorHostal::confirmarAltaHabitacion()
{
    string nombreH = instancia->getNombreHostal();
    DTHabitacion *dt = instancia->getDTHabitacion();
    map<string, Hostal *>::iterator it = instancia->colHostales.find(nombreH);
    Hostal *h = it->second;
    h->aniadirHabitacion(dt);
    instancia->liberarDTHabitacion();
}

void ControladorHostal::vincularEmpleadoHostal(Empleado *empleado, string nombreHostal)
{
    map<string, Hostal *>::iterator it;
    it = instancia->colHostales.find(nombreHostal);
    Hostal *hostal = it->second;
    
    empleado->setHostal(hostal);
}

map<int, DTHabitacion *> ControladorHostal::obtenerHabDisponibles(string nombreHostal, date in, date out)
{
    map<string, Hostal *>::iterator it = instancia->colHostales.find(nombreHostal);
    Hostal *h = it->second;
    map<int, DTHabitacion *> res = h->obtenerHabDisponibles(in, out);
    return res;
}

void ControladorHostal::vincularReservaHabitacion(Reserva *res, string nombreHostal, int numeroHabitacion)
{
    map<string, Hostal *>::iterator it = instancia->colHostales.find(nombreHostal);
    it->second->vincularReservaHabitacion(res, numeroHabitacion);
}

static bool mejorCalificado(pair<string, Hostal *> &uno, pair<string, Hostal *> &dos)
{
    float promedioUno = uno.second->calcularPromedio();
    float promedioDos = dos.second->calcularPromedio();
    return promedioUno > promedioDos;
}

DTHostal **ControladorHostal::obtenerTop3()
{
    vector<pair<string, Hostal *>> v(instancia->colHostales.begin(), instancia->colHostales.end()); //? esto no hay que borrarlo de alguna forma antes del return?
    sort(v.begin(), v.end(), mejorCalificado);
    DTHostal **res = new DTHostal *[3];
    for (int i = 0; i < 3; i++)
    {
        res[i] = NULL;
    }

    vector<pair<string, Hostal *>>::iterator it = v.begin();
    for (int i = 0; i <= 2 && it != v.end(); i++)
    {
        res[i] = it->second->getDTHostal();
        ++it;
    }
    return res;
}

set<DTCalificacion *> ControladorHostal::obtenerCalificacionesHostal(string nombreHostal)
{
    map<string, Hostal *>::iterator it = instancia->colHostales.find(nombreHostal);
    return it->second->obtenerCalificaciones();
}

map<int, DTReserva *> ControladorHostal::obtenerReservasNoCanceladas(string nombreHostal, string emailHuesped)
{
    map<string, Hostal *>::iterator it;
    it = instancia->colHostales.find(nombreHostal);
    return it->second->obtenerReservasNoCanceladas(emailHuesped);
}

void ControladorHostal::finalizarEstadia(string emailHuesped, string nombreHostal)
{
    map<string, Hostal *>::iterator it1 = instancia->colHostales.find(nombreHostal);
    Hostal *hostal = it1->second;
    hostal->finalizarEst(emailHuesped);
}

set<DTEstadia *> ControladorHostal::obtenerEstadiasFinalizadas(string emailHuesped, string nombreHostal)
{
    map<string, Hostal *>::iterator it = colHostales.find(nombreHostal);
    return it->second->obtenerEstadiasFinalizadas(emailHuesped);
}

void ControladorHostal::vincularYNotificarCalificacion(Calificacion *calif, string nombreHostal, string emailHuesped)
{
    map<string, Hostal *>::iterator it;
    it = colHostales.find(nombreHostal);
    Hostal *hostal = it->second;
    hostal->agregarCaliFHostal(calif, emailHuesped);
}

DTHostalExtendido *ControladorHostal::infoHostal(string nombreHostal)
{
    map<string, Hostal *>::iterator it;
    it = colHostales.find(nombreHostal);
    return it->second->infoHostal();
}

map<int, DTReserva *> ControladorHostal::obtenerReservas(string nombreHostal)
{
    map<string, Hostal *>::iterator it = instancia->colHostales.find(nombreHostal);
    return it->second->obtenerReservas();
}

set<DTEstadia *> ControladorHostal::obtenerEstadias(string nombreHostal)
{
    map<string, Hostal *>::iterator it;
    it = instancia->colHostales.find(nombreHostal);
    instancia->colDTEstadia = it->second->obtenerEstadias();
    return instancia->colDTEstadia;
}

DTReserva *ControladorHostal::mostrarReserva(string nombreHostal, int codigoReserva)
{
    map<string, Hostal *>::iterator it;
    it = colHostales.find(nombreHostal);
    map<int, DTReserva *> reservas = it->second->obtenerReservas(); //! hay que hacer delete 1
    map<int, DTReserva *>::iterator it2;
    it2 = reservas.begin();
    bool encontrado = 0;
    DTReserva *actual;
    DTReserva *actual2 = NULL;
    while (it2 != reservas.end() && !encontrado)
    {
        actual = it2->second;
        if (actual->getCodigo() == codigoReserva)
        {
            encontrado = 1;
            actual2 = new DTReserva(actual->getCodigo(), actual->getCheckIn(), actual->getCheckOut(), actual->getEstado(), actual->getNumHabitacion(), actual->getCosto(), actual->getEmailsHuespedes());
        }
        it2++;
    }

    for (map<int, DTReserva *>::iterator it3 = reservas.begin(); it3 != reservas.end(); ++it3)
    {
        delete it3->second; //! delete 1
    }
    reservas.clear();

    return actual2;
}

DTEstadia *ControladorHostal::mostrarEstadia(string emailHuesped, int codigoReserva)
{
    set<DTEstadia *>::iterator it = colDTEstadia.begin();
    bool encontrado = 0;
    DTEstadia *actual = NULL;
    while (it != colDTEstadia.end() && !encontrado)
    {
        actual = *it;
        if (actual->getHuesped() == emailHuesped && actual->getReserva() == codigoReserva)
            encontrado = 1;
        it++;
    }
    return actual;
}

void ControladorHostal::desvincularReservaHabitacion(string nombreHostal, Reserva *res)
{
    map<string, Hostal *>::iterator it = instancia->colHostales.find(nombreHostal);
    it->second->desvincularReservaHabitacion(res);
}

void ControladorHostal::mostrarHostales()
{
    map<string, DTHostal *> hostales = instancia->obtenerHostales();
    for (map<string, DTHostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
    {
        string nomHostal = it->first;
        DTHostal *hostal = it->second;
        cout << hostal->getNombre() << endl;
    }
}