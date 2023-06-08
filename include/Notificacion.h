#ifndef _NOTIFICACION_H
#define _NOTIFICACION_H

#include <string>
#include <iostream>
using namespace std;
class Notificacion
{
private:
    string emailHuesped;
    int Nota;
    string comentario;
public:
    //creates
    Notificacion();
    Notificacion(string,int,string);

    //setters
    void setHuesped(string emailHuesped);
    void setNota(int nota);
    void setComentario(string comentario);

    //getters
    string getHuesped();
    int getNota();
    string getComentario();
};

ostream &operator<<(ostream &o, Notificacion &n);

#endif