#ifndef _EMPLEADO_H
#define _EMPLEADO_H

#include "Usuario.h"
#include "Suscrito.h"
#include "TipoCargo.h"
#include "Hostal.h"
#include "Notificacion.h"
#include "DTEmpleado.h"

class Empleado: public Usuario, public Suscrito
{
private:
    TipoCargo cargo;
    Hostal *hostal;
    set<Notificacion*> colNotificaciones;
public:
    Empleado();
    Empleado(string nombre,string email,string contrasenia, TipoCargo cargo);
    ~Empleado();
    //setters
    void setCargo(TipoCargo); 
    void setHostal(Hostal*);
    //getters
    Hostal* getHostal();
    TipoCargo getCargo();
    set<Notificacion*> getNotificaciones();
    //operaciones
    virtual bool esEmpleado();
    virtual void notificar(int nota, string comentario, string emailHuesped);
    set <DTCalificacion*> obtenerComentariosSinResponder();
    void suscribirse();
    void eliminarNotificaciones();
    void desuscribir();

    virtual DTUsuario* obtenerDTUsuario();
};

#endif
