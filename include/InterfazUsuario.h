#ifndef _INTERFAZUSUARIO_H
#define _INTERFAZUSUARIO_H

#include "date.h"
#include "DTUsuario.h"
#include "DTHuesped.h"
#include "DTCalificacion.h"
#include "DTEmpleado.h"
#include "Notificacion.h"
#include <map>
#include <string>
#include <set>
using namespace std;

class InterfazUsuario
{
public:
    virtual bool ingresarPersona(DTUsuario*) = 0;
    virtual map<string, DTEmpleado*> obtenerEmpleados() = 0;
    virtual void ingresarEmpleado(string, string) = 0;
    virtual void cancelarAlta() = 0;
    virtual void confirmarAlta() = 0;
    virtual void confirmarAsignacion() = 0;
    virtual void cancelarAsignacion() = 0;
    virtual map<string, DTHuesped*> obtenerHuespedes() = 0;
    virtual set<DTCalificacion*> obtenerComentariosSinResponder(string) = 0;
    virtual map<string, DTUsuario*> obtenerUsuarios() = 0;
    virtual DTUsuario* infoUsuario(string) = 0;
    virtual void suscribirse(string) = 0;
    virtual set<Notificacion*> obtenerNotificaciones(string) = 0;
    virtual void eliminarNotificaciones(string) = 0;
    virtual void eliminarSuscripcion(string) = 0;
    virtual ~InterfazUsuario()
    {

    }  
};

#endif