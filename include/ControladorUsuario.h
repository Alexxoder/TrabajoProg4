#ifndef _CONTROLADORUSUARIO_H
#define _CONTROLADORUSUARIO_H

#include "InterfazUsuario.h"
#include "DTHuesped.h"
#include "Huesped.h"
using namespace std;

class ControladorUsuario : public InterfazUsuario
{
private:
    static ControladorUsuario *instancia;
    ControladorUsuario();

    map<string, Usuario *> colUsuarios;

    string nombreHostal;
    string emailEmpleado;
    DTHuesped *datosHuesped;
    DTUsuario *datosUsuario;
    DTEmpleado *datosEmpleado;

public:
    // creates
    static ControladorUsuario *getInstancia();
    ~ControladorUsuario();

    // getters
    string getNombreHostal();
    string getEmailEmpleado();
    DTUsuario *getDTUsuario();
    map<string, Usuario*> getColUsuarios();

    // setters
    void setDTEmpleado(Usuario *);
    void setNombreHostal(string);
    void setEmailEmpleado(string);
    void setDTHuesped(Usuario *);
    void setDTUsuario(Usuario *);

    // opts del DC
    virtual bool ingresarPersona(DTUsuario *usuario);
    virtual map<string, DTEmpleado*> obtenerEmpleados();
    virtual void ingresarEmpleado(string, string);
    virtual void cancelarAlta();
    virtual void confirmarAlta();
    virtual void confirmarAsignacion();
    virtual void cancelarAsignacion();
    virtual map<string, DTHuesped*> obtenerHuespedes();
    virtual set<DTCalificacion*> obtenerComentariosSinResponder(string); //! esto devuelve 1 sola calificacion o devuelve 1 conjunto?
    virtual map<string, DTUsuario *> obtenerUsuarios();
    virtual DTUsuario *infoUsuario(string);
    DTUsuario *retornarUsuario(string);
    // virtual set<DTUsuario*> obtenerEmpleados(); aparece 2 veces linea 40 y 51 -> esta implementada la de la linea 40 y en el cpp esta no aparece
    virtual void suscribirse(string emailEmpleado);
    virtual set<Notificacion *> obtenerNotificaciones(string emailEmpleado);
    virtual void eliminarNotificaciones(string emailEmpleado);
    virtual void eliminarSuscripcion(string emailEmpleado);
    void guardarDTUsuario(DTUsuario *);
    void mostrarUsuarios();
};

#endif

