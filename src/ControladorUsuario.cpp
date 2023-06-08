#include "../include/ControladorUsuario.h"
#include "../include/ControladorHostal.h"

ControladorUsuario *ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario()
{
}

ControladorUsuario::~ControladorUsuario()
{
    for (map<string, Usuario *>::iterator it = colUsuarios.begin(); it != colUsuarios.end(); ++it)
        delete it->second;
    colUsuarios.clear();
}

ControladorUsuario *ControladorUsuario::getInstancia()
{
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}

map<string, Usuario *> ControladorUsuario::getColUsuarios()
{
    return instancia->colUsuarios;
}

bool ControladorUsuario::ingresarPersona(DTUsuario *usuario)
{
    map<string, Usuario *>::iterator it;

    // si el huesped ya existe retorno true
    it = colUsuarios.find(usuario->getEmail()); // tengo el iterador al huesped.
    if (it == colUsuarios.end())                // si no encuentra el email, it va a apuntar al final del map. usuario no registrado
    {
        // como no existe el usuario, lo guardo en memoria y devuelvo false
        this->datosUsuario = usuario;
        return false;
    }
    else
    {
        return true;
    }
}

void ControladorUsuario::ingresarEmpleado(string nombreHostal, string emailEmpleado)
{
    instancia->setEmailEmpleado(emailEmpleado);
    instancia->setNombreHostal(nombreHostal);
}

void ControladorUsuario::cancelarAlta() // no esta eliminando memoria con delete, de eso debe encargarse el que pasa por parametro en ingresarPersona()
{
    this->datosUsuario = this->datosHuesped = NULL;
    this->datosEmpleado = NULL;
}

void ControladorUsuario::confirmarAlta()
{

    DTHuesped *dthuesped = dynamic_cast<DTHuesped *>(this->datosUsuario);
    if (dthuesped != NULL) // creo un huesped y lo aÃ±ado a la coleccion de Usuarios del controlador y libero la info del controlador sin delete
    {
        Huesped *hues = new Huesped(dthuesped->getNombre(), dthuesped->getEmail(), dthuesped->getContrasenia(), dthuesped->esFinger()); // no se si esta bien la sintaxis
        string email = hues->getEmail();
        this->colUsuarios[email] = hues;
        this->datosUsuario = NULL;
    }
    else // igual que el otro pero con empleado
    {
        DTEmpleado *dtempleado = dynamic_cast<DTEmpleado *>(this->datosUsuario);
        Empleado *emp = new Empleado(dtempleado->getNombre(), dtempleado->getEmail(), dtempleado->getContrasenia(), dtempleado->getCargo()); // no se si esta bien la sintaxis
        string email = emp->getEmail();
        this->colUsuarios[email] = emp;
        this->datosUsuario = NULL;
    }
}

void ControladorUsuario::confirmarAsignacion()
{
    string nombre = instancia->getNombreHostal();
    string emailEmpleado = instancia->getEmailEmpleado();
    map<string, Usuario *>::iterator it;
    it = instancia->colUsuarios.find(emailEmpleado);
    Usuario *user = it->second;
    ControladorHostal *c = ControladorHostal::getInstancia();
    Empleado *emp = dynamic_cast<Empleado *>(user);
    c->vincularEmpleadoHostal(emp, nombre);
}

void ControladorUsuario::cancelarAsignacion()
{
    instancia->emailEmpleado = '0';
    instancia->nombreHostal = '0';
}

map<string, DTHuesped *> ControladorUsuario::obtenerHuespedes()
{
    map<string, DTHuesped *> res;
    for (map<string, Usuario *>::iterator it = instancia->colUsuarios.begin(); it != instancia->colUsuarios.end(); ++it)
        if (!it->second->esEmpleado())
        {
            DTUsuario *huesped = it->second->obtenerDTUsuario();
            DTHuesped *dt = dynamic_cast<DTHuesped *>(huesped);
            res[it->first] = dt;
        }
    return res;
}

set<DTCalificacion *> ControladorUsuario::obtenerComentariosSinResponder(string emailEmpleado)
{
    map<string, Usuario *>::iterator it;
    it = instancia->colUsuarios.find(emailEmpleado);
    Empleado *emp = dynamic_cast<Empleado *>(it->second);
    return emp->obtenerComentariosSinResponder();
}

map<string, DTUsuario *> ControladorUsuario::obtenerUsuarios()
{
    map<string, DTUsuario *> res;
    for (map<string, Usuario *>::iterator it = instancia->colUsuarios.begin(); it != instancia->colUsuarios.end(); ++it)
    {
        Usuario *u = it->second;
        DTUsuario *dtu = u->obtenerDTUsuario();
        res[dtu->getEmail()] = dtu;
    }
    return res;
}

DTUsuario *ControladorUsuario::infoUsuario(string emailHuesped)
{
    map<string, DTUsuario *> col = instancia->obtenerUsuarios();
    DTUsuario *res = col.find(emailHuesped)->second;
    for (map<string, DTUsuario *>::iterator it = col.begin(); it != col.end(); ++it)
    {
        if (it->second != res)
            delete it->second;
    }
    col.clear();
    return res;
}

map<string, DTEmpleado *> ControladorUsuario::obtenerEmpleados()
{
    map<string, DTEmpleado *> DTEmpleados;
    map<string, Usuario *> col = instancia->colUsuarios;
    map<string, Usuario *>::iterator it;
    for (it = col.begin(); it != col.end(); it++)
    {
        string clave = it->first;
        Usuario *user = it->second;
        if (user->esEmpleado())
        {
            Empleado *emp = dynamic_cast<Empleado *>(user);
            DTEmpleado *dtEmp = new DTEmpleado(emp->getNombre(), clave, emp->getContrasenia(), emp->getCargo());
            DTEmpleados[clave] = dtEmp;
        }
    }
    return DTEmpleados;
}

void ControladorUsuario::suscribirse(string emailEmpleado)
{
    // se chequea en el main, el email de empleado
    map<string, Usuario *>::iterator it = colUsuarios.find(emailEmpleado);
    Empleado *empleado = dynamic_cast<Empleado *>(it->second);
    empleado->suscribirse();
}

set<Notificacion *> ControladorUsuario::obtenerNotificaciones(string emailEmpleado)
{
    map<string, Usuario *>::iterator it;
    it = colUsuarios.find(emailEmpleado);
    // nunca sera null ya que siempre le paso un email de empleado valido cargado desde el main
    Empleado *emp = dynamic_cast<Empleado *>(it->second);
    return emp->getNotificaciones();
}

void ControladorUsuario::eliminarNotificaciones(string emailEmpleado)
{
    map<string, Usuario *>::iterator it;
    it = colUsuarios.find(emailEmpleado);
    Empleado *emp = dynamic_cast<Empleado *>(it->second);
    emp->eliminarNotificaciones();
}

void ControladorUsuario::eliminarSuscripcion(string emailEmpleado)
{
    map<string, Usuario *>::iterator it;
    it = colUsuarios.find(emailEmpleado);
    Empleado *emp = dynamic_cast<Empleado *>(it->second);
    emp->eliminarNotificaciones();
    emp->desuscribir();
}

DTUsuario *ControladorUsuario::getDTUsuario()
{
    return NULL;
}

void ControladorUsuario::setNombreHostal(string nombreHostal)
{
    instancia->nombreHostal = nombreHostal;
}

void ControladorUsuario::setEmailEmpleado(string emailEmpleado)
{
    instancia->emailEmpleado = emailEmpleado;
}

string ControladorUsuario::getNombreHostal()
{
    return instancia->nombreHostal;
}

string ControladorUsuario::getEmailEmpleado()
{
    return instancia->emailEmpleado;
}