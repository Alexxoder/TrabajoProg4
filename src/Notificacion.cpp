#include "../include/Notificacion.h"

//creates
Notificacion::Notificacion()
{
    this->Nota = 0;
    this->comentario = '0';
    this->emailHuesped ='0';
}

Notificacion::Notificacion(string emailHuesped, int nota, string comentario)
{
    this->emailHuesped = emailHuesped;
    this->Nota = nota;
    this->comentario = comentario;
}

//setters
void Notificacion::setHuesped(string emailHuesped)
{
    this->emailHuesped = emailHuesped;
}

void Notificacion::setNota(int nota)
{
    this->Nota  = nota;
}

void Notificacion::setComentario(string comentario)
{
    this->comentario = comentario;
}

//getters
string Notificacion::getComentario()
{
    return this->comentario;
}

string Notificacion::getHuesped()
{
    return this->emailHuesped;
}

int Notificacion::getNota()
{
    return this->Nota;
}

ostream &operator<<(ostream &o, Notificacion &n)
{
    o << "Mail del Huesped: " << n.getHuesped() << endl;
    o << "Nota: " << n.getNota() << endl;
    o << "Comentario: ";
    if (n.getComentario() == "")
        o << "No hay." << endl;
    else
        o << n.getComentario() << endl;

    return o;
}